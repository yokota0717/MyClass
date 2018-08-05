#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>

using namespace std;


class GraphFactory {
	string path;
	map<string, int> pool;

	int CreateGraph(const std::string& fileName);

public:
	GraphFactory();
	int GetGraph(const std::string& fileName);
};