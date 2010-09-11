#include "StdAfx.h"
#include "Player.h"

namespace Domlib
{

Player::Player( Engine* pEngine, IAI* pAi )
    :
    m_pEngine( pEngine ),
    m_pAi( pAi )
{
}

Player::~Player( void )
{
    delete m_pAi;
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