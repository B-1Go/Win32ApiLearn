#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float m_fTheta; // 이동 방향 (각도)

public:
    void SetDir(bool _fTheta)
    {
        m_fTheta = _fTheta;
    }

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    CMissile();
    ~CMissile();
};

