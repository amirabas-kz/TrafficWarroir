#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

class CLevel;
class CBullet;

class CBlock
{
public:
	CBlock(int iX, int iY, int iWidth, int iHeight, CLevel* pLevel);

	void Draw(Graphics* pGraphic);

	void Move();
	void Distroid();

	bool ColideWithBullet(CBullet* pBullet);

private:
	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iHeight;

	CLevel* m_pLevel;
	int m_iColor;
};