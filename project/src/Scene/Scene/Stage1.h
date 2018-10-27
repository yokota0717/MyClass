/**
* @file Stage1.h
* @brief �Q�[���{�҂̓��e���`����
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include "../SceneInfo.hpp"
#include "../../System/Image/Image.h"

namespace Scene {
	/**
	* @brief �Q�[���{�҂̓��e���`����
	*/
	class Stage1 : public AbstractScene
	{
	public:
		Stage1(IOnSceneChangedListener* listener, [[maybe_unused]]const Parameter& param);
		~Stage1();

		void update() override;
		void render() override;
	};


}
