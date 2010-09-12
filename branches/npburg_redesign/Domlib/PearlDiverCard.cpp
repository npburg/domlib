#include "StdAfx.h"
#include "PearlDiverCard.h"

namespace Domlib
{

PearlDiverCard::PearlDiverCard( void )
    : Card( 
        L"Pearl Diver",
        CARDID_PEARLDIVER,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

PearlDiverCard::~PearlDiverCard( void )
{
}

void PearlDiverCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    
    Card* pCard = pPlayer->SetAsideCardFromUnderDraw();
    PearlDiverOpt pearlDiverOpt = pAi->OnPearlDiver( pCard );
    
    switch( pearlDiverOpt )
    {
    case Domlib::PEARLDIVER_TOP_OF_DRAWPILE:
        pPlayer->PutCardOnDraw( pCard );
        break;
    case Domlib::PEARLDIVER_BOTTOM_OF_DRAWPILE:
        pPlayer->PutCardUnderDraw( pCard );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: PearlDiverCard::OnActionPhase" );
        break;
    }       
}

} // namespace Domlib