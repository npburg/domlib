#include "StdAfx.h"
#include "UpgradeCard.h"

namespace Domlib
{

UpgradeCard::UpgradeCard( void )
    : Card( 
        L"Upgrade",
        CARDID_UPGRADE,
        CARDTYPE_ACTION,
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
    AI* pAi = pPlayer->GetAI();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );

    ICard* pCardToTrash = pAi->OnUpgrade();

    if( pPlayer->IsCardInHand( pCardToTrash ) )
    {
        pPlayer->TrashFromHand( pCardToTrash );
        ICard* pCardToGain = pAi->OnGainACardExactly( 
            pCardToTrash->Cost( pEngine ) + Treasure( 1, 0 ) );
        pPlayer->GainCardOnDiscard( pCardToGain );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: UpgradeCard::OnActionPhase" );
    }
}

} // namespace Domlib