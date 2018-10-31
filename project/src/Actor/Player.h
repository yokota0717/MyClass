/**
* @file		Player.h
* @brief	プレイヤクラス
*/

#pragma once
#include "../System/Node/Node.h"
#include "../System/Image/Image.h"
#include "Move/Move.h"


class Player : public Node
{
	Image image_;
	MoveBase* move_;
public:
	Player(const std::string& path, MoveBase* move);
	~Player();

	void init() override;
	void update() override;
	void render() override;
	void fin();
};