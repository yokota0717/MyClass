/**
* @file Error.hpp
* @brief エラーが発生した時の処理を定義する
* @author yokota0717
* @date 2018.10.27
*/

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include "DxLib.h"

//! 使いやすいようにマクロ定義
#define ERR(str) Error::finish(str, _T(__FUNCTION__), __LINE__);

class Error {
public:
	static void finish(char* errorMsg, LPCTSTR lpszFuncName, int lineN) {
		char funcName[1024];
		sprintf_s(funcName, 1024, "%s", lpszFuncName);
		std::cout << "異常が発生しました" << std::endl;
		std::cout << errorMsg << std::endl
			<< funcName << std::endl
			<< lineN << std::endl;
	}
};