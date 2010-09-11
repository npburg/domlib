#include "StdAfx.h"
#include "Engine.h"
#include "Player.h"

namespace Domlib
{

Engine::Engine( void )
{
}

Engine::~Engine( void )
{
    while( m_PlayerList.size() )
    {
        delete m_PlayerList.back();
        m_PlayerList.pop_back();
    }
}

void Engine::RegisterPlayer( AI* pAi )
{
    pAi->SetEngine( new IEngine( this ) );

    Player* pNewPlayer = new Player( this, new IAI( pAi ) );

    m_PlayerList.push_back( pNewPlayer );
}


void Engine::Play( void )
{
    m_pCurrentPlayer = GetFirstPlayer();

    try
    {
        while( !IsGameOver() )
        {
            m_pCurrentPlayer->PlayTurn();
            if( m_OutpostFlag )
            {
                // do not increment the pPlayer pointer;
            }
            else
            {
                m_pCurrentPlayer = GetNextPlayer( m_pCurrentPlayer );
            }
        }
    }
    catch( std::wstring* errorString )
    {
        std::wcout << L"Exception raised: " << errorString << L"\n";
    }

}

} // namespace Domlib