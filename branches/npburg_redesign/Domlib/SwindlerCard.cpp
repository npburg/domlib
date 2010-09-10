#include "StdAfx.h"
#include "SwindlerCard.h"

namespace Domlib
{

SwindlerCard::SwindlerCard( void )
    : Card( 
        L"Swindler",
        CARDID_SWINDLER,
        CARDTYPE_ACTION_ATTACK,
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

    Attack( pEngine, ATTACK_OTHERS );
}

void SwindlerCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    ICard* pCardTrashed = pPlayer->TrashFromDeck();

    if( pCardTrashed->IsNullCard() )
    {
        // Do nothing
    }
    else
    {
        Player* pAttackingPlayer = pEngine->GetCurrentPlayer();
        AI* pAttackingAi = pAttackingPlayer->GetAI();
        ICard* pCardGained = pAttackingAi->OnSwindler( 
            pCardTrashed->Cost( pEngine ) );

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