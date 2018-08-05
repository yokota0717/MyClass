#pragma once
#include "SceneBase.h"
class Title : public SceneBase
{
public:
	Title(const std::string& name);
	~Title();

	void init() override;
	void update() override;
	void render() override;
};

