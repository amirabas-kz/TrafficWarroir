#include "CLevel.h"
#include <string>

#include <cstdlib>
#include <ctime>

CLevel::CLevel()
	: m_iWidth(300) // change these 2 variables to proper values
	, m_iHeight(500)
	, m_bShowMenu(true)
	, m_bExitState(false)
{
	srand(time(nullptr));

	m_pCar = new CCar(this);

	CreateBlocks();
}
int CLevel::GetWidth() const
{
	return m_iWidth;
}

int CLevel::GetHeight() const
{
	return m_iHeight;
}

// #############################################################################################
void CLevel::KeyDown(int iKey)
{
	if (m_bShowMenu)
	{
		if (iKey == VK_DOWN)
			m_Menu.SelectNext();
		else if (iKey == VK_UP)
			m_Menu.SelectPrev();
		else if (iKey == VK_RETURN)
		{
			if (m_Menu.GetSelected() == 0)
				m_bShowMenu = false;
			else if (m_Menu.GetSelected() == 2)
				m_bExitState = true;
		}
	}
	else
	{
		if (iKey == VK_RIGHT)
			m_pCar->MoveRight();
		else if (iKey == VK_LEFT)
			m_pCar->MoveLeft();
		else if (iKey == VK_SPACE)
			m_pCar->Fire();
		else if (iKey == VK_ESCAPE)
			m_bShowMenu = true;
	}
}


void CLevel::CreateBlocks()
{
	int k = rand() % 3 + 1;

	for (int m = 0; m < k; ++m)
	{
		int iW = 20 * rand() / (float)RAND_MAX + 20;
		int iX = (m_iWidth - iW) * rand() / (float)RAND_MAX;

		CBlock* pbl = new CBlock(iX, m_iHeight, iW, 20, this);
		m_lpBlocks.push_back(pbl);
	}
}

void CLevel::DeleteBlock(CBlock* pBlock)
{
	m_lpForDelete.push_back(pBlock);
}


bool CLevel::CheckCollision(CBullet* pBullet)
{
	bool bRes = false;
	for (auto blocks : m_lpBlocks)
	{
		bRes = blocks->ColideWithBullet(pBullet);

		if (bRes)
			break;
	}

	return bRes;
}

void CLevel::DrawAll(Graphics* pGraphic)
{
	if (m_bShowMenu)
		m_Menu.Draw(pGraphic);
	else
	{
		m_pCar->Draw(pGraphic);

		static int i = 0;
		++i;

		for (auto blocks : m_lpBlocks)
		{
			blocks->Draw(pGraphic);

			if (i > 20)
				blocks->Move();
		}

		if (i > 20)
			i = 0;

		for (auto item : m_lpForDelete)
		{
			for (auto it = m_lpBlocks.begin(); it != m_lpBlocks.end(); ++it)
			{
				if (*it == item)
				{
					delete *it;
					m_lpBlocks.erase(it);
					break;
				}
			}

		}
		m_lpForDelete.clear();


		static int j = 0;
		++j;
		if (j > 1000)
		{
			j = 0;
			CreateBlocks();
		}

		Pen      pen(Color(255, 0, 0, 255), 2.0f);
		pGraphic->DrawLine(&pen, 0, 60, m_iWidth, 60);
	}
}

bool CLevel::IsMustExit()
{
	return m_bExitState;
}