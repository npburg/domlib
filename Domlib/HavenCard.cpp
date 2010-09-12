#include "StdAfx.h"
#include "HavenCard.h"

namespace Domlib
{

HavenCard::HavenCard( void )
    : Card( 
        L"Haven",
        CARDID_HAVEN,
        CARDTYPE_ACTION_DURATION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

HavenCard::~HavenCard( void )
{
}

void HavenCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    
    Card* pCard = pAi->OnHaven();
    if( pPlayer->IsCardInHand( pCard ) )
    {
        pPlayer->PutCardInHaven( pCard );
    }
    else
    {
        //TODO: report error
        throw std::wstring( L"Error: HavenCard::OnActionPhase" );
    }
}

void HavenCard::OnDurationPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    Card* pCard = pPlayer->TakeCardFromHaven();
    
    pPlayer->PutCardInHand( pCard );    
}

} // namespace Domlib