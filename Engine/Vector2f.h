#pragma once

namespace Engine
{
	class Vector2f
	{
	private:
		float x, y;

	public:
		Vector2f(float x = 0, float y = 0);

		void setX(float x);
		float getX();

		void setY(float y);
		float getY();

		float getLength();

		float getDistance(Vector2f vector);
	};
}