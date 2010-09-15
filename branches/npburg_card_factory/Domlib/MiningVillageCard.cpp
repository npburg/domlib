#include "StdAfx.h"
#include "MiningVillageCard.h"

namespace Domlib
{

MiningVillageCard::MiningVillageCard( void )
    : Card( 
        L"Mining Village",
        CARDID_MININGVILLAGE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

MiningVillageCard::~MiningVillageCard( void )
{
}

void MiningVillageCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 2 );

    MiningVillageOpt miningVillageOpt = pAI->OnMiningVillage();
    switch( miningVillageOpt )
    {
    case MININGVILLAGE_DO_NOT_TRASH_CARD:
        // do nothing
        break;
    case MININGVILLAGE_TRASH_CARD:
        pPlayer->TrashFromInPlay( this );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: MiningVillageCard::OnActionPhase()" );
        break;
    }
}

} // namespace Domlib