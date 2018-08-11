#include "Move.h"
#include "../Game.h"


Move::Move(Math::Vec& pos, float speed)
	:
	pos_(pos),
	speed_(speed)
{
}


Move::~Move()
{
}

Math::Vec& Move::getPos(){
	return pos_;
}

InputMove::InputMove(Math::Vec& pos, float speed)
	:
	Move(pos, speed)
{}

void InputMove::move(){
	if (game->kb.On(LEFT)) {
		pos_.x -= speed_;
	}
	if (game->kb.On(RIGHT)) {
		pos_.x += speed_;
	}
	if (game->kb.On(UP)) {
		pos_.y -= speed_;
	}
	if (game->kb.On(DOWN)) {
		pos_.y += speed_;
	}
}
