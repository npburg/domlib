#include "stdafx.h"
#include "DomAIDLL.h"

DOMAIDLL_API bool CreateAI( Domlib::AI* &pAI )
{
    pAI = NULL;

    return true;
}

DOMAIDLL_API bool DestroyAI( Domlib::AI* &pAI )
{
    pAI = NULL;

    return true;
}
