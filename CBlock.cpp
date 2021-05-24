#include "CBlock.h"
#include "CLevel.h"

CBlock::CBlock(int iX, int iY, int iWidth, int iHeight, CLevel* pLevel)
	: m_iX(iX)
	, m_iY(iY)
	, m_iWidth(iWidth)
	, m_iHeight(iHeight)
	, m_pLevel(pLevel)
	, m_iColor(200)
{
}

void CBlock::Draw(Graphics* pGraphic)
{
	SolidBrush  brush(Color(255, m_iColor, 0, 0));
	Rect rect(m_iX, m_iY, m_iWidth, m_iHeight);
	pGraphic->FillRectangle(&brush, rect);
}

void CBlock::Move()
{
	m_iY -= 7;

	if (m_iY < 60)
		Distroid();
}

void CBlock::Distroid()
{
	m_pLevel->DeleteBlock(this);
}

bool CBlock::ColideWithBullet(CBullet* pBullet)
{
	bool bRes = false;
	if (((pBullet->GetX() >= m_iX && pBullet->GetX() <= m_iX + m_iWidth) ||
		(pBullet->GetX() - pBullet->GetW() >= m_iX && pBullet->GetX() - pBullet->GetW() <= m_iX + m_iHeight)) &&
		pBullet->GetY() >= m_iY)
	{
		bRes = true;
		m_iColor -= 30;
	}

	if (m_iColor < 0)
	{
		m_iColor = 0;
		m_pLevel->DeleteBlock(this);
	}

	return bRes;
}