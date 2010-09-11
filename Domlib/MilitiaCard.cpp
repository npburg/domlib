#include "StdAfx.h"
#include "MilitiaCard.h"

namespace Domlib
{

MilitiaCard::MilitiaCard( void )
    : Card( 
        L"Militia",
        CARDID_MILITIA,
        CARDTYPE_ACTION_ATTACK,
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
    Attack( pEngine, ATTACK_OTHERS );
}
    
void MilitiaCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    IAI* pAi = pPlayer->GetAI();
    CardList cardsToDiscard;
    
    cardsToDiscard = pAi->OnMilitia();
    if( pPlayer->AreCardsInHand( cardsToDiscard ) )
    {
        pPlayer->DiscardFromHand( cardsToDiscard );

        if( pPlayer->HandSize() > 3 )
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