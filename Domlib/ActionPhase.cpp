#include "ActionPhase.h"
#include "Card.h"
#include "Player.h"

namespace Domlib
{

namespace Phases
{

ActionPhase::ActionPhase( void )
{

}

ActionPhase::~ActionPhase( void )
{

}

void ActionPhase::Execute(
    Game* pGame,
    Turn* pTurn,
    Player* pPlayer )
{
    if( pPlayer->HasActionCardInHand() )
    {
        bool willPlayAction = true;
        Card* pCard = NULL;

        pPlayer->SelectActionCardFromHandToPlay(
            pCard,
            willPlayAction );

        if( willPlayAction )
        {
            if( pCard->IsAction() )
            {
                // Execute the action card
                // requested by the player
                pCard->Execute( 
                    pGame, 
                    pTurn, 
                    pPlayer );
            }
            else
            {
                // report faulty player
            }
        }
    }
}

} // namespace Domlib::Phases

} // namespace Domlib