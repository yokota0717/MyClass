#include "Move.h"
#include "../../Scene/GameManager.h"


MoveBase::MoveBase(const Math::Vec& pos, const float speed, const bool gravity)
	:
	pos_(pos),
	speed_(speed),
	isGravity_(gravity),
	gravity_(-9.8f)
{}


MoveBase::~MoveBase()
{}

Math::Vec& MoveBase::getPos() {
	return pos_;
}

//void InputMove::move(){
//	if (game->kb.On(LEFT)) {
//		pos_.x -= speed_;
//	}
//	if (game->kb.On(RIGHT)) {
//		pos_.x += speed_;
//	}
//	if (game->kb.On(UP)) {
//		pos_.y -= speed_;
//	}
//	if (game->kb.On(DOWN)) {
//		pos_.y += speed_;
//	}
//}

PlayerMove::PlayerMove(const Math::Vec & pos, const float speed, const bool gravity)
	:
	MoveBase(pos, speed, gravity)
{}

void PlayerMove::move() {
}
