#include "StdAfx.h"
#include "ContrabandCard.h"

namespace Domlib
{

ContrabandCard::ContrabandCard(void)
    : Card( 
        L"Contraband",
        CARDID_CONTRABAND,
        CARDTYPE_TREASURE,
        3,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

ContrabandCard::~ContrabandCard(void)
{
}

Treasure ContrabandCard::OnTreasurePhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusBuys( 1 );

    Player* pPlayerToLeft = pEngine->GetNextPlayer( pPlayer );
    IAI* pAI = pPlayerToLeft->GetAI();
    Card*   pContrabandCard = pAI->OnContraband();

    pEngine->SetContrabandCard( pContrabandCard );
    
    return m_TreasureValue;
}

void ContrabandCard::OnCleanUpPhase( Engine* pEngine )
{
    pEngine->ClearContrabandCards();
}

} // namespace Domlib