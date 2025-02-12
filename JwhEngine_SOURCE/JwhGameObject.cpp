#include "JwhGameObject.h"
#include "JwhInput.h"

namespace jw
{
	GameObject::GameObject()
		: mX(0.0f), mY(0.0f), mX2(0.0f), mY2(0.0f), aX(0.0f)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}

		if (Input::GetKey(eKeyCode::Left)) 
		{
			mX2 -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::Right)) 
		{
			mX2 += 0.01f;
		}
		if (Input::GetKey(eKeyCode::Up)) 
		{
			mY2 -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::Down)) 
		{
			mY2 += 0.01f;
		}

		switch (vec)
		{
			case 0:
			{
				aX -= 0.05f;
				if (200 + aX <= 200)
				{
					vec = 1;
				}
			}
			break;
			case 1:
			{
				aX += 0.05f;
				if (200 + aX >= 400)
				{
					vec = 0;
				}
				break;
			}
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBruch = (HBRUSH)SelectObject(hdc, blueBrush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		(HBRUSH)SelectObject(hdc, oldBruch);

		HPEN redpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HBRUSH oldPen = (HBRUSH)SelectObject(hdc, redpen);

		Ellipse(hdc, 200 + mX2, 200 + mY2, 300 + mX2, 300 + mY2);

		(HBRUSH)SelectObject(hdc, oldPen);

		HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		HBRUSH oldBru = (HBRUSH)SelectObject(hdc, grayBrush);

		Rectangle(hdc, 400 + aX, 400, 500 + aX, 500);

		(HBRUSH)SelectObject(hdc, oldBru);

		SelectObject(hdc, oldBru);
		DeleteObject(grayBrush);

		SelectObject(hdc, oldPen);
		DeleteObject(blueBrush);
		DeleteObject(redpen);
	}
}

