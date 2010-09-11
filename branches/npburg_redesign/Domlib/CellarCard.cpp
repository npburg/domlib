#include "StdAfx.h"
#include "CellarCard.h"

namespace Domlib
{

CellarCard::CellarCard( void ) 
    : Card( 
        L"Cellar",
        CARDID_CELLAR,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

CellarCard::~CellarCard( void )
{
}

void CellarCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    CardList cardsToDiscard;

    cardsToDiscard = pAi->OnCellar();
    if( pPlayer->AreCardsInHand( cardsToDiscard ) )
    {
        pPlayer->DiscardFromHand( cardsToDiscard );
        pPlayer->DrawCardsToHand( cardsToDiscard.size() );
    }
    else
    {
        // TODO: Add error
        throw std::wstring( L"Error: CellarCard::OnActionPhase()" );
    }
}

} // namespace Domlib