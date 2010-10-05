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

void Game::RegisterAI( AI* pAI )
{
    m_Engine.RegisterPlayer( pAI );
}

void Game::RandomizeKingdomCards( int cardSet )
{
    m_Engine.RandomizeKingdomCards( cardSet );
}

void Game::Play( void )
{
    m_Engine.Play();
}

void* Game::GetResults( void )
{
    return NULL;
}


} // namespace Domlib