#include "Player.h"
#include "../Scene/GameManager.h"


Player::Player(const std::string& path, Move* move)
	:
	Node("Player", Node::State::Run),
	image_(path),
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
	image_.draw(Math::Box2D(move_->getPos().x, move_->getPos().y, 100, 100), Math::Box2D(0, 0, 800, 600));
}

void Player::fin() 
{}
