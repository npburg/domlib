#include "StdAfx.h"
#include "StewardCard.h"

namespace Domlib
{

StewardCard::StewardCard( void )
    : Card( 
        L"Steward",
        CARDID::STEWARD,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

StewardCard::~StewardCard( void )
{
}

void StewardCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    StewardOpt stewardOpt = pAI->OnSteward();

    switch( stewardOpt.underlying() )
    {
    case StewardOpt::PLUS_2_CARDS:
        pPlayer->DrawCardsToHand( 2 );
        break;
    case StewardOpt::PLUS_2_COINS:
        pPlayer->PlusCoins( 2 );
        break;
    case StewardOpt::TRASH_2_CARDS:
        {
            CardList cardsToTrash = pAI->OnStewardTrash();
            if( cardsToTrash.size() == 2 &&
                pPlayer->AreCardsInHand( cardsToTrash ) )
            {
                pPlayer->TrashFromHand( cardsToTrash );
            }
        }
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: StewardCard::OnActionPhase" );
    }
}

} // namespace Domlib