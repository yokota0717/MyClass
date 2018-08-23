#include "Title.h"
#include "../Actor/Game.h"
#include "../Actor/Player.h"
#include "../Actor/Move/Move.h"


Title::Title(const std::string& name, Node::State state)
	:
	SceneBase(name, state)
{}


Title::~Title() {}

void Title::init() {
	insertAsChild(new Player("scene1.jpg", new InputMove(Math::Vec(100, 100), 5.f)));
}

void Title::update() {
	if (game->kb.Down(SPACE)) {
		//postMsg(getObjectFromRoot("Stage1"), "changeScene");
		changeScene("Stage1");
	}
}

void Title::render()
{
	SetFontSize(50);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}

int Title::receiveMsg(Node* sender, const std::string & msg) {
	if (sender->name() == "Stage1") {
		runAll();
		sender->stopAll();
		//(getObjectFromRoot("Player").lock())->changeParent(sender, selfPtr());
		return 1;
	}
	return 0;
}
