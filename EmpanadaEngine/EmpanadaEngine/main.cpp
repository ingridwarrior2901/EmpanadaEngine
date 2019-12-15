//
//  main.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/18/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//


#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup /NODEFAULTLIB:MSVCRT")
#endif

#include <iostream>
#include <sstream>
#include "Core/Audio/IEMPAudio.h"
#include "Core/Game/EMPGameApp.h"
#include "Core/ECS/Components/EMPTransformComponent.h"
#include "Core/ECS/Entities/EMPModel.h"
#include "Core/ECS/Entities/EMPSprite.h"
#include "Core/Events/EMPEventManager.h"
#include "Core/Events/EMPMouseEvent.h"
#include "Core/GUI/EMPButton.h"
#include "Core/GUI/EMPText.h"
#include "Core/Render/IEMPBuffer.h"
#include "Core/Scenes/IEMPScene.h"
#include "Core/Windows/EMPWindowManager.h"

// MARK: - Constants

namespace Constants
{
    namespace Font
    {
        const std::string name = "Resources/ARCADECLASSIC.TTF";
        const float fontScale = 0.5f;
    }

    namespace Player
    {
        const std::string name = "empanadaGirl";
        const glm::vec2 size = glm::vec2(64.0f);
        const glm::vec2 startPosition = glm::vec2(30.0f, 350.0f);
        const std::string spriteImagePath = "Resources/spritesheet.png";
        const std::string animationForward = "walkForward";
        const float gravitySpeed = 500.0f;
        const int frameHorizontal = 9;
        const int frameVertical = 1;
        const float winPosition = 1100.0f;
    }

    namespace Enemy
    {
        const std::string name = "skeleton";
        const glm::vec2 size = glm::vec2(64.0f);
        const std::vector<glm::vec2> startPositions = { glm::vec2(70.0f, 349.0f), glm::vec2(170.0f, 349.0f), glm::vec2(270.0f, 349.0f) };
        const std::string spriteImagePath = "Resources/enemy.png";
        const std::string animationForward = "walkForward";
        const std::string animationBackward = "walkBackward";
        const std::string animationBackwardImage = "Resources/enemyBackwards.png";
        const int fps = 8;
        const int frameHorizontal = 9;
        const int frameVertical = 1;
    }

    namespace EmpanadaIcon
    {
        const std::string name = "icon";
        const glm::vec2 size = glm::vec2(20.0f, 41.0f);
        const glm::vec2 startPosition = glm::vec2(30.0f, 52.0f);
        const std::string spriteImagePath = "Resources/empanada.png";
    }

    namespace Text
    {
        const std::string scoreInitialText = "0";
        const std::string gameTitle = "Empanada Game";
        const std::string gameover = "Game Over";
        const std::string winText = "You Win!";
        const glm::vec3 textColor = glm::vec3(1.0f);
        const glm::vec2 scorePosition = glm::vec2(60.0f, 500.0f);
        const glm::vec2 titlePosition = glm::vec2(320.0f, 500.0f);
        const glm::vec2 gamePosition = glm::vec2(340.0f, 500.0f);
    }
    
    namespace Floor
    {
        const std::string name = "floor-grass";
        const glm::vec2 size = glm::vec2(70.0f);
        const float positionY = 380.0f;
        const float offsetX = 35.0f;
        const std::string spriteImagePath = "Resources/grass.png";
        const int numberOfFloors = 20;
    }

    namespace Button
    {
        const std::string name = "floor-grass";
        const glm::vec2 size = glm::vec2(180.0f, 50.0f);
        const glm::vec2 startPosition = glm::vec2(550.0f, 300.0f);
        const std::string spriteImagePath = "Resources/startButton.png";
    }

    namespace EmpanadaCoin
    {
        const std::string name = "coin";
        const glm::vec2 size = glm::vec2(10.0f, 21.0f);
        const std::vector<glm::vec2> startPositions = { glm::vec2(60.0f, 350.0f), glm::vec2(90.0f, 350.0f),
                                                        glm::vec2(120.0f, 350.0f), glm::vec2(150.0f, 350.0f),
                                                        glm::vec2(251.0f, 350.0f), glm::vec2(281.0f, 350.0f),
                                                        glm::vec2(371.0f, 350.0f), glm::vec2(401.0f, 350.0f),
                                                        glm::vec2(431.0f, 350.0f), glm::vec2(461.0f, 350.0f)
        };
        const std::string spriteImagePath = "Resources/empanada.png";
    }

    namespace Game
    {
        const glm::vec2 windowSize = glm::vec2(1280, 800);
        const glm::vec4 backgroundColor = glm::vec4(0.36, 0.49, 0.62, 1.0f);
    }

    namespace Music
    {
        const std::string musicPath = "Resources/song2.wav";
    }
}

