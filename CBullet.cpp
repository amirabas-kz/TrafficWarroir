#include "CBullet.h"
#include "CLevel.h"
#include "CCar.h"

CBullet::CBullet(int iX, int iY, CLevel* pLevel, CCar *pCar)
	: m_iX(iX - 5)
	, m_iY(iY)
	, m_iWidth(10)
	, m_iHeight(10)
	, m_pLevel(pLevel)
	, m_pCar(pCar)
{
}

void CBullet::Draw(Graphics* pGraphic)
{
	SolidBrush  brush(Color(255, 0, 0, 120));
	Rect rect(m_iX, m_iY, m_iWidth, m_iHeight);
	pGraphic->FillRectangle(&brush, rect);

	Addvance();
}

void CBullet::Addvance()
{
	m_iY += 10;

	if (m_pLevel->CheckCollision(this))
		m_pCar->DeleteBullet(this);
	else if (m_iY > 500)
		m_pCar->DeleteBullet(this);
}

int CBullet::GetX()
{
	return m_iX;
}

int CBullet::GetY()
{
	return m_iY;
}

int CBullet::GetW()
{
	return m_iWidth;
}