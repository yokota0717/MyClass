/**
 * @file Random.hpp
 * @brief �����Ɋւ��鏈�����L�q���܂�
 * @author tonarinohito
 * @date 2018/10/05
 */
#pragma once
#include <random>
 /**
 * @brief �����_���Ȓl�������܂�
 */
class Random
{
private:
	std::mt19937 mt_;

public:
	Random()
	{
		std::random_device device;
		mt_.seed(device());
	}

	//![min, max]�͈͂̈�l�������擾���܂�
	[[nodiscard]] const int getRand(int min, int max)
	{
		std::uniform_int_distribution<int> range(min, max);
		return range(mt_);
	}
	//![min, max]�͈͂̈�l�������擾���܂�
	[[nodiscard]] const float getRand(float min, float max)
	{
		std::uniform_real_distribution<float> range(min, max);
		return range(mt_);
	}
	//![min, max]�͈͂̈�l�������擾���܂�
	[[nodiscard]] const double getRand(double min, double max)
	{
		std::uniform_real_distribution<double> range(min, max);
		return range(mt_);
	}
};