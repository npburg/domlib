#include "StdAfx.h"
#include "TradingPostCard.h"

namespace Domlib
{

TradingPostCard::TradingPostCard( void )
    : Card( 
        L"Trading Post",
        CARDID_TRADINGPOST,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

TradingPostCard::~TradingPostCard( void )
{
}

void TradingPostCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    CardList cardsToTrash = pAi->OnTradingPost();

    if( cardsToTrash.size() == 2 &&
        pPlayer->AreCardsInHand( cardsToTrash ) )
    {
        pPlayer->TrashFromHand( cardsToTrash );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: TradingPost::OnActionPhase" );
    }
}

} // namespace Domlib