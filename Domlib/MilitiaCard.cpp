#include "StdAfx.h"
#include "MilitiaCard.h"

namespace Domlib
{

MilitiaCard::MilitiaCard( void )
    : Card( 
        L"Militia",
        CARDID::MILITIA,
        CARDTYPE::ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

MilitiaCard::~MilitiaCard( void )
{
}

void MilitiaCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->PlusCoins( 2 );
    Attack( pEngine, AttackWhom::OTHERS );
}
    
void MilitiaCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    IAI* pAI = pPlayer->GetAI();
    CardList cardsToDiscard;
    
    cardsToDiscard = pAI->OnMilitia();
    if( pPlayer->AreCardsInHand( cardsToDiscard ) )
    {
        pPlayer->DiscardFromHand( cardsToDiscard );

        if( pPlayer->CardsInHand() > 3 )
        {
            // TODO: report error
            throw std::wstring( L"Error: MilitiaCard::OnAttack" );
        }        
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: MilitiaCard::OnAttack" );
    }
}

} // namespace Domlib