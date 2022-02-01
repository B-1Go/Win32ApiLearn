#pragma once


class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);
private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END]; // ��� �� ���
	CScene* m_pCurScene; // ���� ��

public:
	void init();

public:
	CSceneMgr();
	virtual ~CSceneMgr();

	// ��Ӹ� �ϴ� �θ�Ŭ�������� �ݵ�� �Ҹ��ڿ� virtual ����� ��ӹ��� �ڽ�Ŭ�������� �Ҹ��ڰ� ȣ���� �ȴ�.
};

