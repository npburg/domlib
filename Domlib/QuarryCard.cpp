#include "StdAfx.h"
#include "QuarryCard.h"

namespace Domlib
{

QuarryCard::QuarryCard(void)
    : Card( 
        L"Quarry",
        CARDID_QUARRY,
        CARDTYPE_TREASURE,
        0,
        Treasure( 1, 0 ),
        Treasure( 4, 0 ) )
{
}

QuarryCard::~QuarryCard(void)
{
}

Treasure QuarryCard::OnTreasurePhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusQuarry();
    
    return m_TreasureValue;
}

void QuarryCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->MinusQuarry();
}

} // namespace Domlib