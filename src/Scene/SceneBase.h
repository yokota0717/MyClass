#pragma once
#include <string>
#include "../Object/Object.h"

class SceneBase : public GameObject
{
	//const std::string name_;
public:
	SceneBase(const std::string& name);
	~SceneBase();

	//bool changeScene(SceneBase* scene);
};