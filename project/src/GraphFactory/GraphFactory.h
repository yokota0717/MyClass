#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>

class GraphFactory {
	std::string path;
	std::map<std::string, int> pool;

	int CreateGraph(const std::string& fileName);

public:
	GraphFactory();
	int GetGraph(const std::string& fileName);
};