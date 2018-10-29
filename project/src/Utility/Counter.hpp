/**
* @file Counter.hpp
* @brief Counter�������N���X�ł�
* @author tonarinohito
* @date 2018/10/05
* @par History
- 2018/10/12 tonarinohito
-# reset()�C��
- 2018/10/16 tonarinohito
-# ++��--�̑�����������
*/
#pragma once

/*! @class Counter
*   @brief �J�E���^�[�ł�.����l�ɒB�����牺���l�A�����l�𒴂��������l�ɂȂ�܂�
*   @details �R���X�g���N�^�ŏ����l�A���Z�l�A�����l�A����l��ݒ肵�Ă�������
*   ����l�≺���l��ݒ肵�Ă��Ȃ��ꍇ�A���̌^�̍ő�l�A�ŏ��l���ݒ肳��܂�
*   �����w�肵�Ȃ��ꍇ�̉��Z�l��1�ɂȂ�܂�
*/
template <typename T> class TCounter
{
#undef max
#undef min
private:
	bool isMax_;
	bool isMin_;
	T now_;
	T add_;
	T min_;
	T max_;
public:

	TCounter() :
		isMax_(false),
		isMin_(false),
		now_(0),
		add_(1),
		min_(std::numeric_limits<T>::min()),
		max_(std::numeric_limits<T>::max())
	{};
	//!���Z�l�̂ݐݒ�
	explicit TCounter(T add) :
		isMax_(false),
		isMin_(false),
		now_(0),
		add_(add),
		min_(std::numeric_limits<T>::min()),
		max_(std::numeric_limits<T>::max())
	{};
	//!�����l�Ə���l�ݒ�
	explicit TCounter(T min, T max) :
		isMax_(false),
		isMin_(false),
		now_(0),
		add_(1),
		min_(min),
		max_(max)
	{};
	//!���ׂẴp�����[�^�ݒ�
	explicit TCounter(T now, T add, T min, T max) :
		isMax_(false),
		isMin_(false)
	{
		now_ = now;
		add_ = add;
		min_ = min;
		max_ = max;
	}
	/*!* @brief �J�E���^�[�����������܂�*/
	void SetCounter(T now, T add, T min, T max)
	{
		now_ = now;
		add_ = add;
		min_ = min;
		max_ = max;
	}
	/*!
	* @brief �J�E���^�[�����Z�l�������܂�
	* @return ���݂̃J�E���^�[�̒l
	*/
	const T operator++()
	{
		if (now_ >= max_)
		{
			now_ = min_;
		}
		else
		{
			now_ += add_;
		}
		return now_;
	}

	/*!
	* @brief �J�E���^�[�����Z�l�������܂�
	* @return ���݂̃J�E���^�[�̒l
	*/
	const T operator--()
	{
		if (now_ <= min_)
		{
			now_ = max_;
		}
		else
		{
			now_ -= add_;
		}
		return now_;
	}
	//!�I�����Ԃ܂ŉ��Z�l�����₵�܂��B����ȏ�ɂȂ������~���܂�
	void add()
	{
		if (now_ >= max_)
		{
			return;
		}
		now_ += add_;
	}
	//!�I�����Ԃ܂ŉ��Z�l�������܂��B�����ȉ��ɂȂ������~���܂�
	void sub()
	{
		if (now_ <= min_)
		{
			return;
		}
		now_ -= add_;
	}
	//!�o�ߎ��Ԃ�0�ɂ��A�t���O���ăZ�b�g���܂�
	void reset()
	{
		isMax_ = false;
		isMin_ = false;
		now_ = 0;
	}

	//!���݂̃J�E���^�[�̒l���~���b�ŕԂ��܂�
	[[nodiscard]] const T getMilliSecond(T frameRate) const
	{
		return (now_ / frameRate) * 1000;
	}

	//!�I�����Ԃ�ݒ肵�܂�
	void setEndTime(T max, T min)
	{
		max_ = max;
		min_ = min;
	}
	//!�I�����Ԃ�ݒ肵�܂�
	void setEndTime(T endTime)
	{
		max_ = endTime;
		min_ = -endTime;
	}
	//!�I�����Ԃ��^�̍ő�l�ɂ��܂�
	void setInfinity()
	{
		max_ = std::numeric_limits<T>::max();
		min_ = std::numeric_limits<T>::min();
	}

	//!�c�莞��(�I������-�o�ߎ���)��Ԃ�
	[[nodiscard]] const T getRemainingTime() const
	{
		return max_ - now_;
	}
	//!���݂̃J�E���^�[�̒l��Ԃ��܂�
	[[nodiscard]] const T& getCurrentCount() const
	{
		return now_;
	}

	/*!
	* @brief ���݂̃J�E���^�[�̒l��1�x�ł�����l�ȏ�ɓ��B�������Ԃ��܂�
	* @return bool
	*/
	[[nodiscard]] const bool isMax()
	{
		if (now_ >= max_)
		{
			isMax_ = true;
		}
		return isMax_;
	}

	/*!
	* @brief ���݂̃J�E���^�[�̒l��1�x�ł������l�ȉ��ɓ��B�������Ԃ��܂�
	* @return bool
	*/
	[[nodiscard]] const bool isMin()
	{
		if (now_ <= min_)
		{
			isMin_ = true;
		}
		return isMin_;
	}
};

typedef TCounter<int>Counter;
typedef TCounter<float>Counter_f;
typedef TCounter<double>Counter_d;
typedef TCounter<long>Counter_l;
typedef TCounter<long long>Counter_ll;