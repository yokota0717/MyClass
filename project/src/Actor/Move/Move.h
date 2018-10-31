/**
* @file Move.h
* @brief ふるまいクラス、動くオブジェクトに持たせる
* @author yokota0717
* @param history
- 2018.10.31 yokota0717
-# 仮引数をconstにした
-# 重力の追加
*/
#pragma once
#include "../../System/Math/Math.h"

class MoveBase
{
protected:
	//! 現在座標
	Math::Vec pos_;
	//! 移動速度
	float speed_;
	//! 重力を適用するか
	bool isGravity_;
	//! 重力加速度
	const float gravity_;
public:
	explicit MoveBase(const Math::Vec& pos, const float speed, const bool gravity);
	virtual ~MoveBase();
	virtual void move() = 0;

	Math::Vec& getPos();
};

class PlayerMove : public MoveBase {
public:
	PlayerMove(const Math::Vec& pos, const float speed, const bool gravity);
	virtual void move();
};