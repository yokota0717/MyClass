#include "Game.h"
#include "../Scene/Title.h"
#include "../Scene/Stage1.h"
//#include "Player.h"

Root::Root()
	:
	GameObject("Root", GameObject::Status::run),
	frame_(0)
{}
Root::~Root() {}

void Root::init(std::shared_ptr<GameObject> thisptr) {
	setWeakPtr(thisptr);
	insertAsChild(new Title("Title", GameObject::Status::run));
	insertAsChild(new Stage1("Stage1", GameObject::Status::pause));
}
void Root::update() {
	++frame_;
}
void Root::render() {

}
int Root::frame() {
	return frame_;
}
int Root::receiveMsg(std::weak_ptr<GameObject> sender, const std::string & msg)
{
	return 0;
}
Game::Game() 
	:
	pad(0)
{
	grafac = std::make_unique<GraphFactory>();
	root = std::make_shared<Root>();
	root->init(root);
}

Game::~Game(){}

void Game::doAll() {
	kb.update();
	mouse.update();
	pad.update();
	if (kb.Down(Q)) { debug_ = !debug_; }
	root->updateWithChildren();
	root->renderWithChildren();
}
void Game::fin() {}

bool Game::DebugMode() {
	return debug_;
}

extern Game* game = new Game();