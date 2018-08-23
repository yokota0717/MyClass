#pragma once
#include <string>
#include "../Object/Node.h"

class SceneBase : public Node
{
	Node::State preState_;
public:
	SceneBase(const std::string& name, Node::State state);
	~SceneBase();

	bool changeScene(const std::string& scene);
};