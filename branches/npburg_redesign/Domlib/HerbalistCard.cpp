#include "StdAfx.h"
#include "HerbalistCard.h"

namespace Domlib
{

HerbalistCard::HerbalistCard( void )
    : Card( 
        L"Herbalist",
        CARDID_HERBALIST,
        CARDTYPE_ACTION,
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
    AI* pAi = pPlayer->GetAI();

    if( pPlayer->GetCardCountInDeckType( CARDTYPE_TREASURE ) > 0 )
    {
        ICard* pTreasureToPutBack = pAi->OnHerbalist();

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