#include "StdAfx.h"
#include "MasqueradeCard.h"

namespace Domlib
{

MasqueradeCard::MasqueradeCard( void )
    : Card( 
        L"Masquerade",
        CARDID_MASQUERADE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

MasqueradeCard::~MasqueradeCard( void )
{
}

void MasqueradeCard::OnActionPhase( Engine* pEngine )
{
    Player* pCurrentPlayer = pEngine->GetCurrentPlayer();
    IAI* pCurrentAi = pCurrentPlayer->GetAI();

    pCurrentPlayer->DrawCardsToHand( 2 );
    
    Card* pCardToPass = pCurrentAi->OnMasqueradePass();
    
    if( pCurrentPlayer->IsCardInHand( pCardToPass ) )
    {
        pCurrentPlayer->TakeCardFromHand( pCardToPass );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: MasqueradeCard::OnActionPhase" );
    }

    Card* pCardToRecieve = pCardToPass;
    Player* pNextPlayer = pEngine->GetNextPlayer( pCurrentPlayer );

    while( pNextPlayer != pCurrentPlayer )
    {
        IAI* pNextAi = pNextPlayer->GetAI();
        pCardToPass = pNextAi->OnMasqueradePass();

        if( pNextPlayer->IsCardInHand( pCardToPass ) )
        {
            pNextPlayer->TakeCardFromHand( pCardToPass );
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: MasqueradeCard::OnActionPhase" );
        }

        pNextPlayer->PutCardInHand( pCardToRecieve );
        pCardToRecieve = pCardToPass;
        pNextPlayer = pEngine->GetNextPlayer( pNextPlayer );
    }

    pCurrentPlayer->PutCardInHand( pCardToRecieve );

    Card* pCardToTrash = pCurrentAi->OnMasqueradeTrash();
    
    if( pCurrentPlayer->IsCardInHand( pCardToTrash ) )
    {
        pCurrentPlayer->TrashFromHand( pCardToTrash );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error:  MasqueradeCard::OnActionPhase" );
    }
}

} // namespace Domlib