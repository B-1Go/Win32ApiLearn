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
	GetCurrentDirectory(255, m_szContentPath); // exe 실행되면 실행된 자신의 위치를 저장하는데 그 정보를 Get하는 함수

	// 상위폴더로

	// + bin\content\



	//SetWindowText(CCore::GetInst()->GetMainHwnd(), m_szContentPath);
}
