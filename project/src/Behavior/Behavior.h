#pragma once


//�ӂ�܂��N���X�̊��N���X
class Behavior {	
public:
	virtual ~Behavior() {};
	virtual void Move() = 0;
};



//�v���C����ǂ�������
class ChaseBehavior :public Behavior {		
public:
	ChaseBehavior(float, float);
	~ChaseBehavior() {};

	void Move();

private:
	float speed;		//�ǂ������鑬�x
	float distance;		//�v���C���Ƃ̍ŒZ����
};

class RepeatHorizontalBehavior :public Behavior {
public:
	RepeatHorizontalBehavior(float,float);
	~RepeatHorizontalBehavior() {};

	void Move();

private:
	float speed;		//�ړ����x
	float distance;		//�ړ���
};

class RepeatVerticalBehavior :public Behavior {
public:
	RepeatVerticalBehavior(float, float);
	~RepeatVerticalBehavior() {};

	void Move();

private:
	float speed;		//�ړ����x
	float distance;		//�ړ���
};

class CircularBehavior :public Behavior {
public:
	CircularBehavior(float, float);
	~CircularBehavior() {};

	void Move();

private:
	float speed;		//�ړ����x
	float radius;		//���a
};