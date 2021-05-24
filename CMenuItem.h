#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

#include <string>

class CMenuItem
{
public:
	CMenuItem(std::wstring title);

	void Draw(Graphics* pGraphic, int iX, int iY);

	void SetSelected(bool bState);

private:
	bool m_bSelected;
	std::wstring m_wsTitle;
	Font m_Font;
};