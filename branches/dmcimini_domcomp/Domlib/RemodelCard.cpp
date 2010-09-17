#include "StdAfx.h"
#include "RemodelCard.h"

namespace Domlib
{

RemodelCard::RemodelCard( void )
    : Card(
           L"Remodel",
           CARDID_REMODEL,
           CARDTYPE_ACTION,
           0,
           Treasure( 0, 0 ),
           Treasure( 4, 0 ) )
{
}

RemodelCard::~RemodelCard( void )
{
}


void RemodelCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    Card* pCardToRemodel = pAI->OnRemodel();

    if( pPlayer->IsCardInHand( pCardToRemodel ) )
    {
        pPlayer->TrashFromHand( pCardToRemodel );
        Treasure cost = pCardToRemodel->Cost( pEngine ) + Treasure( 2, 0 );
        pAI->OnGainACard( &cost );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: RemodelCard::OnActionPhase" );
    }
}

} // namespace Domlib