struct EnemyPatrol
{
    EmpanadaEngine::EMPSpritePTR enemy;
    bool forward;
    float patrolPositionX;
};
    
    // MARK: - Scene

class DemoScene: public EmpanadaEngine::IEMPScene
{
public:
    
    // MARK: - Constructor
    
    DemoScene() : IEMPScene("Example") { }
    ~DemoScene() { }
    
    // MARK: - Lifecycle
    
    void Start() override
    {
        std::cout << "Start scene"<< std::endl;
    }
    
    void Attach() override
    {
        auto &application = EmpanadaEngine::EMPGameApp::GetInstance();
        application.GetFontManager()->LoadFont(Constants::Font::name);
        
		#ifdef __APPLE__
		//TODO: There's is a bug when the app is trying to load the music in Windows Platform.
		SetupMusic();
		#endif
        SetupTexts();
        
        m_empanadaIcon = CreateSprite(Constants::EmpanadaIcon::name,
                                      Constants::EmpanadaIcon::spriteImagePath,
                                      Constants::EmpanadaIcon::startPosition,
                                      Constants::EmpanadaIcon::size);

        m_startButton = EmpanadaEngine::NewRef<EmpanadaEngine::EMPButton>(GetDefaultShader(),
                                                                          Constants::Button::spriteImagePath,
                                                                          Constants::Button::startPosition,
                                                                          Constants::Button::size,
                                                                          EMPBindFunction(DemoScene::OnButtonPressed));
        AddEntity(m_startButton);
        m_enableCollision = true;
    }
    
    void Update(float deltaTime) override
    {
        IEMPScene::Update(deltaTime);

        if (!m_startGame) { return; }
        
        if (m_sprite->GetPosition().y >= Constants::Player::startPosition.y - 10.0f)
        {
            m_delayCollision = false;
            m_addGravity = false;
            m_canPlayerJump = true;
        }
        
        if (m_addGravity)
        {
            m_gravitySpeed += Constants::Player::gravitySpeed * deltaTime;
        }
        
        auto &application = EmpanadaEngine::EMPGameApp::GetInstance();
        
        if (application.GetInputManager()->GetInputInterface()->IsKeyPressed(GLFW_KEY_D))
        {
            float speed = !m_addGravity ? m_speed : m_speed * 2;
            MoveSpriteHorizontal(m_sprite, (speed * deltaTime));
            
            if (!m_addGravity)
            {
                m_sprite->GetAnimationComponent()->PlayAnimation();
            }
        }
        else
        {
            m_sprite->GetAnimationComponent()->StopAnimation();
        }
        
        if (application.GetInputManager()->GetInputInterface()->IsKeyPressed(GLFW_KEY_W) && m_canPlayerJump && !m_addGravity)
        {
            m_delayCollision = true;
            m_canPlayerJump = false;
            m_addGravity = true;
            m_gravitySpeed = -Constants::Player::gravitySpeed;
        }
        
        if (m_addGravity)
        {
            MoveSpriteVertical(m_sprite, (m_gravitySpeed * deltaTime));
        }
        
        EnemyPatrolMovement(deltaTime);
        
        
        for (EmpanadaEngine::IEMPEntityPTR coin : m_coinToRemoveList)
        {
            RemoveEntity(coin);
        }
        
        if (m_sprite->GetPosition().x > Constants::Player::winPosition)
        {
            ReloadLevel(Constants::Text::winText);
        }
    }
    
    // MARK: - Collisions
    
    void Collide(EmpanadaEngine::IEMPEntityPTR firstEntityObject, EmpanadaEngine::IEMPEntityPTR secondEntityObject) override
    {
        if (firstEntityObject->GetName().find(Constants::Floor::name) != std::string::npos &&
            secondEntityObject->GetName().find(Constants::Player::name) != std::string::npos && !m_delayCollision)
        {
            m_canPlayerJump = true;
            m_addGravity = false;
            m_gravitySpeed = 0;
        }
        
        if ((firstEntityObject->GetName().find(Constants::Player::name) != std::string::npos &&
             secondEntityObject->GetName().find(Constants::Enemy::name) != std::string::npos) ||
            (firstEntityObject->GetName().find(Constants::Enemy::name) != std::string::npos &&
             secondEntityObject->GetName().find(Constants::Player::name) != std::string::npos))
        {
            ReloadLevel(Constants::Text::gameover);
        }
        
        
        if ((firstEntityObject->GetName().find(Constants::Player::name) != std::string::npos &&
             secondEntityObject->GetName().find(Constants::EmpanadaCoin::name) != std::string::npos) ||
            (firstEntityObject->GetName().find(Constants::EmpanadaCoin::name) != std::string::npos &&
             secondEntityObject->GetName().find(Constants::Player::name) != std::string::npos))
        {
            m_scoreValue += 1;
            m_score->SetText(std::to_string(m_scoreValue));
            m_coinToRemoveList.push_back(firstEntityObject);
        }
        
    }
    
