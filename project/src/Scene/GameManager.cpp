#include "GameManager.h"

Root::Root()
	:
	Node("Root", Node::State::Run),
	frame_(0)
{}
Root::~Root() {}

void Root::init(Node* thisptr) {
	setSelfPtr(thisptr);
}
void Root::update() {
	++frame_;
}
void Root::render() {

}
int Root::frame() {
	return frame_;
}
GameManager::GameManager() 
	:
	pad(0)
{
	debug_ = false;
	sceneManager_ = new Scene::SceneManager();
	resManager_ = new ResourceManager();
	resManager_->init();
	root = new Root();
	root->init(root);
}

GameManager::~GameManager(){
	delete root;
	delete sceneManager_;
	delete resManager_;
}

void GameManager::doAll() {
	fps_.update();
	kb.update();
	mouse.update();
	pad.update();
	sceneManager_->updateTopScene();
	if (kb.Down(Q)) { debug_ = !debug_; }
	root->updateWithChildren();
	sceneManager_->renderTopScene();
	root->renderWithChildren();
	fps_.wait();
}
void GameManager::fin() {}

bool GameManager::DebugMode() {
	return debug_;
}

extern GameManager* game = new GameManager();