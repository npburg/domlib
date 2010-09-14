#include "StdAfx.h"
#include "GardensCard.h"

namespace Domlib
{

GardensCard::GardensCard( void )
    : Card( 
        L"Gardens",
        CARDID_GARDENS,
        CARDTYPE_VICTORY,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

GardensCard::~GardensCard( void )
{
}

int GardensCard::OnScoring( Engine* pEngine ) const
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int deckSize = pPlayer->GetDeckSize();

    return (int)(deckSize / 10);
}



} // namespace Domlib