    // MARK: - Buttons Action
    void OnButtonPressed()
    {        
        if (m_startGame) { return; }
        
        SetupSprites();
        
        m_startGame = true;
        m_text->SetText(Constants::Text::gameTitle);
        m_text->SetPosition(Constants::Text::titlePosition);
        RemoveEntity(m_startButton);
    }
    
    // MARK: - Setups
    
    void SetupMusic()
    {
        m_music = EmpanadaEngine::IEMPAudio::Load(Constants::Music::musicPath);
        m_music->SetLooping(true);
        m_music->PlaySound();
    }
    
    void SetupTexts()
    {
        m_score = CreateText(Constants::Text::scoreInitialText,
                             Constants::Text::scorePosition,
                             Constants::Font::fontScale,
                             Constants::Text::textColor);
        
        m_text = CreateText(Constants::Text::gameTitle,
                            Constants::Text::titlePosition,
                            Constants::Font::fontScale,
                            Constants::Text::textColor);
    }
    
    void SetupSprites()
    {
        m_sprite = CreateSprite(Constants::Player::name,
                                Constants::Player::spriteImagePath,
                                Constants::Player::startPosition,
                                Constants::Player::size);
        
        m_sprite->AddAnimation(Constants::Player::animationForward,
                               Constants::Player::frameHorizontal,
                               Constants::Player::frameVertical);
        
        m_sprite->GetAnimationComponent()->SetLooping(true);
        
        
        for (int i = 0; i < Constants::Enemy::startPositions.size(); i ++)
        {
            EmpanadaEngine::EMPSpritePTR enemy = CreateSprite(Constants::Enemy::name,
                                                              Constants::Enemy::spriteImagePath,
                                                              Constants::Enemy::startPositions[i],
                                                              Constants::Enemy::size);
            
            enemy->AddAnimation(Constants::Enemy::animationForward,
                                Constants::Enemy::frameHorizontal,
                                Constants::Enemy::frameVertical);
            
            EmpanadaEngine::IEMPTexturePTR enemyTexture = EmpanadaEngine::IEMPTexture::Load(Constants::Enemy::animationBackwardImage);
            
            enemy->AddAnimation(Constants::Enemy::animationBackward,
                                Constants::Enemy::frameHorizontal,
                                Constants::Enemy::frameVertical,
                                Constants::Enemy::fps,
                                enemyTexture);
            
            enemy->GetAnimationComponent()->SetLooping(true);
            m_enemyList.push_back({ enemy, true, Constants::Enemy::startPositions[i].x});
        }
        
        
        float floorOffsetX = 0;
        for (int i = 0; i < Constants::Floor::numberOfFloors; i ++)
        {
            std::stringstream stringFormat;
            stringFormat << Constants::Floor::name << i;
            std::string grassName = stringFormat.str();
            
            EmpanadaEngine::EMPSpritePTR floor = CreateSprite(grassName,
                                                              Constants::Floor::spriteImagePath,
                                                              glm::vec2(floorOffsetX, Constants::Floor::positionY),
                                                              Constants::Floor::size);
            floorOffsetX += Constants::Floor::offsetX;
            m_floorList.push_back(floor);
        }
        
        for (int i = 0; i < Constants::EmpanadaCoin::startPositions.size(); i++)
        {
            std::stringstream stringFormat;
            stringFormat << Constants::EmpanadaCoin::name << i;
            std::string coinName = stringFormat.str();
            EmpanadaEngine::EMPSpritePTR coin = CreateSprite(coinName,
                                                             Constants::EmpanadaCoin::spriteImagePath,
                                                             glm::vec2(Constants::EmpanadaCoin::startPositions[i]),
                                                             Constants::EmpanadaCoin::size);
            m_coinList.push_back(coin);
        }
    }
    
    // MARK: - Public Methods
    
    void ReloadLevel(std::string gameTitle)
    {
        m_scoreValue = 0;
        m_score->SetText(std::to_string(m_scoreValue));
        m_text->SetText(gameTitle);
        m_text->SetPosition(Constants::Text::gamePosition);
        
        reloadEnemies();
        reloadFloor();
        reloadCoins();
        
        RemoveEntity(m_sprite);
        AddEntity(m_startButton);
        
        m_startGame = false;
        m_gameOver = true;
    }
    
    void MoveSpriteHorizontal(EmpanadaEngine::EMPSpritePTR sprite, float speed)
    {
        glm::vec3 currentPosition = glm::vec3(sprite->GetPosition().x + speed,
                                              sprite->GetPosition().y,
                                              0.0f);
        sprite->GetTransformComponent()->SetPosition(currentPosition);
    }
    
