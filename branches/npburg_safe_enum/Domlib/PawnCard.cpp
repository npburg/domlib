#include "StdAfx.h"
#include "PawnCard.h"

namespace Domlib
{

PawnCard::PawnCard( void )
    : Card( 
        L"Pawn",
        CARDID::PAWN,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

PawnCard::~PawnCard( void )
{
}

void PawnCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    PawnOptPair pawnOptPair = pAI->OnPawn();

    if( pawnOptPair.first != pawnOptPair.second )
    {
        switch( pawnOptPair.first.underlying() )
        {
        case PawnOpt::PLUS_1_CARD:
            pPlayer->DrawCardsToHand( 1 );
            break;
        case PawnOpt::PLUS_1_ACTION:
            pPlayer->PlusActions( 1 );
            break;        
        case PawnOpt::PLUS_1_BUY:
            pPlayer->PlusBuys( 1 );
            break;
        case PawnOpt::PLUS_1_COIN:
            pPlayer->PlusCoins( 1 );
            break;
        default:
            // TODO: report error
            throw std::wstring( L"Error: PawnCard::OnActionPhase" );
            break;
        }

        switch( pawnOptPair.second.underlying() )
        {
        case PawnOpt::PLUS_1_CARD:
            pPlayer->DrawCardsToHand( 1 );
            break;
        case PawnOpt::PLUS_1_ACTION:
            pPlayer->PlusActions( 1 );
            break;        
        case PawnOpt::PLUS_1_BUY:
            pPlayer->PlusBuys( 1 );
            break;
        case PawnOpt::PLUS_1_COIN:
            pPlayer->PlusCoins( 1 );
            break;
        default:
            // TODO: report error
            throw std::wstring( L"Error: PawnCard::OnActionPhase" );
            break;
        }
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: PawnCard::OnActionPhase" );
    }
}

} // namespace Domlib