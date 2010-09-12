#include "StdAfx.h"
#include "NavigatorCard.h"

namespace Domlib
{

NavigatorCard::NavigatorCard( void )
    : Card( 
        L"Navigator",
        CARDID_NAVIGATOR,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 0 ) )
{
}

NavigatorCard::~NavigatorCard( void )
{
}

void NavigatorCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    
    pPlayer->PlusCoins( 2 );
    CardList cardList = pPlayer->SetAside( 5 );
    CardList reorderedCardList = pAi->OnNavigator( cardList );
    
    if( CardListsMatch( cardList, reorderedCardList ) )
    {
        pPlayer->PutCardsOnDraw( reorderedCardList );
    }
    else if( reorderedCardList.size() == 0 )
    {
        pPlayer->PutCardsInDiscard( cardList );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: NavigatorCard::OnActionPhase" );
    }
}

} // namespace Domlib