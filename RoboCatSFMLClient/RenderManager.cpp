#include "RoboCatClientPCH.hpp"

std::unique_ptr< RenderManager >	RenderManager::sInstance;

RenderManager::RenderManager()
{
	view.reset(sf::FloatRect(0, 0, 1280, 720));
	WindowManager::sInstance->setView(view);
	m_city.setTexture(*TextureManager::sInstance->GetTexture("city"));
	m_deathScreen.setTexture(*TextureManager::sInstance->GetTexture("deathScreen"));
	m_winScreen.setTexture(*TextureManager::sInstance->GetTexture("winScreen"));
	m_mainMenu.setTexture(*TextureManager::sInstance->GetTexture("mainMenu"));
}

void RenderManager::StaticInit()
{
	sInstance.reset(new RenderManager());
}

void RenderManager::AddComponent(SpriteComponent* inComponent)
{
	mComponents.emplace_back(inComponent);
}

void RenderManager::RemoveComponent(SpriteComponent* inComponent)
{
	int index = GetComponentIndex(inComponent);

	if (index != -1)
	{
		int lastIndex = mComponents.size() - 1;
		if (index != lastIndex)
		{
			mComponents[index] = mComponents[lastIndex];
		}
		mComponents.pop_back();
	}
}

int RenderManager::GetComponentIndex(SpriteComponent* inComponent) const
{
	for (int i = 0, c = mComponents.size(); i < c; ++i)
	{
		if (mComponents[i] == inComponent)
		{
			return i;
		}
	}

	return -1;
}

//this part that renders the world is really a camera-
//in a more detailed engine, we'd have a list of cameras, and then render manager would
//render the cameras in order
void RenderManager::RenderComponents()
{
	//Get the logical viewport so we can pass this to the SpriteComponents when it's draw time
	for (SpriteComponent* c : mComponents)
	{	
		WindowManager::sInstance->draw(c->GetSprite());	
	}
}

sf::Vector2f RenderManager::FindPlayerCentrePoint()
{
	uint32_t catID = (uint32_t)'RCAT';
	for (auto obj : World::sInstance->GetGameObjects())
	{
		// Find a cat.
		if (obj->GetClassId() == catID)
		{
			RoboCat* cat = dynamic_cast<RoboCat*>(obj.get());
			auto id = cat->GetPlayerId();
			auto ourID = NetworkManagerClient::sInstance->GetPlayerId();
			if (id == ourID)
			{
				// If so grab the centre point.
				auto centre = cat->GetLocation();
				//m_lastPos.x = centre.mX;
				//m_lastPos.y = centre.mY;
				auto cen = view.getCenter();
				auto size = view.getSize();
				return sf::Vector2f(centre.mX, centre.mY);
			}
		}
	}
	return sf::Vector2f(0, 0);
}

uint8_t RenderManager::FindPlayerHealth()
{
	uint32_t playerID = (uint32_t)'RCAT';
	for (auto obj : World::sInstance->GetGameObjects())
	{
		// Find a cat.
		if (obj->GetClassId() == playerID)
		{
			RoboCat* player = dynamic_cast<RoboCat*>(obj.get());
			auto id = player->GetPlayerId();
			auto ourID = NetworkManagerClient::sInstance->GetPlayerId();
			if (id == ourID)
			{
				return player->GetHealth();
			}
		}
	}
	return 0;
}

sf::Vector2f RenderManager::AlivePlayers()
{
	int Players = 0;
	int alivePlayers = 0;
	uint32_t playerID = (uint32_t)'RCAT';
	for (auto obj : World::sInstance->GetGameObjects())
	{
		// Find a cat.
		if (obj->GetClassId() == playerID)
		{
			RoboCat* cat = dynamic_cast<RoboCat*>(obj.get());
			Players++;
			if (cat->GetHealth() > 0)
				alivePlayers++;
		}
	}
	return sf::Vector2f(alivePlayers, Players);
}

void RenderManager::Render()
{
	//
	// Clear the back buffer
	//
	//This is where background colour changes -> Try to get background image here! - Lee
	if (mComponents.size() > 0)
	{
		WindowManager::sInstance->clear(sf::Color(0, 100, 0, 0));
		WindowManager::sInstance->draw(m_city);
		RenderManager::sInstance->RenderComponents();

		HUD::sInstance->Render();

		//When player is dead display screen
		if (FindPlayerCentrePoint() == sf::Vector2f(-0, 0))
		{
			sf::Vector2f died(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
			m_deathScreen.setPosition(died);
			WindowManager::sInstance->draw(m_deathScreen);
		}
		else
		{
			//We are the last player alive.
			sf::Vector2f players = AlivePlayers();

			if (players.x == 1.f && FindPlayerHealth() > 0 &&
				ScoreBoardManager::sInstance->GetEntry(NetworkManagerClient::sInstance->GetPlayerId())->GetScore() > 30)
			{
				// Draw some you are the winner screen.
				sf::Vector2f winner(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
				m_winScreen.setPosition(winner);
				WindowManager::sInstance->draw(m_winScreen);
			}
		}
	}
	else
	{
		WindowManager::sInstance->draw(m_mainMenu);



		// <Failed> Attempt 1 at creating buttons for menu - Lee
		/*
		auto play_button = std::make_shared<GUI::Button>(context);
		play_button->setPosition(520, 350);
		play_button->SetText("Join Lobby");
		play_button->SetCallback([this]()
			{
				RequestStackPop();
				RequestStackPush(StateID::kJoinGame);
			});
			*/
	}
	//GameObjectRegistry::sInstance->CreateGameObject('CITY');
	//mSpriteComponent.reset(new SpriteComponent(this));
	//mSpriteComponent->SetTexture(TextureManager::sInstance->GetTexture("city"));
	//
	// Present our back buffer to our front buffer
	//
	WindowManager::sInstance->display();
}