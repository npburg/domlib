#include "StdAfx.h"
#include "ForgeCard.h"

namespace Domlib
{

ForgeCard::ForgeCard(void)
    : Card( 
        L"Forge",
        CARDID::FORGE,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 7, 0 ) )
{
}

ForgeCard::~ForgeCard(void)
{
}

void ForgeCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    CardList cardsToTrash = pAI->OnForge();
    
    if( pPlayer->AreCardsInHand( cardsToTrash ) )
    {
        pPlayer->TrashFromHand( cardsToTrash );
        int coins = 0;
        
        for( CardListIter iter = cardsToTrash.begin();
             iter != cardsToTrash.end();
             iter++ )
        {
            coins += (*iter)->Cost( pEngine ).Coins();
        }
        
        pPlayer->OnGainACard( &Treasure( coins, 0 ) );
    }
    else
    {
        // TODO: report error.
        throw std::wstring( L"Error: ForgeCard::OnActionPhase" );
    }
    
}

} // namespace Domlib