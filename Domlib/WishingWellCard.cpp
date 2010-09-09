#include "StdAfx.h"
#include "WishingWellCard.h"

namespace Domlib
{

WishingWellCard::WishingWellCard( void )
    : Card( 
        L"WishingWell",
        CARDID_WISHINGWELL,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

WishingWellCard::~WishingWellCard( void )
{
}

void WishingWellCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    AI* pAi = pPlayer->GetAI();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );

    ICard* pCardToWishFor = pAi->OnWishingWell();
    ICard* pCardRevealed = pPlayer->RevealCardFromDeck();

    if(  pCardRevealed->CardId() == pCardToWishFor->CardId() )
    {
        pPlayer->PutCardInHand( pCardRevealed );
    }
    else
    {
        pPlayer->PutCardOnDraw( pCardRevealed );
    }
}

} // namespace Domlib