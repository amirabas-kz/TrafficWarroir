#include "CMenu.h"
#include <string>

CMenu::CMenu()
	: m_iSelected(0)
{
	CMenuItem* pMenuItem = new CMenuItem(L"New Game");
	pMenuItem->SetSelected(true);
	m_vpMenuItem.push_back(pMenuItem);

	pMenuItem = new CMenuItem(L"Settings");
	m_vpMenuItem.push_back(pMenuItem);

	pMenuItem = new CMenuItem(L"Exit");
	m_vpMenuItem.push_back(pMenuItem);
}

void CMenu::Draw(Graphics* pGraphic)
{
	int iY = 70;
	for (int i = 0; i < m_vpMenuItem.size(); ++i)
	{
		m_vpMenuItem[i]->Draw(pGraphic, 40.0f, iY);

		iY += 30;
	}
}

void CMenu::SelectNext()
{
	m_vpMenuItem[m_iSelected]->SetSelected(false);

	m_iSelected = (m_iSelected + 1) % m_vpMenuItem.size();
	m_vpMenuItem[m_iSelected]->SetSelected(true);
}

void CMenu::SelectPrev()
{
	m_vpMenuItem[m_iSelected]->SetSelected(false);

	--m_iSelected;
	if (m_iSelected < 0)
		m_iSelected = m_vpMenuItem.size() - 1;
	else
		m_iSelected %= m_vpMenuItem.size();
	m_vpMenuItem[m_iSelected]->SetSelected(true);
}

int CMenu::GetSelected()
{
	return m_iSelected;
}