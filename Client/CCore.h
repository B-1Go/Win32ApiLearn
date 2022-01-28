#pragma once
#include "pch.h"

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능
//class CCore
//{
//private:
//	static CCore* g_pInst;
//
//public:
//	// 정적 멤버 함수
//	static CCore* GetInstance()
//	{
//		// 최초 호출된 경우
//		if (nullptr == g_pInst)
//		{
//			g_pInst = new CCore;
//		}
//		return g_pInst;
//	}
//
//	static void Release()
//	{
//		if (nullptr != g_pInst)
//		{
//			delete g_pInst;
//			g_pInst = nullptr;
//		}
//	}
//
//private:
//	CCore();
//	~CCore();
//};

// 싱글톤 이지만 데이터 영역에 올리는 방법으로 구현
class CCore
{
public:
	//static CCore* GetInst()
	//{
	//	static CCore core; // 데이터영역에 생성 됬다면 새로운 core 객체를 만드는게 아니라 생성된 core 객체를 가리킨다.
	//	return &core; // 따라서 데이터영역에 생성 됬다면 주소를 리턴하는 역할을 수행한다.
	//}
	// 1. static 특성상 한번 생성되면 데이터 영역에 있으므로 다시 생성호출을 해도 무시된다.
	// 2. static 은 해당 객체또는 Class로만 접근이 가능한데 주소값을 어떻게든 알아내면 포인터처럼 사용이 가능하다.
	// 3. static CCore core 즉, 스택틱 객체 이므로 해제에 신경쓸 필요가 없다. (반대로 원하는때에 해제를 못한다)
	SINGLE(CCore);
private:
	HWND m_hWnd; // 메인 윈도우 핸들
	POINT m_ptResolution; // 메인 윈도우 해상도

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	CCore();
	~CCore();
};

