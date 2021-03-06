#include "StdAfx.h"
#include "TreasuryCard.h"

namespace Domlib
{

TreasuryCard::TreasuryCard( void )
    : Card( 
        L"Treasury",
        CARDID::TREASURY,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

TreasuryCard::~TreasuryCard( void )
{
}

void TreasuryCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    pPlayer->PlusCoins( 1 );
}

void TreasuryCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    if( pPlayer->IsCardInBuyList( CARDTYPE::VICTORY ) )
    {
        TreasuryOpt treasuryOpt = pAI->OnTreasury();
        
        switch( treasuryOpt )
        {
        case Domlib::TreasuryOpt::DISCARD:
            // Do nothing
            break;
        case Domlib::TreasuryOpt::PUT_BACK:
            pPlayer->TakeCardFromInPlay( this );
            pPlayer->PutCardOnDraw( this );
            break;
        default:
            // TODO: report error
            throw std::wstring( L"Error: TreasuryCard::OnCleanUpPhase" );
            break;
        }
    }
}

} // namespace Domlib