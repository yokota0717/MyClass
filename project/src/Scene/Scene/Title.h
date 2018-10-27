/**
* @file Title.h
* @brief タイトルシーンの内容を記述する
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include "../SceneInfo.hpp"
#include "../../System/Image/Image.h"

namespace Scene {
	class Title : public AbstractScene {
	public:
		Title(IOnSceneChangedListener* listener, [[maybe_unused]]const Parameter& param);
		~Title();

		void update() override;
		void render() override;
	};
}
