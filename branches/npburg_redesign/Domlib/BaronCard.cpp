#include "StdAfx.h"
#include "BaronCard.h"

namespace Domlib
{

BaronCard::BaronCard( void )
    : Card( 
        L"Baron",
        CARDID_BARON,
        CARDTYPE_ACTION,
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
    IAI* pAi = pPlayer->GetAI();

    pPlayer->PlusBuys( 1 );
    BaronOpt baronOpt = pAi->OnBaron();
    switch( baronOpt )
    {
    case BARON_DISCARD_ESTATE:
        pPlayer->PlusCoins( 4 ) ;
        break;
    case BARON_DO_NOT_DISCARD_ESTATE:
        pPlayer->GainCardOnDeck( CARDID_ESTATE );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: BaronCard::OnActionPhase" );
        break;
    }
}

} // namespace Domlib