#include "pch.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CkeyMgr.h"
#include "CTimeMgr.h"

#include "CMissile.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"

CPlayer::CPlayer()
	: m_pTex(nullptr)
{
	// Texture 로딩하기
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\player.bmp");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 15.f));
	GetCollider()->SetScale(Vec2(30.f, 35.f));
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}

	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}

	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}

	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeigth = (int)m_pTex->Heigth();

	Vec2 vPos = GetPos();

	int(vPos.x - (float)(iWidth / 2));
	int(vPos.y - (float)(iHeigth / 2));

	// BitBlt(_dc, int(vPos.x - (float)(iWidth / 2)), int(vPos.y - (float)(iHeigth / 2)), iWidth, iHeigth, m_pTex->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_dc, int(vPos.x - (float)(iWidth / 2)), int(vPos.y - (float)(iHeigth / 2)), iWidth, iHeigth, m_pTex->GetDC(), 0, 0, iWidth, iHeigth, RGB(255, 0, 255));

	// 컴포넌트(충돌체, etc...)
	component_render(_dc);
}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	// Missile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(Vec2(0.f, -1.f));

 	CreateObject(pMissile, GROUP_TYPE::PROJ_PLAYER);
}


