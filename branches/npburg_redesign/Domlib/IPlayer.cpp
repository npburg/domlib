#include "IPlayer.h"

namespace Domlib
{

namespace AI
{

IPlayer::IPlayer( void )
{
};

IPlayer::~IPlayer( void )
{
};

IGameEngine* IPlayer::Engine( void )
{
    return m_pEngine;
}

void IPlayer::SetGameEngine( IGameEngine* pGameEngine )
{
    m_pEngine = pGameEngine;
}

}; // namespace Domlib::AI

}; // namespace Domlib