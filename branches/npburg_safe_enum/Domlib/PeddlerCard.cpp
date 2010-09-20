#include "StdAfx.h"
#include "PeddlerCard.h"

namespace Domlib
{

PeddlerCard::PeddlerCard(void)
    : Card( 
        L"Peddler",
        CARDID::PEDDLER,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 8, 0 ) )
{
}

PeddlerCard::~PeddlerCard(void)
{
}

void PeddlerCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    pPlayer->PlusCoins( 1 );
}

Treasure PeddlerCard::Cost( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int numActionCardsInPlay = pPlayer->CardsInPlay( CARDTYPE::ACTION );
    int coins = std::max( m_TreasureValue.Coins() - ( 2 * numActionCardsInPlay), 0 );
    
    return Treasure( coins, 0 );
}

} // namespace Domlib