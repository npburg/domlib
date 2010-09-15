#include "StdAfx.h"
#include "BishopCard.h"

namespace Domlib
{

BishopCard::BishopCard(void)
    : Card( 
        L"Bishop",
        CARDID_BISHOP,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

BishopCard::~BishopCard(void)
{
}

void BishopCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->PlusCoins( 1 );
    pPlayer->PlusVictoryTokens( 1 );
    
    if( pPlayer->CardsInHand() )
    {
        IAI* pAI = pPlayer->GetAI();
        Card* pCard = pAI->OnBishopSelf();
    
        if( pPlayer->IsCardInHand( pCard ) )
        {
            pPlayer->TrashFromHand( pCard );
            pPlayer->PlusVictoryTokens( (int)( pCard->Cost( pEngine ).Coins() / 2 ) );
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: BishopCard::OnActionPhase" );
        }
    }
    
    ActionForOthers( pEngine );
}

void BishopCard::OnActionPhaseOther( Engine* pEngine, Player* pPlayer )
{
    if( pPlayer->CardsInHand() )
    {
        IAI* pAI = pPlayer->GetAI();
        Card* pCard = pAI->OnBishopOther();
    
        if( pPlayer->IsCardInHand( pCard ) )
        {
            pPlayer->TrashFromHand( pCard );
        }
        else if( pCard->IsNullCard() )
        {
            // Do nothing
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: BishopCard::OnActionPhase" );
        }
    }
}

} // namespace Domlib