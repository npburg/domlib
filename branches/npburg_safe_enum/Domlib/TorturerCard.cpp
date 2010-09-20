#include "StdAfx.h"
#include "TorturerCard.h"

namespace Domlib
{

TorturerCard::TorturerCard( void )
    : Card( 
        L"Torturer",
        CARDID::TORTURER,
        CARDTYPE::ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

TorturerCard::~TorturerCard( void )
{
}

void TorturerCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->DrawCardsToHand( 3 );

    Attack( pEngine, AttackWhom::OTHERS );
}

void TorturerCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    IAI* pAI = pPlayer->GetAI();
    CardList cardsToTrash = pAI->OnTorturer();

    if( cardsToTrash.size() == 0 )
    {
        pPlayer->GainCardOnDeck( CARDID::CURSE );
    }
    else if( cardsToTrash.size() == 2 &&
             pPlayer->AreCardsInHand( cardsToTrash ) )
    {
        pPlayer->TrashFromHand( cardsToTrash );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: TorturerCard::OnAttack" );
    }
}

} // namespace Domlib