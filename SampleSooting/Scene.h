#pragma once
#include <Siv3D.hpp>
#include "Player.h"
#include "Enemy.h"

struct GameData
{
    int32 score = 0;
    int32 highScore = 0;
};

using App = SceneManager<String, GameData>;

class Title : public App::Scene
{
public:

    // �R���X�g���N�^�i�K�������j
    Title(const InitData& init);

    // �X�V�֐�
    void update() override;

    // �`��֐� (const �C��)
    void draw() const override;
};

class Game : public App::Scene
{
private:
    Player player;
    Enemy enemy;
public:
    // �R���X�g���N�^�i�K�������j
    Game(const InitData& init);

    // �X�V�֐�
    void update() override;

    // �`��֐� (const �C��)
    void draw() const override;
};

class Ending : public App::Scene 
{
private:
    int32 highScore;
public:
    Ending(const InitData& init);

    // �X�V�֐�
    void update() override;

    // �`��֐� (const �C��)
    void draw() const override;
};