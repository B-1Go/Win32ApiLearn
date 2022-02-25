#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:

public:
    virtual void update();
    virtual void render(HDC _dc);


private:
    void CreateMissile();

    CLONE(CPlayer);
public:
    CPlayer();

    // 컴파일러가 알아서 복사생성자를 만들어 주지만 직접 구현을 해보자면 아래와 같이 만들어 질 것이다.
    /*CPlayer(const CPlayer& _origin)
        : CObject(_origin)
        , m_pTex(_origin.m_pTex)
    {}*/

    ~CPlayer();
};

