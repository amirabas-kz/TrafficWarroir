#pragma once

#include "CMenuItem.h"
#include <vector>

class CMenu
{
public:
	CMenu();

	void Draw(Graphics* pGraphic);

	void SelectNext();
	void SelectPrev();

	int GetSelected();

private:
	int m_iSelected;
	std::vector<CMenuItem*> m_vpMenuItem;
};