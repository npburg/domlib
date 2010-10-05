#include "StdAfx.h"
#include "Engine.h"
#include "Player.h"

namespace Domlib
{

Engine::Engine( void )
{
    // TODO: Implement the NullPlayer and NullAI.
    //m_pNullPlayer = new Player( this, 
    m_pCurrentPlayer = m_pNullPlayer;
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
    return m_SupplyPileManager.IsPileAvailable( cardId );
}


CardList Engine::PilesAvailable( void )
{
    return m_SupplyPileManager.PilesAvailable();
}


int Engine::CardsAvailable( CARDID cardId )
{
    return m_SupplyPileManager.CardsAvailable( cardId );
}


CardList Engine::CardsCostingExactly( const Treasure* cost )
{
    throw std::wstring( L"Error: Engine::CardsCostingExactly - To be implemented..." );
    CardList cardList;
    
    return cardList;
}

void Engine::RandomizeKingdomCards( int cardSet )
{
    m_CardSet = cardSet;
}

void Engine::RegisterPlayer( AI* pAI )
{
    pAI->SetEngine( new IEngine( this ) );

    Player* pNewPlayer = new Player( this, new IAI( pAI ) );

    m_PlayerList.push_back( pNewPlayer );
}

void Engine::Play( void )
{
    m_SupplyPileManager.RandomizeKingdomCards( m_CardSet );
    m_SupplyPileManager.InitializePiles( m_PlayerList.size() );
    
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
    if( m_PlayerList.size() )
    {
        return m_PlayerList.front();
    }
    
    return m_pNullPlayer;
}

Player* Engine::GetPreviousPlayer( Player* pPlayer )
{
    PlayerListIter iter = find( m_PlayerList.begin(),
                                m_PlayerList.end(),
                                pPlayer );
    
    if( iter == m_PlayerList.end() )
    {
        // TODO: report error
        return m_pNullPlayer;
    }
    else if (iter == m_PlayerList.begin() )
    {
        return m_PlayerList.back();
    }
    else
    {
        iter--;
        return (*iter);
    }
}

Player* Engine::GetCurrentPlayer( void )
{
    return m_pCurrentPlayer;
}

Player* Engine::GetNextPlayer( Player* pPlayer )
{
    PlayerListIter iter = find( m_PlayerList.begin(),
                                m_PlayerList.end(),
                                pPlayer );
    
    if( iter == m_PlayerList.end() )
    {
        // TODO: report error
        return m_pNullPlayer;
    }
    else
    {
        iter++;
        if( iter == m_PlayerList.end() )
        {
            return m_PlayerList.front();
        }
        else
        {
            return (*iter);
        }
    }
}

Player* Engine::GetLastPlayer( void )
{
    if( m_PlayerList.size() )
    {
        return m_PlayerList.back();
    }
    
    return m_pNullPlayer;
}

void Engine::PutCardInTrash( Card* pCard )
{
    m_TrashList.push_front( pCard );
}

bool Engine::IsGameOver( void ) const
{
    if( m_SupplyPileManager.PileExists( CARDID::COLONY ) && 
        m_SupplyPileManager.IsPileEmpty( CARDID::COLONY ) )
    {
        return true;
    }
    else if( m_SupplyPileManager.IsPileEmpty( CARDID::PROVINCE ) )
    {
        return true;
    }
    else if( m_PlayerList.size() <= 4 &&
             m_SupplyPileManager.NumEmptyPiles() >= 3 )
    {
        return true;
    }
    else if( m_SupplyPileManager.NumEmptyPiles() >= 4 )
    {
        return true;
    }

    return false;
}

int Engine::TradeTokens( void )
{
    return m_TradeRouteMat;
}

void Engine::SetContrabandCard( Card* pCard )
{
    m_SupplyPileManager.SetContrabandCard( pCard );
}

void Engine::ClearContrabandCards( void )
{
    m_SupplyPileManager.ClearContrabandCards();
}

int Engine::SupplyPilesEmpty( void )
{
    return m_SupplyPileManager.NumEmptyPiles();
}

void Engine::SetOutpostFlag( bool flag )
{
    m_OutpostFlag = flag;
}

void Engine::OnEmbargo(Domlib::Card* pCard)
{
    m_SupplyPileManager.Embargo( pCard );
}

void Engine::SetAmbassadorCard( Card* pCard )
{
    m_pAmbassadorCard = pCard;
}

void Engine::PutCardInSupply( Card* pCard )
{
    m_SupplyPileManager.AddCard( pCard );
}

Card* Engine::GetAmbassadorCard( void )
{
    return m_pAmbassadorCard;
}

} // namespace Domlib