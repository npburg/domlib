#include "StdAfx.h"
#include "SaboteurCard.h"

namespace Domlib
{

SaboteurCard::SaboteurCard( void )
    : Card( 
        L"Saboteur",
        CARDID::SABOTEUR,
        CARDTYPE::ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

SaboteurCard::~SaboteurCard( void )
{
}

void SaboteurCard::OnActionPhase( Engine* pEngine )
{
    Attack( pEngine, AttackWhom::OTHERS );
}

void SaboteurCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    IAI* pAI = pPlayer->GetAI();
    Card* pCardRevealed = pPlayer->RevealCardFromDeck();
    CardList revealedCardList;

    while( pCardRevealed->Cost( pEngine ) < Treasure( 3, 0 ) ||
           pCardRevealed->IsNullCard() )
    {
        revealedCardList.push_back( pCardRevealed );
        pCardRevealed = pPlayer->RevealCardFromDeck();
    }
    revealedCardList.push_back( pCardRevealed );

    if( pCardRevealed->IsNullCard() )
    {
        // do nothing
    }
    else
    {
        pPlayer->TrashCard( pCardRevealed );
        Treasure cost = pCardRevealed->Cost( pEngine ) - Treasure( 2, 0 );
        pAI->OnGainACard( &cost );
    }

    pPlayer->PutCardsInDiscard( revealedCardList );
}

} // namespace Domlib