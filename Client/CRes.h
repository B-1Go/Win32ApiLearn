#pragma once




class CRes
{
private:
	wstring m_strKey;		   // ���ҽ� Ű
	wstring m_strRelativePath; // ���ҽ� �����


public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = _strPath; }


public:
	CRes();
	~CRes();
};

