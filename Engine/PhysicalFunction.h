#pragma once

namespace Engine
{
	static class PhysicalFunction
	{
	public:
		static float getSpeed(float oldSpeed, float acceleration, float time);
		static float getMoving(float speed, float time);
	};
}