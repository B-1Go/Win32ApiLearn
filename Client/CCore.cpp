#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CkeyMgr.h"
#include "CObject.h"

CObject g_obj;

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt = {0, 0, _ptResolution.x, _ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	// Manager �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CkeyMgr::GetInst()->init();

	g_obj.SetPos(Vec2((float)(_ptResolution.x / 2), (float)(_ptResolution.y / 2)));
	g_obj.SetScale(Vec2(100, 100));

	return S_OK;
}

void CCore::progress()
{
	update();

	render();
}

void CCore::update()
{
	Vec2 vPos = g_obj.GetPos();

	// �񵿱� �Է� �ޱ�
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 0.01f;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 0.01f;
	}
	
	g_obj.SetPos(vPos);
}

void CCore::render()
{
	// �׸���
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_hDC, int(vPos.x - vScale.x / 2.f)
				   , int(vPos.y - vScale.y / 2.f)
				   , int(vPos.x + vScale.x / 2.f)
				   , int(vPos.y + vScale.y / 2.f));
}