#include "StdAfx.h"
#include "PearlDiverCard.h"

namespace Domlib
{

PearlDiverCard::PearlDiverCard( void )
    : Card( 
        L"Pearl Diver",
        CARDID::PEARLDIVER,
        CARDTYPE::ACTION,
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
    IAI* pAI = pPlayer->GetAI();
    
    pPlayer->DrawCardsToHand( 1 );
    pPlayer->PlusActions( 1 );
    
    Card* pCard = pPlayer->SetAsideCardFromUnderDraw();
    PearlDiverOpt pearlDiverOpt = pAI->OnPearlDiver( pCard );
    
    switch( pearlDiverOpt )
    {
    case Domlib::PearlDiverOpt::TOP_OF_DRAWPILE:
        pPlayer->PutCardOnDraw( pCard );
        break;
    case Domlib::PearlDiverOpt::BOTTOM_OF_DRAWPILE:
        pPlayer->PutCardUnderDraw( pCard );
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: PearlDiverCard::OnActionPhase" );
        break;
    }       
}

} // namespace Domlib