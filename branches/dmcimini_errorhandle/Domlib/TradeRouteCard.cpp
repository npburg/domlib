#include "StdAfx.h"
#include "TradeRouteCard.h"

namespace Domlib
{

TradeRouteCard::TradeRouteCard(void)
    : Card( 
        L"Trade Route",
        CARDID_TRADEROUTE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

TradeRouteCard::~TradeRouteCard(void)
{
}

void TradeRouteCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( pEngine->TradeTokens() );
    
    if( pPlayer->CardsInHand() )
    {
        IAI* pAI = pPlayer->GetAI();
        Card* pCardToTrash = pAI->OnTrashCardFromHand();
        
        if( pPlayer->IsCardInHand( pCardToTrash ) )
        {
            pPlayer->TrashFromHand( pCardToTrash );
        }
    }
}

} // namespace Domlib