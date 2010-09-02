#include "BuyPhase.h"
#include "Card.h"
#include "Turn.h"
#include "Player.h"
#include "Game.h"

namespace Domlib
{

namespace Phases
{

BuyPhase::BuyPhase( void )
{

}

BuyPhase::~BuyPhase( void )
{

}

void BuyPhase::Execute(
    Game* pGame,
    Turn* pTurn,
    Player* pPlayer )
{
    
    while( pTurn->AvailableBuys() && 
           pPlayer->ContinueBuying( pTurn->AvailableBuys() ) )
    {
        CARDID newCard = pPlayer->BuyCard( pTurn );

        if( newCard != CARDID_UNKNOWN )
        {
            Card* pCard = pGame->GetDeck()->GetCard( newCard );

            bool removed = false;
            CARDID id = pCard->CardId();
            
            switch( id )
            {
            case CARDID_COPPER:     removed = pGame->TakeCopper(); break;
            case CARDID_SILVER:     removed = pGame->TakeSilver(); break;
            case CARDID_GOLD:       removed = pGame->TakeGold(); break;
            case CARDID_ESTATE:     removed = pGame->TakeEstate(); break;
            case CARDID_DUCHY:      removed = pGame->TakeDuchy(); break;
            case CARDID_PROVINCE:   removed = pGame->TakeProvince(); break;
            case CARDID_CURSE:      removed = pGame->TakeCurse(); break;
            default:                removed = pGame->TakeKingdomCard( pCard );
            }

            if( removed )
            {
                pPlayer->GainCard( pCard );
            }
        }

        // Remove Buy
        pTurn->AddBuys( -1 );
    }
}

} // namespace Domlib::Phases

} // namespace Domlib