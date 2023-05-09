#include "RoboCatShared.hpp"

#include "SFML\Graphics.hpp"

#include "InputManager.hpp"
#include "SpriteComponent.hpp"
#include "PlayerSpriteComponent.hpp"
#include "TextureManager.hpp"
#include "FontManager.hpp"
#include "RenderManager.hpp"
#include "WindowManager.hpp"

#include "RoboCatClient.hpp"
#include "MouseClient.hpp"
#include "YarnClient.hpp"

#include "HUD.hpp"

#include "ReplicationManagerClient.hpp"
#include "NetworkManagerClient.hpp"
#include "Client.hpp"

#include "SettingsState.hpp"
#include "MenuState.hpp"
#include "LobbyState.hpp"
#include "StateID.hpp"
#include "StateStack.hpp"
#include "State.hpp"
#include "StackManager.hpp"
#include "TitleState.hpp"
//#include "Client.hpp"