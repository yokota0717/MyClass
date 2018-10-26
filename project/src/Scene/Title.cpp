#include "Title.h"
#include "DxLib.h"

namespace Scene {
	Title::Title(IOnSceneChangedListener* listener, const Parameter& param)
		:
		AbstractScene(listener, param)
	{}

	Title::~Title() {}

	void Title::update() {
	}

	void Title::render()
	{
		SetFontSize(50);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
	}
}
