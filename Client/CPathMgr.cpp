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

	// 문자열길이
	int iLen = wcslen(m_szContentPath);

	// 상위폴더로
	for (int i = iLen; 0 <= i; --i)
	{
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");

	// SetWindowText(CCore::GetInst()->GetMainHwnd(), m_szContentPath);
}
