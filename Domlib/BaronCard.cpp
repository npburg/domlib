#include "StdAfx.h"
#include "BaronCard.h"

namespace Domlib
{

BaronCard::BaronCard( void )
    : Card( 
        L"Baron",
        CARDID::BARON,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

BaronCard::~BaronCard( void )
{
}

void BaronCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    pPlayer->PlusBuys( 1 );
    BaronOpt baronOpt = pAI->OnBaron();
    switch( baronOpt.underlying() )
    {
    case BaronOpt::DISCARD_ESTATE:
        pPlayer->PlusCoins( 4 ) ;
        break;
    case BaronOpt::DO_NOT_DISCARD_ESTATE:
        pPlayer->GainCardOnDeck( CARDID::ESTATE );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: BaronCard::OnActionPhase" );
        break;
    }
}

} // namespace Domlib