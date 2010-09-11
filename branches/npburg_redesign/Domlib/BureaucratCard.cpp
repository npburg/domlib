#include "StdAfx.h"
#include "BureaucratCard.h"

namespace Domlib
{

BureaucratCard::BureaucratCard( void )
    : Card( 
        L"Bureaucrat",
        CARDID_BUREAUCRAT,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

BureaucratCard::~BureaucratCard( void )
{
}

void BureaucratCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->GainCardOnDeck( CARDID_SILVER );
    Attack( pEngine, ATTACK_OTHERS );
}

void BureaucratCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    IAI* pAi = pPlayer->GetAI();
    Card* pVictoryCard = pAi->OnBureaucrat();
    
    if( pVictoryCard->IsVictoryCard() &&
        pPlayer->IsCardInHand( pVictoryCard ) )
    {
        pPlayer->DiscardFromHandToDrawPile( pVictoryCard );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: BureaucratCard::OnAttack()" );
    }
}

} // namespace Domlib