#pragma once

#include "../WorldData.h"
#include <math.h>


enum class EasingName
{
	LINEAR,
	BACK_IN,
	BACK_OUT,
	BACK_INOUT,
	BOUNCE_OUT,
	BOUNCE_IN,
	BOUNCE_INOUT,
	CIRCLE_IN,
	CIRCLE_OUT,
	CIRCLE_INOUT,
	CUBIC_IN,
	CUBIC_OUT,
	CUBIC_INOUT,
	ELASTIC_IN,
	ELASTIC_OUT,
	ELASTIC_INOUT,
	EXPO_IN,
	EXPO_OUT,
	EXPO_INOUT,
	QUAD_IN,
	QUAD_OUT,
	QUAD_INOUT,
	QUART_IN,
	QUART_OUT,
	QUART_INOUT,
	QUINT_IN,
	QUINT_OUT,
	QUINT_INOUT,
	SINE_IN,
	SINE_OUT,
	SINE_INOUT
};

inline std::string GetName(const EasingName& n)
{
	std::string name[]
	{
		"LINEAR",
		"BACK_IN",
		"BACK_OUT",
		"BACK_INOUT",
		"BOUNCE_OUT",
		"BOUNCE_IN",
		"BOUNCE_INOUT",
		"CIRCLE_IN",
		"CIRCLE_OUT",
		"CIRCLE_INOUT",
		"CUBIC_IN",
		"CUBIC_OUT",
		"CUBIC_INOUT",
		"ELASTIC_IN",
		"ELASTIC_OUT",
		"ELASTIC_INOUT",
		"EXPO_IN",
		"EXPO_OUT",
		"EXPO_INOUT",
		"QUAD_IN",
		"QUAD_OUT",
		"QUAD_INOUT",
		"QUART_IN",
		"QUART_OUT",
		"QUART_INOUT",
		"QUINT_IN",
		"QUINT_OUT",
		"QUINT_INOUT",
		"SINE_IN",
		"SINE_OUT",
		"SINE_INOUT",
	};
	return name[static_cast<int>(n)];
}

template<typename T>
class Easing {
public:
	Easing():
		start(T()),
		end(T()),
		duration(0),
		elapse(0)
	{}
	Easing(T s, T e, int dur, int elp) :
		start(s),
		end(e),
		duration(dur),
		elapse(elp)
	{}

private:
	T start;			//開始(座標だったりサイズだったり)
	T end;				//終了
	int duration;		//何秒で終わらせるか
	int elapse;			//経過時間
};

