#include "StdAfx.h"
#include "SwindlerCard.h"

namespace Domlib
{

SwindlerCard::SwindlerCard( void )
    : Card( 
        L"Swindler",
        CARDID::SWINDLER,
        CARDTYPE::ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

SwindlerCard::~SwindlerCard( void )
{
}

void SwindlerCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoins( 2 );

    Attack( pEngine, AttackWhom::OTHERS );
}

void SwindlerCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    Card* pCardTrashed = pPlayer->TrashCardFromDeck();

    if( pCardTrashed->IsNullCard() )
    {
        // Do nothing
    }
    else
    {
        Player* pAttackingPlayer = pEngine->GetCurrentPlayer();
        IAI* pAttackingAi = pAttackingPlayer->GetAI();
        Card* pCardGained = pAttackingAi->OnSwindler( pCardTrashed );

        if( pCardTrashed->Cost( pEngine ) == pCardGained->Cost( pEngine ) ||
            pCardGained->IsNullCard() )
        {
            pPlayer->PutCardInDiscard( pCardGained );
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: SwindlerCard::OnAttack" );
        }
    }
}

} // namespace Domlib