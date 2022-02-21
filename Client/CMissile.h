#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float m_fTheta; // 이동 방향 각도 (라디안, 호도법)

    Vec2 m_vDir; // 이동 방향 벡터

public:
    void SetDir(bool _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir) { (m_vDir = _vDir).normalize(); }

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    virtual void OnCollisionEnter(CCollider* _pOther);

public:
    CMissile();
    ~CMissile();
};

