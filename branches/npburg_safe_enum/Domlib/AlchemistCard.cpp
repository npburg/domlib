#include "StdAfx.h"
#include "AlchemistCard.h"

namespace Domlib
{

AlchemistCard::AlchemistCard( void )
    : Card( 
        L"Alchemist",
        CARDID::ALCHEMIST,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 1 ) )
{
}

AlchemistCard::~AlchemistCard( void )
{
}

void AlchemistCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 2 );
    pPlayer->PlusActions( 1 );
}

void AlchemistCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    if( pPlayer->IsCardInPlay( CARDID::POTION ) )
    {
        AlchemistOpt alchemistOpt = pAI->OnAlchemist();
        
        switch( alchemistOpt.underlying() )
        {
        case AlchemistOpt::DISCARD:
            // Do nothing, the card will be cleaned up as normal.
            break;
        case AlchemistOpt::PUT_BACK:
            pPlayer->TakeCardFromInPlay( CARDID::ALCHEMIST );
            pPlayer->PutCardOnDraw( CARDID::ALCHEMIST );
            break;
        default:
            // TODO: report error
            throw std::wstring( L"Error: AlchemistCard::OnCleanUpPhase" );
            break;
        }
    }
    else
    {
        // Do nothing, the card will be cleaned up as normal.
    }
}

} // namespace Domlib