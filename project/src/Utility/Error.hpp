/**
* @file Error.hpp
* @brief �G���[�������������̏������`����
* @author yokota0717
* @date 2018.10.27
*/

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include "DxLib.h"

//! �g���₷���悤�Ƀ}�N����`
#define ERR(str) Error::finish(str, _T(__FUNCTION__), __LINE__);

class Error {
public:
	static void finish(char* errorMsg, LPCTSTR lpszFuncName, int lineN) {
		char funcName[1024];
		sprintf_s(funcName, 1024, "%s", lpszFuncName);
		std::cout << "�ُ킪�������܂���" << std::endl;
		std::cout << errorMsg << std::endl
			<< funcName << std::endl
			<< lineN << std::endl;
	}
};