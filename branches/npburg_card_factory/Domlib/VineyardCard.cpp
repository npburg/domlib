#include "StdAfx.h"
#include "VineyardCard.h"

namespace Domlib
{

VineyardCard::VineyardCard( void )
    : Card( 
        L"Vineyard",
        CARDID_VINEYARD,
        CARDTYPE_TREASURE,
        0,
        Treasure( 0, 0 ),
        Treasure( 0, 1 ) )
{
}

VineyardCard::~VineyardCard( void )
{
}

int VineyardCard::OnScoring( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int numActionCardsInDeck = pPlayer->GetCardCountInDeckType( CARDTYPE_ACTION );
    return (int)( numActionCardsInDeck / 3 );
}

} // namespace Domlib