#include "StdAfx.h"
#include "CountingHouseCard.h"

namespace Domlib
{

CountingHouseCard::CountingHouseCard(void)
    : Card( 
        L"Counting House",
        CARDID_COUNTINGHOUSE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

CountingHouseCard::~CountingHouseCard(void)
{
}

void CountingHouseCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    int numCoppersInDiscard = pPlayer->CardsInDiscard( CARDID_COPPER );
    
    if( numCoppersInDiscard > 0 )
    {
        IAI* pAI = pPlayer->GetAI();
        int numCoppersToTake = pAI->OnCountingHouse( numCoppersInDiscard );
        
        if( numCoppersToTake <= numCoppersInDiscard )
        {
            for( int i = 0; i < numCoppersToTake; i++ )
            {
                pPlayer->TakeCardFromDiscard( CARDID_COPPER );
                pPlayer->PutCardInHand( CARDID_COPPER );
            }
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: CountingHouseCard::OnActionPhase" );
        }
    }
}

} // namespace Domlib