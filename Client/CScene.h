#pragma once

// 전방선언 (포인터 타입만 사용가능)
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // 오브젝트를 저장 및 관리할 벡터를 그룹 개수만큼 선언
	wstring m_strName; // Scene 이름

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void update();
	void finalupdate();
	void render(HDC _dc);

	// 순수 가상함수 1. 자식에서 start함수를 구현하지 않으면 객체가 생성 될 수 없다.  2. 부모가 Start함수로 객체를 만들 일이 없다.
	virtual void Enter() = 0; // 해당 Scene 에 진입 시 호출
	virtual void Exit() = 0; //  해당 Scene 에 탈출 시 호출


public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType)	{ return m_arrObj[(UINT)_eType]; }



public:
	CScene();
	~CScene();
};

