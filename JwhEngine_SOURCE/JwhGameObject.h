#pragma once
#include "CommonInclude.h"

namespace jw
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
			mX2 = x;
			mY2 = y;
			aX = x;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }
		float GetPositionX2() { return mX2; }
		float GetPositionY2() { return mY2; }
		float GetPositionAY() { return aX; }
	private:
		//ÁÂÇ¥
		float mX;
		float mY;
		float mX2;
		float mY2;
		float aX;
		int vec = 1;
	};
}


