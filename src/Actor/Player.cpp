#include "Player.h"
#include "Game.h"


Player::Player(const std::string& path)
	:
	GameObject("Player", GameObject::Status::run),
	image_(path)
{
}

Player::~Player()
{}

void Player::init() {}

void Player::update() {
}

void Player::render() {
	image_.draw(Math::Box2D(10, 10, 200, 100), Math::Box2D(0, 0, 800, 600));
}

void Player::fin() 
{}
