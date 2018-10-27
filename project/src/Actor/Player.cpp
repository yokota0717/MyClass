#include "Player.h"
#include "../Scene/GameManager.h"


Player::Player(const std::string& path, Move* move)
	:
	Node("Player", Node::State::Run),
	move_(move)
{
}

Player::~Player()
{
	delete move_;
}

void Player::init() {}

void Player::update() {
	move_->move();
}

void Player::render() {
	image_.draw(Math::Vec(move_->getPos().x, move_->getPos().y), true);
}

void Player::fin() 
{}
