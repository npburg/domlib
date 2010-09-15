#include "StdAfx.h"
#include "VaultCard.h"

namespace Domlib
{

VaultCard::VaultCard(void)
    : Card( 
        L"Vault",
        CARDID_VAULT,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

VaultCard::~VaultCard(void)
{
}

void VaultCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    
    pPlayer->DrawCardsToHand( 2 );
    
    CardList cardsToDiscard = pAI->OnVaultSelf();
    
    if( pPlayer->AreCardsInHand( cardsToDiscard ) )
    {
        pPlayer->DiscardFromHand( cardsToDiscard );
        pPlayer->PlusCoins( cardsToDiscard.size() );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: VaultCard::OnActionPhase" );
    }
    
    ActionForOthers( pEngine );
}

void VaultCard::OnActionPhaseOther( Engine* pEngine, Player* pPlayer )
{
    if( pPlayer->CardsInHand() )
    {
        IAI* pAI = pPlayer->GetAI();
        CardList cardsToDiscard = pAI->OnVaultOther();
        
        if( cardsToDiscard.size() == 2 )
        {
            pPlayer->DrawCardsToHand( 1 );
            pPlayer->DiscardFromHand( cardsToDiscard );
        }
        else if( cardsToDiscard.size() == 1 &&
                 pPlayer->CardsInHand() == 1 )
        {
            pPlayer->DiscardFromHand( cardsToDiscard );
        }
        else if( cardsToDiscard.size() == 0 )
        {
            // Do nothing.
        }
        else
        {
            // TODO: report error.
            throw std::wstring( L"Error: VaultCard::OnActionPhaseOther" );
        }
    }
}

} // namespace Domlib