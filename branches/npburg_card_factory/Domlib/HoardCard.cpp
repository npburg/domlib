#include "StdAfx.h"
#include "HoardCard.h"

namespace Domlib
{

HoardCard::HoardCard(void)
    : Card( 
        L"Hoard",
        CARDID_HOARD,
        CARDTYPE_TREASURE,
        2,
        Treasure( 0, 0 ),
        Treasure( 6, 0 ) )
{
}

HoardCard::~HoardCard(void)
{
}

void HoardCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int numVictoryCardsBought = pPlayer->CardsBought( CARDTYPE_VICTORY );
    
    for( int i = 0; i < numVictoryCardsBought; i++ )
    {
        pPlayer->GainCardOnDiscard( CARDID_GOLD );
    }    
}

} // namespace Domlib