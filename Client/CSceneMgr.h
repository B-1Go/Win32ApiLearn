#pragma once


class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);
private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END]; // 모든 씬 목록
	CScene* m_pCurScene; // 현재 씬

public:
	void init();

public:
	CSceneMgr();
	virtual ~CSceneMgr();

	// 상속만 하는 부모클래스에서 반드시 소멸자에 virtual 해줘야 상속받은 자식클래스까지 소멸자가 호출이 된다.
};