//引用URL：https://qiita.com/hart_edsf/items/962ac03281b871dcc0df
//イージング関数
namespace Ease
{
	float InQuad(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		return max*t*t + min;
	}
	float OutQuad(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		return -max*t*(t - 2) + min;
	}
	float InOutQuad(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		if (t / 2 < 1)
			return max / 2 * t * t + min;
		--t;
		return -max * (t * (t - 2) - 1) + min;
	}
	float InCubic(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		return max * t*t*t + min;
	}
	float OutCubic(float t, float totaltime, float max, float min) {
		max -= min;
		t = t / totaltime - 1;
		return max * (t*t*t + 1) + min;
	}
	float InOutCubic(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		if (t / 2 < 1)
			return max / 2 * t*t*t + min;
		t -= 2;
		return max / 2 * (t*t*t + 2) + min;
	}
	float InQuart(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		return max * t*t*t*t + min;
	}
	float OutQuart(float t, float totaltime, float max, float min) {
		max -= min;
		t = t / totaltime - 1;
		return -max*(t*t*t*t - 1) + min;
	}
	float InOutQuart(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		if (t / 2 < 1)
			return max / 2 * t*t*t*t + min;
		t -= 2;
		return -max / 2 * (t*t*t*t - 2) + min;
	}
	float InQuint(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		return max*t*t*t*t*t + min;
	}
	float OutQuint(float t, float totaltime, float max, float min) {
		max -= min;
		t = t / totaltime - 1;
		return max*(t*t*t*t*t + 1) + min;
	}
	float InOutQuint(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		if (t / 2 < 1)
			return max / 2 * t*t*t*t*t + min;
		t -= 2;
		return max / 2 * (t*t*t*t*t + 2) + min;
	}
	float InSine(float t, float totaltime, float max, float min) {
		max -= min;
		return -max*cos(t*ToRadian(90) / totaltime) + max + min;
	}
	float OutSine(float t, float totaltime, float max, float min) {
		max -= min;
		return max * sin(t*ToRadian(90) / totaltime) + min;
	}
	float InOutSine(float t, float totaltime, float max, float min) {
		max -= min;
		return -max / 2 * (cos(t*PI / totaltime) - 1) + min;
	}
	float InExp(float t, float totaltime, float max, float min) {
		max -= min;
		return t == 0.0 ? min : max*powf(2, 10 * (t / totaltime - 1)) + min;
	}
	float OutExp(float t, float totaltime, float max, float min) {
		max -= min;
		return t == totaltime ? max + min : max*(-powf(2, -10 * t / totaltime) + 1) + min;
	}
	float InOutExp(float t, float totaltime, float max, float min) {
		if (t == 0.0)
			return min;
		if (t == totaltime)
			return max;
		max -= min;
		t /= totaltime;

		if (t / 2 < 1)
			return max / 2 * powf(2, 10 * (t - 1)) + min;
		--t;
		return max / 2 * (-powf(2, -10 * t) + 2) + min;

	}
	float InCirc(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		return -max*(sqrt(1 - t*t) - 1) + min;
	}
	float OutCirc(float t, float totaltime, float max, float min) {
		max -= min;
		t = t / totaltime - 1;
		return max*sqrt(1 - t*t) + min;
	}
	float InOutCirc(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;
		if (t / 2 < 1)
			return -max / 2 * (sqrt(1 - t*t) - 1) + min;
		t -= 2;
		return max / 2 * (sqrt(1 - t*t) + 1) + min;
	}
	float InBack(float t, float totaltime, float max, float min, float s) {
		max -= min;
		t /= totaltime;
		return max*t*t*((s + 1)*t - s) + min;
	}
	float OutBack(float t, float totaltime, float max, float min, float s) {
		max -= min;
		t = t / totaltime - 1;
		return max*(t*t*((s + 1)*t*s) + 1) + min;
	}
	float InOutBack(float t, float totaltime, float max, float min, float s) {
		max -= min;
		s *= 1.525f;
		if (t / 2 < 1)
			return max*(t*t*((s + 1)*t - s)) + min;
		
		t -= 2;
		return max / 2 * (t*t*((s + 1)*t + s) + 2) + min;
	}
	float OutBounce(float t, float totaltime, float max, float min) {
		max -= min;
		t /= totaltime;

		if (t < 1 / 2.75)
			return max*(7.5625f*t*t) + min;
		else if (t < 2 / 2.75)
		{
			t -= 1.5f / 2.75f;
			return max*(7.5625f*t*t + 0.75f) + min;
		}
		else if (t< 2.5 / 2.75)
		{
			t -= 2.25f / 2.75f;
			return max*(7.5625f*t*t + 0.9375f) + min;
		}
		else
		{
			t -= 2.625f / 2.75f;
			return max*(7.5625f*t*t + 0.984375f) + min;
		}
	}
	float InBounce(float t, float totaltime, float max, float min) {
		return max - OutBounce(totaltime - t, totaltime, max - min, 0) + min;
	}
	float InOutBounce(float t, float totaltime, float max, float min) {
		if (t < totaltime / 2)
			return InBounce(t * 2.0f, totaltime, max - min, max)*0.5f + min;
		else
			return OutBounce(t * 2.0f - totaltime, totaltime, max - min, 0)*0.5f + min + (max - min)*0.5f;
	}
	float Linear(float t, float totaltime, float max, float min) {
		return (max - min)*t / totaltime + min;
	}
	float InElastic(float t, float totaltime, float max, float min) {
		return 0;
	}


	/*
	{
		// t = 経過時間 b = 始点 c = 終点 - 始点 d = 持続時間 
		"ELASTIC_IN",
			[](float t, const float b, const float c, const float d)
		{
			t = clamp(t, 0.0f, d);	//tを 0.0f <= t <= d　に丸め込み

			if (t == 0)      return b;
			if ((t /= d) == 1) return b + c;
			float p = d*0.3f;

			float a = c;
			float s = p / 4;
			t -= 1;
			return -(a * std::pow(2.0f, 10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)) + b;
		}
	},

	{
		"ELASTIC_OUT",
		[](float t, const float b, const float c, const float d)
		{
			t = clamp(t, 0.0f, d);

			if (t == 0)      return b;
			if ((t /= d) == 1) return b + c;
			float p = d*0.3f;

			float a = c;
			float s = p / 4;
			return (a* std::pow(2.0f, -10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p) + c + b);
		}
	},

	{
		"ELASTIC_INOUT",
		[](float t, const float b, const float c, const float d)
		{
			t = clamp(t, 0.0f, d);

			if (t == 0) return b;
			if ((t /= d / 2) == 2) return b + c;
			float p = d*(0.3f*1.5f);

			float a = c;
			float s = p / 4;
			if (t < 1)
			{
				t -= 1;
				return -0.5f*(a * std::pow(2.0f, 10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)) + b;
			}
			t -= 1;
			return a * std::pow(2.0f, -10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)*0.5f + c + b;
		}
	},
	*/
}