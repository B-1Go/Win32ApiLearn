#pragma once
#include "pch.h"

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����
//class CCore
//{
//private:
//	static CCore* g_pInst;
//
//public:
//	// ���� ��� �Լ�
//	static CCore* GetInstance()
//	{
//		// ���� ȣ��� ���
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

// �̱��� ������ ������ ������ �ø��� ������� ����
class CCore
{
public:
	//static CCore* GetInst()
	//{
	//	static CCore core; // �����Ϳ����� ���� ��ٸ� ���ο� core ��ü�� ����°� �ƴ϶� ������ core ��ü�� ����Ų��.
	//	return &core; // ���� �����Ϳ����� ���� ��ٸ� �ּҸ� �����ϴ� ������ �����Ѵ�.
	//}
	// 1. static Ư���� �ѹ� �����Ǹ� ������ ������ �����Ƿ� �ٽ� ����ȣ���� �ص� ���õȴ�.
	// 2. static �� �ش� ��ü�Ǵ� Class�θ� ������ �����ѵ� �ּҰ��� ��Ե� �˾Ƴ��� ������ó�� ����� �����ϴ�.
	// 3. static CCore core ��, ����ƽ ��ü �̹Ƿ� ������ �Ű澵 �ʿ䰡 ����. (�ݴ�� ���ϴ¶��� ������ ���Ѵ�)
	SINGLE(CCore);
private:
	HWND m_hWnd; // ���� ������ �ڵ�
	POINT m_ptResolution; // ���� ������ �ػ�

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	CCore();
	~CCore();
};

