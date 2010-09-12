#include "StdAfx.h"
#include "TreasuryCard.h"

namespace Domlib
{

TreasuryCard::TreasuryCard( void )
    : Card( 
        L"Treasury",
        CARDID_TREASURY,
        CARDTYPE_ACTION,
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
    IAI* pAi = pPlayer->GetAI();

    if( pPlayer->IsCardInBuyList( CARDTYPE_VICTORY ) )
    {
        TreasuryOpt treasuryOpt = pAi->OnTreasury();
        
        switch( treasuryOpt )
        {
        case Domlib::TREASURY_DISCARD:
            // Do nothing
            break;
        case Domlib::TREASURY_PUT_BACK:
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