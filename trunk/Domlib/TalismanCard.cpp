#include "StdAfx.h"
#include "TalismanCard.h"

namespace Domlib
{

TalismanCard::TalismanCard(void)
    : Card( 
        L"Talisman",
        CARDID_TALISMAN,
        CARDTYPE_TREASURE,
        0,
        Treasure( 1, 0 ),
        Treasure( 4, 0 ) )
{
}

TalismanCard::~TalismanCard(void)
{
}

void TalismanCard::OnCleanUpPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    CardList buyList = pPlayer->GetBuyList();
    
    for( CardListIter iter = buyList.begin();
         iter != buyList.end();
         iter++ )
    {
        if( !(*iter)->IsVictoryCard() )
        {
            pPlayer->GainCardOnDiscard( (*iter) );
        }
    }
}

} // namespace Domlib