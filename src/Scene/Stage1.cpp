#include "Stage1.h"
#include "../Actor/Game.h"


Stage1::Stage1(const std::string& name, Node::State state)
	:
	SceneBase(name, state)
{
}


Stage1::~Stage1()
{
}

void Stage1::init(){

}

void Stage1::update(){
	if (game->kb.Down(ENTER)) {
		//postMsg(getObjectFromRoot("Title"), "changeScene");
		changeScene("Title");
	}
}

void Stage1::render(){
	DrawFormatString(0, 0, GetColor(255, 255, 255), "stage1");
}

int Stage1::receiveMsg(Node* sender, const std::string & msg){
	if (msg == "changeScene") {
		if (sender->name() == "Title") {
			runAll();
			sender->stopAll();
			//auto player = getObjectFromRoot("Player").lock();
			//player->changeParent(selfPtr(), player->selfPtr());
			return 1;
		}
	}
	return 0;
}
