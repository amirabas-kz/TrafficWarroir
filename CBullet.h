#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

class CLevel;
class CCar;

class CBullet
{
public:
	CBullet(int iX, int iY, CLevel* pLevel, CCar *pCar);

	void Draw(Graphics* pGraphic);
	
	int GetX();
	int GetY();
	int GetW();

private:
	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iHeight;

	void Addvance();

	CLevel* m_pLevel;
	CCar* m_pCar;
};