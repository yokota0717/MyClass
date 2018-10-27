#include "Stage1.h"
#include "DxLib.h"
#include "../GameManager.h"

namespace Scene {
	Stage1::Stage1(IOnSceneChangedListener* listener, [[maybe_unused]]const Parameter& param)
		:
		AbstractScene(listener)
	{
	}


	Stage1::~Stage1()
	{
	}

	void Stage1::update() {
		if (game->kb.Down(ENTER)) {
			callBack().onSceneChanged(Scene::SceneName::TITLE, nullptr, Scene::StackPopFlag::POP);
		}
	}

	void Stage1::render() {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "stage1");
	}
}

