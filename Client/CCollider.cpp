#include "pch.h"
#include "CCollider.h"

#include "CObject.h"

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

}
