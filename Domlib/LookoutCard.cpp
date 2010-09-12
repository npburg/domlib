#include "StdAfx.h"
#include "LookoutCard.h"

namespace Domlib
{

LookoutCard::LookoutCard( void )
    : Card( 
        L"Lookout",
        CARDID_LOOKOUT,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 3, 0 ) )
{
}

LookoutCard::~LookoutCard( void )
{
}

void LookoutCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAI = pPlayer->GetAI();
    CardList cardList = pPlayer->SetAside( 3 );
    LookoutStruct lookoutStruct =  pAI->OnLookout( cardList );
    
    if( CardListsMatch( cardList, lookoutStruct ) )
    {
        pEngine->PutCardInTrash( lookoutStruct.pCardToTrash );
        pPlayer->PutCardInDiscard( lookoutStruct.pCardToDiscard );
        pPlayer->PutCardOnDraw( lookoutStruct.PCardToPutBack );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: LookoutCard::OnActionPhase" );
    }
}

} // namespace Domlib