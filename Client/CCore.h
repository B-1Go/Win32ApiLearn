#pragma once
#include "pch.h"

class CCore
{
public:
	SINGLE(CCore);
private:
	HWND m_hWnd; // ���� ������ �ڵ�
	POINT m_ptResolution; // ���� ������ �ػ�
	HDC m_hDC; // ���� �����쿡 Draw�� DC

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();
};
