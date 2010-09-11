#include "StdAfx.h"
#include "MineCard.h"

namespace Domlib
{

MineCard::MineCard( void )
    : Card( 
        L"Mine",
        CARDID_MINE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

MineCard::~MineCard( void )
{
}

void MineCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    Card* pCardToTrash = pAi->OnMineTrash();

    if( pCardToTrash->IsTreasureCard() &&
        pPlayer->IsCardInHand( pCardToTrash ) )
    {
        pPlayer->TrashFromHand( pCardToTrash );
        Treasure cost = pCardToTrash->Cost( pEngine ) + Treasure( 3, 0 );
        Card* pCardToGain = pAi->OnMineGain( &cost );
        pPlayer->GainCardInHand( pCardToGain );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: MineCard::OnActionPhase" );
    }
}

} // namespace Domlib