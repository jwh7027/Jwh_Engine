#pragma once
#include "CommonInclude.h"
#include "JwhGameObject.h"

namespace jw
{
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND mHwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;
		//플레이어
		//float mX;
		//float mY;
		GameObject mPlayer;
	};
}


