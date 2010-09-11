#include "StdAfx.h"
#include "ApprenticeCard.h"

namespace Domlib
{

ApprenticeCard::ApprenticeCard( void )
    : Card( 
        L"Apprentice",
        CARDID_APPRENTICE,
        CARDTYPE_ACTION,
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
    IAI* pAi = pPlayer->GetAI();
    Card* pCardToTrash = pAi->OnApprentice();

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