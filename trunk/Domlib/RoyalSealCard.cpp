#include "StdAfx.h"
#include "RoyalSealCard.h"

namespace Domlib
{

RoyalSealCard::RoyalSealCard(void)
    : Card( 
        L"Royal Seal",
        CARDID_ROYALSEAL,
        CARDTYPE_TREASURE,
        0,
        Treasure( 2, 0 ),
        Treasure( 5, 0 ) )
{
}

RoyalSealCard::~RoyalSealCard(void)
{
}

Treasure RoyalSealCard::OnTreasurePhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusRoyalSeal();
    
    return m_TreasureValue;
}

void RoyalSealCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->MinusRoyalSeal();
}

} // namespace Domlib