#include "Game.h"
//#include "../Scene/Title.h"
//#include "../Scene/Stage1.h"
//#include "Player.h"

Root::Root()
	:
	Node("Root", Node::State::Run),
	frame_(0)
{}
Root::~Root() {
//	deleteChildren();
}

void Root::init(Node* thisptr) {
	setSelfPtr(thisptr);
	//insertAsChild(new Title("Title", Node::State::Run));
	//insertAsChild(new Stage1("Stage1", Node::State::Stop));
}
void Root::update() {
	++frame_;
}
void Root::render() {

}
int Root::frame() {
	return frame_;
}
int Root::receiveMsg(Node* sender, const std::string & msg)
{
	return 0;
}
GameManager::GameManager() 
	:
	pad(0)
{
	grafac = new GraphFactory();
	root = new Root();
	root->init(root);
}

GameManager::~GameManager(){
	delete root;
	delete grafac;
}

void GameManager::doAll() {
	kb.update();
	mouse.update();
	pad.update();
	if (kb.Down(Q)) { debug_ = !debug_; }
	root->updateWithChildren();
	root->renderWithChildren();
}
void GameManager::fin() {}

bool GameManager::DebugMode() {
	return debug_;
}

extern GameManager* game = new GameManager();