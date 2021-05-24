#include "CCar.h"
#include "CLevel.h"

CCar::CCar(CLevel *pLevel)
	: m_iX(135)
	, m_iY(10)
	, m_iWidth(30)
	, m_iHeight(45)
	, m_pLevel(pLevel)
{

}

void CCar::Draw(Graphics* pGraphic)
{
	SolidBrush  brush(Color(255, 0, 0, 120));
	Rect rect(m_iX, m_iY, m_iWidth, m_iHeight);
	pGraphic->FillRectangle(&brush, rect);

	rect = { m_iX + m_iWidth / 2 - 2, m_iY + m_iHeight, 4, 4 };
	pGraphic->FillRectangle(&brush, rect);

	for (auto bullet : m_lpBullets)
		bullet->Draw(pGraphic);

	for (auto item : m_lpForDelete)
	{
		for (auto it = m_lpBullets.begin(); it != m_lpBullets.end(); ++it)
		{
			if (*it == item)
			{
				delete *it;
				m_lpBullets.erase(it);
				break;
			}
		}

	}
	m_lpForDelete.clear();
}

void CCar::MoveLeft()
{
	if (m_iX >= 10)
		m_iX -= 10;
}

void CCar::MoveRight()
{
	if (m_iX < 260)
		m_iX += 10;
}

void CCar::Fire()
{
	CBullet* pBullet = new CBullet(m_iX + static_cast<int>(m_iWidth / 2), m_iY + m_iHeight, m_pLevel, this);
	m_lpBullets.push_back(pBullet);
}

void CCar::DeleteBullet(CBullet* pBullet)
{
	m_lpForDelete.push_back(pBullet);
}