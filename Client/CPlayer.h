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

    // �����Ϸ��� �˾Ƽ� ��������ڸ� ����� ������ ���� ������ �غ��ڸ� �Ʒ��� ���� ����� �� ���̴�.
    /*CPlayer(const CPlayer& _origin)
        : CObject(_origin)
        , m_pTex(_origin.m_pTex)
    {}*/

    ~CPlayer();
};

