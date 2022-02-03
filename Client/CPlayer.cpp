#include "pch.h"
#include "CPlayer.h"

#include "CkeyMgr.h"
#include "CTimeMgr.h"

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (CkeyMgr::GetInst()->GetKeyState(KEY::S) == KEY_STATE::HOLD)
	{
		vPos.y -= 200.f * fDT;
	}

	if (CkeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::HOLD)
	{
		vPos.y += 200.f * fDT;
	}

	if (CkeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		vPos.x -= 200.f * fDT;
	}

	if (CkeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		vPos.x += 200.f * fDT;
	}

	SetPos(vPos);
}
