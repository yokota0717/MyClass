#pragma once
#include <string>
#include "../Object/Object.h"

class SceneBase : public GameObject
{
	GameObject::Status preStatus_;
public:
	SceneBase(const std::string& name, GameObject::Status status);
	~SceneBase();

	bool changeScene(const std::string& scene);
};