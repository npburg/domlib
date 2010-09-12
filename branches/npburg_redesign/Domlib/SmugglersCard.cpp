#include "StdAfx.h"
#include "SmugglersCard.h"

namespace Domlib
{

SmugglersCard::SmugglersCard( void )
    : Card( 
        L"Smugglers",
        CARDID_SMUGGLERS,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

SmugglersCard::~SmugglersCard( void )
{
}

void SmugglersCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    Player* pPlayerToLeft = pEngine->GetPreviousPlayer( pPlayer );
    CardList buyList = pPlayerToLeft->GetBuyList();
    
    for( CardListIter iter = buyList.begin();
         iter != buyList.end();
         iter++ )
    {
        if( (*iter)->Cost( pEngine ) > Treasure( 6, 0 ) )
        {
            buyList.erase( iter );
        }
    }
    
    if( buyList.size() > 0 )
    {
        Card* pCard = pAi->OnSmugglers( buyList );
        
        if( Card::CardInList( pCard, buyList ) )
        {
            pPlayer->GainCardOnDiscard( pCard );
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: SmugglersCard::OnActionPhase" );
        }
    }
}

} // namespace Domlib