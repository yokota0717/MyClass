#include "Stage1.h"
#include "DxLib.h"

namespace Scene {
	Stage1::Stage1(IOnSceneChangedListener* listener, const Parameter& param)
		:
		AbstractScene(listener, param)
	{
	}


	Stage1::~Stage1()
	{
	}

	void Stage1::update() {
	}

	void Stage1::render() {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "stage1");
	}
}

