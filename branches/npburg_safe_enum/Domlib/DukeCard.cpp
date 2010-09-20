#include "StdAfx.h"
#include "DukeCard.h"

namespace Domlib
{

DukeCard::DukeCard( void )
    : Card( 
        L"Duke",
        CARDID::DUKE,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

DukeCard::~DukeCard( void )
{
}

int DukeCard::OnScoring( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int numDuchies = pPlayer->GetCardCountInDeckId( CARDID::DUCHY );
    return ( int )( numDuchies / 5 );
}

} // namespace Domlib