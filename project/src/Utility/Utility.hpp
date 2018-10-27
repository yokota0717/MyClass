/**
 * @file Utility.hpp
 * @brief �֗��ȏ����Q�ł�
 * @author tonarinohito
 * @date 2018/10/04
 */
#pragma once
#include <iostream>
#include <chrono>
#include <cstdio>
#include <windows.h>

#ifdef _DEBUG
 //!�f�o�b�O���ɃR���\�[����\�����܂�
#define ShowConsole() Utility::Console c
//!�R���\�[����cout�������܂�
#define StartOutputDbgString() Utility::coutDbgString c
/**
* @brief �f�o�b�O���ɃR���\�[���ւ̏o�͂����閽�߂ł��B
* @details �Ăяo�����֐������o�͂���܂�
* �����_���ł͎g���܂���B�֐��I�u�W�F�N�g�ł�operator()�ƂȂ��Ă��܂��܂��B
*/
#define DOUT_BY_FUNCTION std::cout << __func__ << ":"
//!�f�o�b�O���ɃR���\�[���ւ̏o�͂����閽�߂ł��B
#define DOUT std::cout
/**
* @brief �R���\�[���ւ̏o�͎��Ƀt�@�C�����ƍs����\�����܂�
* @details DOUT << FILENAME_AND_LINE; �̂悤�Ɏg���܂�
*/
#define FILENAME_AND_LINE __FILE__ << ":" << __LINE__
#else 
#define DOUT_BY_FUNCTION 0 && std::cout 
#define DOUT 0 && std::cout
#define FILENAME_AND_LINE 0 && std::cout
#define ShowConsole() __noop
#define StartOutputDbgString() __noop
#endif
namespace Utility
{
	/*!
	* @class Console
	* @brief Win32�A�v����cin�Acout��������N���X�ł�
	*/
	class Console final
	{
		std::FILE* in_;
		std::FILE* out_;
	public:
		Console()
		{
			AllocConsole();
			freopen_s(&out_, "CONOUT$", "w", stdout); //�W���o�͂��R���\�[���ɂ���
			freopen_s(&in_, "CONIN$", "r", stdin);  //�W�����͂��R���\�[���ɂ���
		}
		~Console()
		{
			std::fclose(in_);
			std::fclose(out_);
			FreeConsole();
		}
	};

	/*!
	@class coutDbgString
	@brief cout�Ńf�o�b�O�E�C���h�E�ɏo�͂ł���悤�ɂȂ�N���X�ł�
	*/
	class coutDbgString final
	{
	private:
		class DbgStreambuf final : public std::streambuf
		{
		public:
			[[nodiscard]] std::streamsize xsputn(const char* s, std::streamsize n)
			{
				OutputDebugString(s);
				return n;
			}
			[[nodiscard]] int_type overflow(int_type c = EOF)
			{
				if (c != EOF)
				{
					char buf[2] = { (char)c, '\0' };
					OutputDebugString(buf);
				}
				return c;
			}
		};
		std::streambuf* default_stream;
		DbgStreambuf debug_stream;
	public:
		coutDbgString()
		{
			default_stream = std::cout.rdbuf(&debug_stream);
		}
		~coutDbgString()
		{
			std::cout.rdbuf(default_stream);
		}
	};

	//!�����ɓ��ꂽ�|�C���^��������܂�
	template<class T> void SafeDelete(T& t)
	{
		if (t)
		{
			delete t;
			t = nullptr;
		}
	}
	//!�����ɓ��ꂽ�z���������܂�
	template<class T> void SafeDeleteArray(T& t)
	{
		if (t)
		{
			delete[] t;
			t = nullptr;
		}
	}

	//!�����ɓ��ꂽ�I�u�W�F�N�g��������܂�
	template<class T> void SafeRelease(T& t)
	{
		if (t)
		{
			t->release();
			t = nullptr;
		}
	}

	/*!
	* @class ProcessingTime
	* @brief �������Ԃ��v�����܂��B
	* @details�@�C���X�^���X�����ꂽ��v�����J�n���A�f�X�g���N�^�Ōv�����ʂ��R���\�[���ɏ����o���܂�
	*/
	template<class T = std::chrono::milliseconds>
	class ProcessingTime final
	{
	private:
		std::string name_;
		std::chrono::system_clock::time_point start_;
		bool isActive_;

	public:
		//!�v�����J�n���܂�
		ProcessingTime(const std::string& a = "Process", bool start = true) :
			name_(a),
			isActive_(start)
		{
			if (start)
			{
				this->reStart();
			}
		}
		~ProcessingTime()
		{
			stop();
		}

		//!�v���̃��X�^�[�g
		void reStart()&
		{
			start_ = std::chrono::system_clock::now();
			isActive_ = true;
		}
		//!�v�����I�����o��
		void stop()&
		{
			if (!isActive_)
				return;
			const auto end = std::chrono::system_clock::now();
			const auto elapsed = std::chrono::duration_cast<T>(end - start_).count();
			if (typeid(T) == typeid(std::chrono::nanoseconds))
			{
				DOUT << elapsed << " [nanoseconds]" << std::endl;
				return;
			}
			if (typeid(T) == typeid(std::chrono::microseconds))
			{
				DOUT << elapsed << " [microseconds]" << std::endl;
				return;
			}
			if (typeid(T) == typeid(std::chrono::milliseconds))
			{
				DOUT << elapsed << " [milliseconds]" << std::endl;
				return;
			}
			if (typeid(T) == typeid(std::chrono::seconds))
			{
				DOUT << elapsed << " [seconds]" << std::endl;
				return;
			}
			if (typeid(T) == typeid(std::chrono::minutes))
			{
				DOUT << elapsed << " [minutes]" << std::endl;
				return;
			}
			if (typeid(T) == typeid(std::chrono::hours))
			{
				DOUT << elapsed << " [hours]" << std::endl;
				return;
			}
			isActive_ = false;
		}
	};
}