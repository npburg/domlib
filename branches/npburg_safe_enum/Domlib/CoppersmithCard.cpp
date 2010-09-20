#include "StdAfx.h"
#include "CoppersmithCard.h"

namespace Domlib
{

CoppersmithCard::CoppersmithCard( void )
    : Card( 
        L"Coppersmith",
        CARDID::COPPERSMITH,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

CoppersmithCard::~CoppersmithCard( void )
{
}

void CoppersmithCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoppersmith();
}

} // namespace Domlib