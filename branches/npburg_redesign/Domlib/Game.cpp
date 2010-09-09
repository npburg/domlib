#include "StdAfx.h"
#include "Game.h"

namespace Domlib
{

Game::Game( void )
{
}

Game::~Game( void )
{
}

IGame* CreateGame( void )
{
    return new Game();
}

} // namespace Domlib