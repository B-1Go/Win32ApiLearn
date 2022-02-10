#pragma once



class CPathMgr
{
	SINGLE(CPathMgr);
private:
	wchar_t m_szContentPath[255]; // 윈도우 디렉토리는 255로 제한 되있음

public:
	void init();
	const wchar_t* GetContentPath() { return m_szContentPath; }

};

