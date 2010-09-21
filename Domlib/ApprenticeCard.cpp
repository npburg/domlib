#include "StdAfx.h"
#include "ApprenticeCard.h"

namespace Domlib
{

ApprenticeCard::ApprenticeCard( void )
    : Card( 
        L"Apprentice",
        CARDID::APPRENTICE,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

ApprenticeCard::~ApprenticeCard( void )
{
}

void ApprenticeCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    Card* pCardToTrash = pAI->OnApprentice();

    if( pPlayer->IsCardInHand( pCardToTrash ) )
    {
        pPlayer->TrashFromHand( pCardToTrash );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: ApprenticeCard::OnActionPhase" );
    }

    Treasure cost = pCardToTrash->Cost( pEngine );
    int numCardsToDraw = cost.Coins() + ( ( cost.Potions() ) ? 2 : 0 );

    pPlayer->DrawCardsToHand( numCardsToDraw );

}

} // namespace Domlib