#include "RoboCatClientPCH.hpp"

std::unique_ptr< TextureManager >		TextureManager::sInstance;

void TextureManager::StaticInit()
{
	sInstance.reset(new TextureManager());
}

TextureManager::TextureManager()
{
	CacheTexture("cat", "../Assets/cat.png");
	CacheTexture("mouse", "../Assets/mouse.png");
	CacheTexture("yarn", "../Assets/yarn.png");
	CacheTexture("city", "../Assets/city.png");
	CacheTexture("mainMenu", "../Assets/MainMenu.png");
	CacheTexture("mainMenu90", "../Assets/MainMenu90.png");
	CacheTexture("mainMenu80", "../Assets/MainMenu80.png");
	CacheTexture("mainMenu70", "../Assets/MainMenu70.png");
	CacheTexture("mainMenu60", "../Assets/MainMenu60.png");
	CacheTexture("mainMenu50", "../Assets/MainMenu50.png");
	CacheTexture("mainMenu40", "../Assets/MainMenu40.png");
	CacheTexture("mainMenu30", "../Assets/MainMenu30.png");
	CacheTexture("mainMenu20", "../Assets/MainMenu20.png");
	CacheTexture("mainMenu10", "../Assets/MainMenu10.png");
	CacheTexture("mainMenu00", "../Assets/MainMenu00.png");
	CacheTexture("deathScreen", "../Assets/deathScreen.png");
	CacheTexture("winScreen", "../Assets/winScreen.png");
}

TexturePtr	TextureManager::GetTexture(const string& inTextureName)
{
	return mNameToTextureMap[inTextureName];
}

bool TextureManager::CacheTexture(string inTextureName, const char* inFileName)
{
	TexturePtr newTexture(new sf::Texture());
	if (!newTexture->loadFromFile(inFileName))
	{
		return false;
	}
	mNameToTextureMap[inTextureName] = newTexture;
	return true;
}