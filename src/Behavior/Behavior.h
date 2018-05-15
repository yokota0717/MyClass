#pragma once


//ふるまいクラスの基底クラス
class Behavior {	
public:
	virtual ~Behavior() {};
	virtual void Move() = 0;
};



//プレイヤを追いかける
class ChaseBehavior :public Behavior {		
public:
	ChaseBehavior(float, float);
	~ChaseBehavior() {};

	void Move();

private:
	float speed;		//追いかける速度
	float distance;		//プレイヤとの最短距離
};

class RepeatHorizontalBehavior :public Behavior {
public:
	RepeatHorizontalBehavior(float,float);
	~RepeatHorizontalBehavior() {};

	void Move();

private:
	float speed;		//移動速度
	float distance;		//移動量
};

class RepeatVerticalBehavior :public Behavior {
public:
	RepeatVerticalBehavior(float, float);
	~RepeatVerticalBehavior() {};

	void Move();

private:
	float speed;		//移動速度
	float distance;		//移動量
};

class CircularBehavior :public Behavior {
public:
	CircularBehavior(float, float);
	~CircularBehavior() {};

	void Move();

private:
	float speed;		//移動速度
	float radius;		//半径
};