#include "StdAfx.h"
#include "AlchemistCard.h"

namespace Domlib
{

AlchemistCard::AlchemistCard( void )
    : Card( 
        L"Alchemist",
        CARDID_ALCHEMIST,
        CARDTYPE_ACTION,
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
    AI* pAi = pPlayer->GetAI();

    if( pPlayer->IsCardInPlay( CARDID_POTION ) )
    {
        AlchemistOpt alchemistOpt = pAi->OnAlchemist();
        
        switch( alchemistOpt )
        {
        case ALCHEMIST_DISCARD:
            // Do nothing, the card will be cleaned up as normal.
            break;
        case ALCHEMIST_PUT_BACK:
            pPlayer->TakeCardFromInPlay( CARDID_ALCHEMIST );
            pPlayer->PutCardOnDraw( CARDID_ALCHEMIST );
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