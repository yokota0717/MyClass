#include "Title.h"
#include "../Actor/Game.h"
#include "../Actor/Player.h"
#include "../Actor/Move/Move.h"


Title::Title(const std::string& name, GameObject::Status status)
	:
	SceneBase(name, status)
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

int Title::receiveMsg(std::weak_ptr<GameObject> sender, const std::string & msg) {
	if (sender.lock()->name() == "Stage1") {
		runAll();
		sender.lock()->pauseAll();
		//(getObjectFromRoot("Player").lock())->changeParent(sender, selfPtr());
		return 1;
	}
	return 0;
}
