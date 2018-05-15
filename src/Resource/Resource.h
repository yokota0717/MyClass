#pragma once
#include <map>
#include <string>
#include <memory>

using namespace std;


class GraphFactory {
	map<string, int> pool;

	int CreateGraph(string);

public:
	int GetGraph(string);
};