/**
* @file		Player.h
* @brief	プレイヤクラス
*/

#pragma once
#include "../Object/Object.h"
#include "../Image/Image.h"
#include "Move\Move.h"


class Player : public GameObject
{
	Image image_;
	Move* move_;
public:
	Player(const std::string& path, Move* move);
	~Player();

	void init() override;
	void update() override;
	void render() override;
	void fin();
};