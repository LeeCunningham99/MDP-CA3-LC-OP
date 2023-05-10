#define _USE_MATH_DEFINES
#include "RoboCatShared.hpp"

#include "SFML\Graphics.hpp"

#include "InputManager.hpp"
#include "SpriteComponent.hpp"
#include "PlayerSpriteComponent.hpp"
#include "TextureManager.hpp"
#include "FontManager.hpp"
#include "RenderManager.hpp"
#include "WindowManager.hpp"
#include "ButtonType.hpp"
#include "Button.hpp"
#include "StateID.hpp"
#include "PlayerDataManager.hpp"
#include "Component.hpp"
#include "KeyBinding.hpp"
#include "RoboCatClient.hpp"
#include "MouseClient.hpp"
#include "YarnClient.hpp"

#include "HUD.hpp"

#include "State.hpp"

#include "ReplicationManagerClient.hpp"
#include "NetworkManagerClient.hpp"
#include "Client.hpp"

#include "AudioManager.hpp"

#include "Container.hpp"
#include "DrawableComponent.hpp"

#include "Label.hpp"
#include "LobbyState.hpp"
#include "MenuState.hpp"

#include "PlayerAction.hpp"

#include "SettingsState.hpp"
#include "StackManager.hpp"
#include "StateStack.hpp"
#include "TextComponent.hpp"
#include "TitleState.hpp"
#include "Utility.hpp"
