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

    // コンストラクタ（必ず実装）
    Title(const InitData& init);

    // 更新関数
    void update() override;

    // 描画関数 (const 修飾)
    void draw() const override;
};

class Game : public App::Scene
{
private:
    Player player;
    Enemy enemy;
public:
    // コンストラクタ（必ず実装）
    Game(const InitData& init);

    // 更新関数
    void update() override;

    // 描画関数 (const 修飾)
    void draw() const override;
};

class Ending : public App::Scene 
{
private:
    int32 highScore;
public:
    Ending(const InitData& init);

    // 更新関数
    void update() override;

    // 描画関数 (const 修飾)
    void draw() const override;
};