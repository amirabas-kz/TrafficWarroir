#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

#include "CBullet.h"
#include <list>

class CLevel;

class CCar
{
public:
	CCar(CLevel *pLevel);

	void Draw(Graphics* pGraphic);

	void MoveLeft();
	void MoveRight();

	void Fire();

	void DeleteBullet(CBullet* pBullet);

private:
	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iHeight;

	std::list<CBullet*> m_lpBullets;
	CLevel *m_pLevel;
	std::list<CBullet*> m_lpForDelete;
};