#include "StdAfx.h"
#include "NoblesCard.h"

namespace Domlib
{

NoblesCard::NoblesCard( void )
    : Card( 
        L"Nobles",
        CARDID::NOBLES,
        CARDTYPE::ACTION_VICTORY,
        0,
        Treasure( 0, 0 ),
        Treasure( 6, 0 ) )
{
}

NoblesCard::~NoblesCard( void )
{
}

void NoblesCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    NoblesOpt noblesOpt = pAI->OnNobles();

    switch( noblesOpt )
    {
    case NoblesOpt::PLUS_3_CARDS:
        pPlayer->DrawCardsToHand( 3 );
        break;
    case NoblesOpt::PLUS_2_ACTIONS:
        pPlayer->PlusActions( 2 );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: NoblesCard::OnActionPhase" );
    }
}

} // namespace Domlib