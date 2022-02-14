#include "pch.h"
#include "CCollider.h"

#include "CCore.h"
#include "CObject.h"

#include "SelectGDI.h"

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_vFinalPos()
	, m_vOffsetPos()
{
}

CCollider::~CCollider()
{
	if (nullptr != m_pOwner)
	{
		delete m_pOwner;
	}
}

void CCollider::finalupdate()
{
	// Object의 위치를 따라감
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

void CCollider::rneder(HDC _dc)
{
	SelectGDI p(_dc, PEN_TYPE::GREEN);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		, (int)(m_vFinalPos.x - m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y - m_vScale.y / 2.f)
		, (int)(m_vFinalPos.x + m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y + m_vScale.y / 2.f));
}
