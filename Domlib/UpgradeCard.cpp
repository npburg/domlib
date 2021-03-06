#include "StdAfx.h"
#include "UpgradeCard.h"

namespace Domlib
{

UpgradeCard::UpgradeCard( void )
    : Card( 
        L"Upgrade",
        CARDID::UPGRADE,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

UpgradeCard::~UpgradeCard( void )
{
}

void UpgradeCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );

    Card* pCardToTrash = pAI->OnUpgrade();

    if( pPlayer->IsCardInHand( pCardToTrash ) )
    {
        pPlayer->TrashFromHand( pCardToTrash );
        Treasure cost = pCardToTrash->Cost( pEngine ) + Treasure( 1, 0 );
        Card* pCardToGain = pAI->OnGainACardExactly( &Treasure( cost ) );
        pPlayer->GainCardOnDiscard( pCardToGain );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: UpgradeCard::OnActionPhase" );
    }
}

} // namespace Domlib