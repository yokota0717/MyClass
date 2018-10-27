/**
* @file MoveObjectBase.hpp
* @brief 動くオブジェクトの基底クラスを定義する
* @author yokota0717
* @date 2018.10.27
*/

#pragma once

#include "../System/Node/Node.h"
#include "Move/Move.h"


/**
* @brief 動くオブジェクトの基底クラス
*/
class MoveObjectBase : public Node {
private:
	Move* move_;


};