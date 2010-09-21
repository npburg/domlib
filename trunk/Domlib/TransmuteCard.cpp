#include "StdAfx.h"
#include "TransmuteCard.h"

namespace Domlib
{

TransmuteCard::TransmuteCard( void )
    : Card( 
        L"Transmute",
        CARDID::TRANSMUTE,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 0, 1 ) )
{
}

TransmuteCard::~TransmuteCard( void )
{
}

void TransmuteCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    Card* pCardToTrash = pAI->OnTransmute();

    if( pPlayer->IsCardInHand( pCardToTrash ) )
    {
        pPlayer->TrashFromHand( pCardToTrash );
        
        if( pCardToTrash->IsActionCard() )
        {
            pPlayer->GainCardOnDiscard( CARDID::DUCHY );
        }

        if( pCardToTrash->IsTreasureCard() )
        {
            pPlayer->GainCardOnDiscard( CARDID::TRANSMUTE );
        }

        if( pCardToTrash->IsVictoryCard() )
        {
            pPlayer->GainCardOnDiscard( CARDID::GOLD );
        }
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: TransmuteCard::OnActionPhase" );
    }
}

} // namespace Domlib