#include "CleanupPhase.h"
#include "Player.h"
#include "Game.h"

namespace Domlib
{

namespace Phases
{

CleanupPhase::CleanupPhase( void )
{

}

CleanupPhase::~CleanupPhase( void )
{

}

void CleanupPhase::Execute(
    Game* pGame,
    Turn* pTurn,
    Player* pPlayer )
{
    // TBD: Put cards in play into discard

    pPlayer->DiscardHand();

    for( int i = 0; i < Game::CARDS_PER_HAND; i++ )
    {
        pPlayer->DrawCard();
    }
}

} // namespace Domlib::Phases

} // namespace Domlib