    void MoveSpriteVertical(EmpanadaEngine::EMPSpritePTR sprite, float speed)
    {
        glm::vec3 currentPosition = glm::vec3(sprite->GetPosition().x,
                                              sprite->GetPosition().y + speed,
                                              0.0f);
        sprite->GetTransformComponent()->SetPosition(currentPosition);
    }
    
    void EnemyPatrolMovement(float deltaTime)
    {
        for (auto& patrol : m_enemyList)
        {
            if (patrol.enemy->GetPosition().x < patrol.patrolPositionX * 3 && patrol.forward)
            {
                MoveSpriteHorizontal(patrol.enemy, (m_speed * deltaTime));
                patrol.enemy->GetAnimationComponent()->PlayAnimation(Constants::Enemy::animationForward);
            }
            else if (patrol.enemy->GetPosition().x > patrol.patrolPositionX)
            {
                patrol.forward = false;
                MoveSpriteHorizontal(patrol.enemy, -(m_speed * deltaTime));
                patrol.enemy->GetAnimationComponent()->PlayAnimation(Constants::Enemy::animationBackward);
                
                if (patrol.enemy->GetPosition().x < patrol.patrolPositionX)
                {
                    patrol.forward = true;
                }
            }
        }
    }
    
    void reloadEnemies()
    {
        for (auto& patrol : m_enemyList)
        {
            patrol.forward = true;
            RemoveEntity(patrol.enemy);
        }
    }
    
    void reloadFloor()
    {
        for (EmpanadaEngine::EMPSpritePTR floor : m_floorList)
        {
            RemoveEntity(floor);
        }
    }
    
    void reloadCoins()
    {
        for (EmpanadaEngine::EMPSpritePTR coin : m_coinList)
        {
            RemoveEntity(coin);
        }
    }
    
    EmpanadaEngine::EMPSpritePTR CreateSprite(std::string name, std::string spritePath, glm::vec2 position, glm::vec2 size)
    {
        EmpanadaEngine::EMPSpritePTR sprite = EmpanadaEngine::NewRef<EmpanadaEngine::EMPSprite>(name,
                                                                                                GetDefaultShader(),
                                                                                                spritePath,
                                                                                                position,
                                                                                                size);
        
        AddEntity(sprite);
        return sprite;
    }
    
    EmpanadaEngine::EMPTextPTR CreateText(std::string text, glm::vec2 position, float scale, glm::vec3 color)
    {
        EmpanadaEngine::EMPTextPTR label = EmpanadaEngine::NewRef<EmpanadaEngine::EMPText>(text, position, scale, color);
        AddEntity(label);
        return label;
    }
    
private:
    // MARK: - Members
    EmpanadaEngine::EMPSpritePTR m_sprite;
    EmpanadaEngine::IEMPAudioPTR m_music;
    EmpanadaEngine::EMPTextPTR m_text;
    EmpanadaEngine::EMPTextPTR m_score;
    EmpanadaEngine::EMPButtonPTR m_startButton;
    EmpanadaEngine::EMPSpritePTR m_empanadaIcon;
    
    std::vector<EnemyPatrol> m_enemyList;
    std::vector<EmpanadaEngine::EMPSpritePTR> m_floorList;
    std::vector<EmpanadaEngine::EMPSpritePTR> m_coinList;
    std::vector<EmpanadaEngine::IEMPEntityPTR> m_coinToRemoveList;
    
    glm::vec3 m_cursorPosition;
    
    bool m_canPlayerJump;
    bool m_addGravity;
    bool m_delayCollision;
    bool m_startGame = false;
    bool m_gameOver;
    
    float m_speed = 40;
    float m_gravitySpeed = 0.0f;
    float m_rotationSpeed = 20;
    
    int m_scoreValue = 0;
};

    // MARK: - Application
class DemoApp: public EmpanadaEngine::EMPGameApp
{
public:
    DemoApp(EmpanadaEngine::EMPGameConfiguration& gameConfiguration, const EmpanadaEngine::EMPWindowConfiguration& windowConfiguration): EmpanadaEngine::EMPGameApp(gameConfiguration, windowConfiguration) {
        
        std::shared_ptr<DemoScene> demoScene = std::make_shared<DemoScene>();
        
        PushScene(demoScene);
    }
};
    
    // MARK: - Main

int main(int argc, const char * argv[]) {
    //Init Game
    EmpanadaEngine::EMPGameConfiguration gameConfig;
    EmpanadaEngine::EMPWindowConfiguration windowConfig(gameConfig.interfaceType);
    windowConfig.windowSize = Constants::Game::windowSize;
    windowConfig.backgroundColor = { Constants::Game::backgroundColor };
    
    DemoApp *demo = new DemoApp(gameConfig, windowConfig);
    demo->Start();
    
    return 0;
}
