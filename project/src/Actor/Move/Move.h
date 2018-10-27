/**
* @file Move.h
* @brief ふるまいクラス、動くオブジェクトに持たせる
*/
#pragma once
#include "../../System/Math/Math.h"

class Move
{
protected:
	//! 現在座標
	Math::Vec pos_;
	//! 移動速度
	float speed_;
public:
	Move(Math::Vec& pos, float speed);
	virtual ~Move();
	virtual void move() = 0;

	Math::Vec& getPos();
};

class InputMove : public Move {
public:
	InputMove(Math::Vec& pos, float speed);
	void move() override;
};