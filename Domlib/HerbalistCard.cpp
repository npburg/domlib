#include "StdAfx.h"
#include "HerbalistCard.h"

namespace Domlib
{

HerbalistCard::HerbalistCard( void )
    : Card( 
        L"Herbalist",
        CARDID::HERBALIST,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

HerbalistCard::~HerbalistCard( void )
{
}

void HerbalistCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusBuys( 1 );
    pPlayer->PlusCoins( 1 );
}

void HerbalistCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    if( pPlayer->GetCardCountInDeckType( CARDTYPE::TREASURE ) > 0 )
    {
        Card* pTreasureToPutBack = pAI->OnHerbalist();

        if( pPlayer->IsCardInPlay( pTreasureToPutBack ) &&
            pTreasureToPutBack->IsTreasureCard() )
        {
            pPlayer->TakeCardFromInPlay( pTreasureToPutBack );
            pPlayer->PutCardOnDraw( pTreasureToPutBack );
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: HerbalistCard::OnCleanUpPhase" );
        }
    }
}

} // namespace Domlib