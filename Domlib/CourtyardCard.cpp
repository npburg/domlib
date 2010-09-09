#include "StdAfx.h"
#include "CourtyardCard.h"

namespace Domlib
{

CourtyardCard::CourtyardCard( void )
    : Card( 
        L"Courtyard",
        CARDID_COURTYARD,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

CourtyardCard::~CourtyardCard( void )
{
}

void CourtyardCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    AI* pAi = pPlayer->GetAI();

    pPlayer->DrawCardsToHand( 3 );
    ICard* pCardToReturn = pAi->OnCourtyard();
    if( pPlayer->IsCardInHand( pCardToReturn ) )
    {
        pPlayer->PutCardOnDraw( pCardToReturn );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: CourtyardCard::OnActionPhase" );
    }
}

} // namespace Domlib