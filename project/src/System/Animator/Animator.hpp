/**
* @file Animator.hpp
* @brief アニメーションを管理するクラスを定義する
* @author yokota0717
* @date 2018.10.29
*/

#pragma once
#include "../Image/Image.h"


class Animator final {
private:
	Image* image_;

public:

	void update();

};