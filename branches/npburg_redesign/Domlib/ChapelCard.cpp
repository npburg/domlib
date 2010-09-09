#include "StdAfx.h"
#include "ChapelCard.h"

namespace Domlib
{

ChapelCard::ChapelCard( void )
    : Card( 
        L"Chapel",
        CARDID_CHAPEL,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

ChapelCard::~ChapelCard( void )
{
}

void ChapelCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    AI* pAi = pPlayer->GetAI();
    ICardList cardsToTrash;

    cardsToTrash = pAi->OnChapel();
    if( pPlayer->AreCardsInHand( cardsToTrash ) )
    {
        pPlayer->TrashFromHand( cardsToTrash );
    }
    else
    {
        // TODO: Add error
        throw std::wstring( L"Error: ChapelCard::OnActionPhase" );
    }
}

} // namespace Domlib