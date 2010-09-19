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


bool Engine::IsCardInStock( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
    return false;
}


CardList Engine::PilesAvailable( void )
{
    throw std::wstring( L"Error: Engine::PilesAvailable - To be implemented..." );
    CardList cardList;
    
    return cardList;
}


bool Engine::CardsAvailable( CARDID cardId )
{
    DOMLIB_NOT_IMPLEMENTED;
    return false;
}


CardList Engine::CardsCostingExactly( const Treasure* cost )
{
    throw std::wstring( L"Error: Engine::CardsCostingExactly - To be implemented..." );
    CardList cardList;
    
    return cardList;
}

void Engine::RegisterPlayer( AI* pAI )
{
    pAI->SetEngine( new IEngine( this ) );

    Player* pNewPlayer = new Player( this, new IAI( pAI ) );

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

Player* Engine::GetFirstPlayer( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

Player* Engine::GetPreviousPlayer( Player* pPlayer )
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

Player* Engine::GetCurrentPlayer( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

Player* Engine::GetNextPlayer( Player* pPlayer )
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

Player* Engine::GetLastPlayer( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return NULL;
}

void Engine::PutCardInTrash( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

bool Engine::IsGameOver( void ) const
{
    DOMLIB_NOT_IMPLEMENTED;
    return true;
}

int Engine::TradeTokens( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

void Engine::SetContrabandCard( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Engine::ClearContrabandCards( void )
{
    DOMLIB_NOT_IMPLEMENTED;
}

int Engine::SupplyPilesEmpty( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return 0;
}

void Engine::SetOutpostFlag( bool flag )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Engine::OnEmbargo(Domlib::Card* pCard)
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Engine::SetAmbassadorCard( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

void Engine::PutCardInSupply( Card* pCard )
{
    DOMLIB_NOT_IMPLEMENTED;
}

Card* Engine::GetAmbassadorCard( void )
{
    DOMLIB_NOT_IMPLEMENTED;
    return Card::GetCard( CARDID_NULL );
}

} // namespace Domlib