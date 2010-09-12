#include "StdAfx.h"
#include "GoonsCard.h"

namespace Domlib
{

GoonsCard::GoonsCard(void)
    : Card( 
        L"Goons",
        CARDID_GOONS,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 6, 0 ) )
{
}

GoonsCard::~GoonsCard(void)
{
}

void GoonsCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( 2 );

    Attack( pEngine, ATTACK_OTHERS );
}

void GoonsCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    IAI* pAI = pPlayer->GetAI();
    CardList cardsToDiscard;
    
    cardsToDiscard = pAI->OnGoons();
    if( pPlayer->AreCardsInHand( cardsToDiscard ) )
    {
        pPlayer->DiscardFromHand( cardsToDiscard );

        if( pPlayer->CardsInHand() > 3 )
        {
            // TODO: report error
            throw std::wstring( L"Error: GoonsCard::OnAttack" );
        }        
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: GoonsCard::OnAttack" );
    }
}

void GoonsCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusVictoryTokens( 1 );
}

} // namespace Domlib