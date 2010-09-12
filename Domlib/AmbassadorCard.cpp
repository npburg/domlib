#include "StdAfx.h"
#include "AmbassadorCard.h"

namespace Domlib
{

AmbassadorCard::AmbassadorCard( void )
    : Card( 
        L"Ambassador",
        CARDID_AMBASSADOR,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

AmbassadorCard::~AmbassadorCard( void )
{
}

void AmbassadorCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();

    Card* pRevealedCard = pAi->OnAmbassadorReveal();
    if( !pPlayer->IsCardInHand( pRevealedCard ) )
    {
        // TODO: report error.
        throw std::wstring( L"Error: AmbassadorCard::OnActionPhase" );
    }
    
    int numToPutBack = pAi->OnAmbassadorPutBack( pRevealedCard );
    
    if( pPlayer->CardsInHand( pRevealedCard ) < numToPutBack )
    {
        // TODO: report error.
        throw std::wstring( L"Error: AmbassadorCard::OnActionPhase" );
    }
    
    for( int i = 0; i < numToPutBack; i++ )
    {
        pPlayer->TakeCardFromHand( pRevealedCard );
        pEngine->PutCardInSupply( pRevealedCard );
    }
    
    pEngine->SetAmbassadorCard( pRevealedCard );
    Attack( pEngine, ATTACK_OTHERS );
    pEngine->SetAmbassadorCard( Card::GetCard( CARDID_NULL ) );
}

void AmbassadorCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    pPlayer->GainCardOnDiscard( pEngine->GetAmbassadorCard() );
}

} // namespace Domlib