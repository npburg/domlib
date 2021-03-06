#include "StdAfx.h"
#include "LibraryCard.h"

namespace Domlib
{

LibraryCard::LibraryCard( void )
    : Card( 
        L"Library",
        CARDID::LIBRARY,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

LibraryCard::~LibraryCard( void )
{
}

void LibraryCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    CardList revealedCardList;

    while( pPlayer->CardsInHand() < 7 )
    {
        Card* pRevealedCard = pPlayer->RevealCardFromDeck();
        if( pRevealedCard->IsActionCard() )
        {
            LibraryOpt libraryOpt = pAI->OnLibrary( pRevealedCard );
            switch( libraryOpt )
            {
            case LibraryOpt::DISCARD_ACTION_CARD:
                revealedCardList.push_back( pRevealedCard );
                break;
            case LibraryOpt::KEEP_ACTION_CARD:
                pPlayer->PutCardInHand( pRevealedCard );
                break;
            default:
                // TODO: report error
                throw std::wstring( L"Error: LibraryCard::OnActionPhase" );
                break;
            }
        }
        else
        {
            pPlayer->PutCardInHand( pRevealedCard );
        }
    }
}

} // namespace Domlib