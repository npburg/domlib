#include "StdAfx.h"
#include "SecretChamberCard.h"

namespace Domlib
{

SecretChamberCard::SecretChamberCard( void )
    : Card( 
        L"Secret Chamber",
        CARDID_SECRETCHAMBER,
        CARDTYPE_ACTION_REACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

SecretChamberCard::~SecretChamberCard( void )
{
}

void SecretChamberCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    AI* pAi = pPlayer->GetAI();
    ICardList cardsToDiscard = pAi->OnSecretChamber();

    if( pPlayer->AreCardsInHand( cardsToDiscard ) )
    {
        pPlayer->PlusCoins( cardsToDiscard.size() );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: SecretChamberCard::OnActionPhase" );
    }
}

void SecretChamberCard::OnReaction( Engine* pEngine, Player* pPlayer )
{
    pPlayer->DrawCardsToHand( 2 );
    
    AI* pAi = pPlayer->GetAI();
    ICardList cardsToPutBack = pAi->OnSecretChamberReaction();

    if( pPlayer->AreCardsInHand( cardsToPutBack ) )
    {
        pPlayer->PutCardsOnDraw( cardsToPutBack );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: SecretChamberCard::OnReaction" );
    }
}

} // namespace Domlib