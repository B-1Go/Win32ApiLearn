#include "pch.h"
#include "CPathMgr.h"

#include "CCore.h"

CPathMgr::CPathMgr()
	: m_szContentPath{}
{}

CPathMgr::~CPathMgr()
{}

void CPathMgr::init()
{
	GetCurrentDirectory(255, m_szContentPath); // exe ����Ǹ� ����� �ڽ��� ��ġ�� �����ϴµ� �� ������ Get�ϴ� �Լ�

	// ����������

	// + bin\content\



	//SetWindowText(CCore::GetInst()->GetMainHwnd(), m_szContentPath);
}
