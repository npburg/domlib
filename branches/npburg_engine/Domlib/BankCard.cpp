#include "StdAfx.h"
#include "BankCard.h"

namespace Domlib
{

BankCard::BankCard(void)
    : Card( 
        L"Bank",
        CARDID::BANK,
        CARDTYPE::TREASURE,
        0,
        Treasure( 0, 0 ),
        Treasure( 7, 0 ) )
{
}

BankCard::~BankCard(void)
{
}

Treasure BankCard::OnTreasurePhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    return Treasure( pPlayer->CardsInPlay( CARDTYPE::TREASURE ), 0 );
}

} // namespace Domlib