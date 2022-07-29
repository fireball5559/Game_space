#pragma once

namespace math
{
	const float Pi = 3.14159265359f; // 180
	const float TwoPi = 6.28318530718f; // 360
	const float HalfPi = 1.57079632679f; // 90

	int sqr(int v);
	inline int half(int v) { return v / 2; }
	inline float DegToRad(float degrees) 
	{
		return degrees * (Pi / 180);
	};	
	inline float RadToDeg(float Radians) 
	{
		return Radians * (180/Pi);
	};
}

