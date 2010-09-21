#include "StdAfx.h"
#include "WatchtowerCard.h"

namespace Domlib
{

WatchtowerCard::WatchtowerCard(void)
    : Card( 
        L"Watchtower",
        CARDID::WATCHTOWER,
        CARDTYPE::ACTION_REACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

WatchtowerCard::~WatchtowerCard(void)
{
}

void WatchtowerCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int numCardsToDraw = 6 - pPlayer->CardsInHand();
    
    if( numCardsToDraw > 0 )
    {
        pPlayer->DrawCardsToHand( numCardsToDraw );
    }
}

void WatchtowerCard::OnReaction( Engine* pEngine, Player* pPlayer )
{
    // TODO: implement the reaction
    throw std::wstring( L"WatchtowerCard::OnReaction - To be implemented..." );
}

} // namespace Domlib