#include "Scene.h"

Title::Title(const InitData& init)
    : IScene(init)
{
}

void Title::update()
{
	if (KeySpace.down())	//Space����������
	{
		// �Q�[���V�[���ɑJ��
		changeScene(U"Game");
	}
}

void Title::draw() const
{
	FontAsset(U"MainFont")(U"�V���[�e�B���O�Q�[��").drawAt(400, 300);
	FontAsset(U"SubFont")(U"�X�y�[�X�L�[�ŊJ�n").drawAt(400, 350);
}

Game::Game(const InitData& init)
    : IScene(init)
{
    
}

void Game::update()
{
	player.move();	//�v���C���[�̈ړ�
	player.shot();	//�v���C���[�̒e��������
	player.show();	//�v���C���[�̕\��
	player.checkIntersect(enemy.getEnemyRect());
	enemy.move();	//�G�̈ړ�
	enemy.shot(player.getPlayerRect(), enemy.getEnemySize());	//�G�̒e�𔭎�
	enemy.show();	//�G�̕\��
	getData().score = player.getScore();
	if (enemy.checkIntersect(player.getPlayerRect())) {
		changeScene(U"Ending");
	}
}

void Game::draw() const 
{
	FontAsset(U"SubFont")(U"Score: {}"_fmt(getData().score)).draw(0, 0);
	FontAsset(U"SubFont")(U"HIghScore: {}"_fmt(getData().highScore)).draw(0, 20);
}

Ending::Ending(const InitData& init)
    : IScene(init), highScore(0)
{
}

void Ending::update()
{
	highScore = getData().highScore;	//highScore���擾
	if (getData().score > highScore) {	//score�̕����������
		highScore = getData().score;	//highScore���X�V
		getData().highScore = highScore;	
	}
	if (KeySpace.down())	//Space����������
	{
		// �Q�[���I�[�o�[�V�[���ɑJ��
		changeScene(U"Game");
	}
}

void Ending::draw() const
{
	FontAsset(U"MainFont")(U"�Q�[���I�[�o�[").drawAt(400, 200);
	FontAsset(U"SubFont")(U"�X�y�[�X�L�[��Retry").drawAt(400, 250);
	FontAsset(U"SubFont")(U"Esc�ŏI��").drawAt(400, 300);
	FontAsset(U"SubFont")(U"�����Score: {}"_fmt(getData().score)).drawAt(400, 350);
	FontAsset(U"SubFont")(U"HIghScore: {}"_fmt(highScore)).drawAt(400, 400);
}
