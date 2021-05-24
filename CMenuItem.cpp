#include "CMenuItem.h"

CMenuItem::CMenuItem(std::wstring title)
	: m_bSelected(false)
	, m_wsTitle(title)
	, m_Font(L"Arial", 10)
{
}

void CMenuItem::Draw(Graphics* pGraphic, int iX, int iY)
{
	SolidBrush  brush(Color(255, 120, 120, 120));
	SolidBrush  brushText(Color(255, 0, 0, 120));
	Pen      pen(Color(255, 0, 0, 255), 2.0f);
	Rect rect(iX, iY, 200, 30);

	if (m_bSelected)
		pGraphic->FillRectangle(&brush, rect);
	else
		pGraphic->DrawRectangle(&pen, rect);

	PointF      pointF(iX + 10, iY + 5);
	pGraphic->DrawString(m_wsTitle.c_str(), m_wsTitle.length(), &m_Font, pointF, &brushText);
}

void CMenuItem::SetSelected(bool bState)
{
	m_bSelected = bState;
}