#include "StdAfx.h"
#include "Domlib.h"
#include "Game.h"

namespace Domlib
{

IGame::IGame( void )
{
    m_pGame = new Game();
}

IGame::~IGame( void )
{
    delete m_pGame;
}

void IGame::RegisterAI( AI* pAI )
{
    m_pGame->RegisterAI( pAI );
}

void IGame::RandomizeKingdomCards( int cardSet )
{
    m_pGame->RandomizeKingdomCards( cardSet );
}

void IGame::Play( void )
{
    m_pGame->Play();
}

void* IGame::GetResults( void )
{
    return m_pGame->GetResults();
}

} // namespace Domlib