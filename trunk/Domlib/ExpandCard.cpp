#include "StdAfx.h"
#include "ExpandCard.h"

namespace Domlib
{

ExpandCard::ExpandCard(void)
    : Card( 
        L"Expand",
        CARDID::EXPAND,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 7, 0 ) )
{
}

ExpandCard::~ExpandCard(void)
{
}

void ExpandCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    Card* pCardToTrash = pAI->OnExpand();
    
    if( pPlayer->IsCardInHand( pCardToTrash ) )
    {
        pPlayer->TrashFromHand( pCardToTrash );
        Treasure cost = pCardToTrash->Cost( pEngine ) + Treasure( 3, 0 );
        pPlayer->OnGainACard( &cost );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: ExpandCard::OnActionPhase" );
    }
}

} // namespace Domlib