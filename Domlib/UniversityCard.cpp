#include "StdAfx.h"
#include "UniversityCard.h"

namespace Domlib
{

UniversityCard::UniversityCard( void )
    : Card( 
        L"University",
        CARDID::UNIVERSITY,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 1 ) )
{
}

UniversityCard::~UniversityCard( void )
{
}

void UniversityCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();

    pPlayer->PlusActions( 2 );

    Card* pActionCardToGain = pAI->OnUniversity();

    if( pActionCardToGain->IsActionCard() &&
        pActionCardToGain->Cost( pEngine ) < Treasure( 5, 0 ) )
    {
        pPlayer->GainCardOnDiscard( pActionCardToGain );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: UniversityCard::OnActionPhase" );
    }
}

} // namespace Domlib