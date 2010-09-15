#include "StdAfx.h"
#include "Domlib.h"
#include "Player.h"

namespace Domlib
{

IPlayerOther::IPlayerOther( Player* pPlayer )
{
    m_pPlayer = pPlayer;
}

IPlayerOther::~IPlayerOther( void )
{
    // Do nothing. The player was allocated and freed by the caller.
}

int IPlayerOther::CardsInHand( void )
{
    return m_pPlayer->CardsInHand();
}

} // namespace Domlib