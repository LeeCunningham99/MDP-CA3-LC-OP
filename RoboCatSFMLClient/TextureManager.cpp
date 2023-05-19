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
	CacheTexture("mainMenu", "../Assets/MainMenu90.png");
	CacheTexture("mainMenu", "../Assets/MainMenu80.png");
	CacheTexture("mainMenu", "../Assets/MainMenu70.png");
	CacheTexture("mainMenu", "../Assets/MainMenu60.png");
	CacheTexture("mainMenu", "../Assets/MainMenu50.png");
	CacheTexture("mainMenu", "../Assets/MainMenu40.png");
	CacheTexture("mainMenu", "../Assets/MainMenu30.png");
	CacheTexture("mainMenu", "../Assets/MainMenu20.png");
	CacheTexture("mainMenu", "../Assets/MainMenu10.png");
	CacheTexture("mainMenu", "../Assets/MainMenu00.png");
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