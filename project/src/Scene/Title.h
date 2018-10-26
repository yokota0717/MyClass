/**
* @file Title.h
* @brief タイトルシーンの内容を記述する
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include "SceneInfo.hpp"

namespace Scene {
	class Title : public AbstractScene
	{
	public:
		Title(IOnSceneChangedListener* listener, const Parameter& param);
		~Title();

		void update() override;
		void render() override;
	};
}
