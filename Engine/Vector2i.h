#pragma once

namespace Engine
{
	class Vector2i
	{
	private:
		int x, y;

	public:
		Vector2i(int x = 0, int y = 0);

		void setX(int x);
		int getX();

		void setY(int y);
		int getY();

		int getLength();

		int getDistance(Vector2i vector);
	};
}