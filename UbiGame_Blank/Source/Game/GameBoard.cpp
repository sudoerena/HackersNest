#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/GravityPhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/PlatformEntity.h"
#include "Game/GameComponents/PlayerMovementComponent.h"

using namespace Game;

GameBoard::GameBoard()
    : m_player(nullptr)
{
    CreatePlayer();
    CreateBackground();
    CreatePlatform(100.f, 200.f);
    CreatePlatform(200.f, 200.f);
    CreatePlatform(300.f, 250.f);
    CreatePlatform(200.f, 450.f, 800.f, 20.f);
}

void GameBoard::CreatePlayer()
{
    m_player = new PlayerEntity();

    GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
    m_player->SetPos(sf::Vector2f(60.f, 60.f));	
    m_player->SetSize(sf::Vector2f(35.f, 35.f));

    m_player->AddComponent<Game::PlayerMovementComponent>();
    m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
    m_player->AddComponent<GameEngine::GravityPhysicsComponent>();
}

void GameBoard::CreateBackground()
{
    GameEngine::Entity* bgEntity = new GameEngine::Entity();
    GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
    render->SetTexture(GameEngine::eTexture::BG);
    render->SetZLevel(0);
    bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
    bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
    GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

    m_backGround = bgEntity;
}

void GameBoard::CreatePlatform(float x, float y, float w, float h)
{
    PlatformEntity* platform = new PlatformEntity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(platform);
    platform->SetPos(sf::Vector2f(x, y));
    platform->SetSize(sf::Vector2f(w, h));

    platform->AddComponent<GameEngine::CollidableComponent>();
}

GameBoard::~GameBoard()
{
}

void GameBoard::Update()
{		
}
