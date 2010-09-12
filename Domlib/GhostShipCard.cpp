#include "StdAfx.h"
#include "GhostShipCard.h"

namespace Domlib
{

GhostShipCard::GhostShipCard( void )
    : Card( 
        L"Ghost Ship",
        CARDID_GHOSTSHIP,
        CARDTYPE_ACTION_ATTACK,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

GhostShipCard::~GhostShipCard( void )
{
}


void GhostShipCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
 
    pPlayer->DrawCardsToHand( 2 );
    Attack( pEngine, ATTACK_OTHERS );   
}


void GhostShipCard::OnAttack( Engine* pEngine, Player* pPlayer )
{
    IAI* pAi = pPlayer->GetAI();
    CardList cardsToPutBack;
    
    cardsToPutBack = pAi->OnGhostShip();
    if( pPlayer->AreCardsInHand( cardsToPutBack ) )
    {
        pPlayer->TakeCardsFromHand( cardsToPutBack );
        pPlayer->PutCardsOnDraw( cardsToPutBack );

        if( pPlayer->CardsInHand() > 3 )
        {
            // TODO: report error
            throw std::wstring( L"Error: GhostShipCard::OnAttack" );
        }        
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: GhostShipCard::OnAttack" );
    }
}

} // namespace Domlib