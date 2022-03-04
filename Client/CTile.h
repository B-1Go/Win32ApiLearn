#pragma once

#include "CObject.h"

class CTexture;

class CTile :
    public CObject
{
private:
    CTexture* m_pTileTex;
    int m_iIdx;

public:
    void SetTexture(CTexture* _pTex)
    {
        m_pTileTex = _pTex;
    }

private:
    void virtual update();
    void virtual render(HDC _dc);

    CLONE(CTile);
public:
    CTile();
    ~CTile();
};

