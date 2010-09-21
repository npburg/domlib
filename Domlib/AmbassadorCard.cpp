#include "StdAfx.h"
#include "AmbassadorCard.h"

namespace Domlib
{

AmbassadorCard::AmbassadorCard( void )
    : Card( 
        L"Ambassador",
        CARDID::AMBASSADOR,
        CARDTYPE::ACTION_ATTACK,
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
    IAI* pAI = pPlayer->GetAI();

    Card* pRevealedCard = pAI->OnAmbassadorReveal();
    if( !pPlayer->IsCardInHand( pRevealedCard ) )
    {
        // TODO: report error.
        throw std::wstring( L"Error: AmbassadorCard::OnActionPhase" );
    }
    
    int numToPutBack = pAI->OnAmbassadorPutBack( pRevealedCard );
    
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
    Attack( pEngine, AttackWhom::OTHERS );
    pEngine->SetAmbassadorCard( Card::GetCard( CARDID::NULLCARD ) );
}

void AmbassadorCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    pPlayer->GainCardOnDiscard( pEngine->GetAmbassadorCard() );
}

} // namespace Domlib