/**
* @file Stage1.h
* @brief �Q�[���{�҂̓��e���`����
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include "SceneInfo.hpp"

namespace Scene {
	/**
	* @brief �Q�[���{�҂̓��e���`����
	*/
	class Stage1 : public AbstractScene
	{
	public:
		Stage1(IOnSceneChangedListener* listener, const Parameter& param);
		~Stage1();

		void update() override;
		void render() override;
	};


}
