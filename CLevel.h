#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

#include "CCar.h"
#include "CBlock.h"
#include "CBullet.h"
#include "CMenu.h"

#include <list>


class CLevel
{
public:
	CLevel();

	int GetWidth() const;
	int GetHeight() const;

	// Use these three method
	void KeyDown(int iKey);
	void DrawAll(Graphics* pGraphic);

	void DeleteBlock(CBlock* pBlock);
	bool CheckCollision(CBullet* pBullet);

	bool IsMustExit();

private:
	int m_iWidth; // save width and height of screen
	int m_iHeight;

	CCar* m_pCar;

	std::list<CBlock*> m_lpBlocks;
	void CreateBlocks();
	std::list<CBlock*> m_lpForDelete;

	CMenu m_Menu;
	bool m_bShowMenu;
	bool m_bExitState;
};