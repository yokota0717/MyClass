#pragma once
#include "SceneBase.h"
class Title : public SceneBase
{
public:
	Title(const std::string& name, Node::State state);
	~Title();

	void init() override;
	void update() override;
	void render() override;

	int receiveMsg(Node* sender, const std::string& msg) override;
};

