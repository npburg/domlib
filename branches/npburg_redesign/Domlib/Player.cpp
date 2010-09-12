#include "StdAfx.h"
#include "Player.h"

namespace Domlib
{

Player::Player( Engine* pEngine, IAI* pAI )
    :
    m_pEngine( pEngine ),
    m_pAI( pAI )
{
}

Player::~Player( void )
{
    delete m_pAI;
}

void Player::PlayTurn( void )
{
    OnDurationPhase();
    OnActionPhase();
    OnTreasurePhase();
    OnBuyPhase();
    OnCleanUpPhase();
}

int Player::ActionsPlayed( void )
{
    return m_ActionsPlayed;
}

} // namespace Domlib