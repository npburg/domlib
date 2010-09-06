#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Turn.h"
#include "IPlayer.h"

namespace Domlib
{

Game::Game( Deck::CARDSET set )
{
    m_pDeck             = new Deck( set );

    m_Estates.first     = m_pDeck->GetEstate();
    m_Duchies.first     = m_pDeck->GetDuchy();
    m_Provinces.first   = m_pDeck->GetProvince();
    m_Coppers.first     = m_pDeck->GetCopper();
    m_Silvers.first     = m_pDeck->GetSilver();
    m_Golds.first       = m_pDeck->GetGold();
    m_Curses.first      = m_pDeck->GetCurse();

    m_Coppers.second    = COPPER_MAX;
    m_Silvers.second    = SILVER_MAX;
    m_Golds.second      = GOLD_MAX;
    m_Estates.second    = ESTATES_MAX;
    m_Duchies.second    = DUCHIES_MAX;
    m_Provinces.second  = PROVINCE_MAX;

}

Game::~Game( void )
{
    while( m_Players.size() )
    {
        delete m_Players.back();
        m_Players.pop_back();
    }

    delete m_pDeck;
}

void Game::Play( void )
{
    std::vector<Player*>::iterator playerIterator = m_Players.begin();

    // Initialize Player
    while( playerIterator != m_Players.end() )
    {
        Player* currentPlayer = *playerIterator;

        InitializePlayer( currentPlayer );

        playerIterator++;
    }

    // Adjust Victory Pile Sizes
    // Eventually add validation for custom decks/starting values
    // to make sure the minimum estates remain for a valid game.
    switch( m_Players.size() )
    {
    case 2:
        m_Estates.second = VICTORY_MAX_2_PLAYER;
        break;
    case 3:
    case 4:
        m_Estates.second = VICTORY_MAX_3_4_PLAYER;
        break;
    default:
        m_Estates.second = 0;
    }

    // Select kingdom cards
    std::vector<Card*> kingdomCards;
    m_pDeck->SelectRandomKingdomCards(
        KINGDOM_PILES,
        kingdomCards );
    
    // Add required cards
    if( m_pRequiredCards.size() )
    {
        std::vector<Card*>::iterator cardItr = kingdomCards.begin();
        std::vector<Card*>::iterator removedItr = m_pRequiredCards.begin();
        while( cardItr != kingdomCards.end() &&
               m_pRequiredCards.size() )
        {
            while( removedItr != m_pRequiredCards.end() )
            {
                if( *cardItr == *removedItr )
                {
                    m_pRequiredCards.erase( removedItr );
                    break;
                }

                removedItr++;
            }
            removedItr = m_pRequiredCards.begin();

            cardItr++;
        }

        if( m_pRequiredCards.size() )
        {
            kingdomCards.insert(
                kingdomCards.end(),
                m_pRequiredCards.begin(),
                m_pRequiredCards.end() );
        }
    }

    // Create piles out of selected cards
    for( int i = 0; i < KINGDOM_PILES; i++ )
    {
        Card* pKingdomCard = kingdomCards.at( i );

        m_KingdomCards.push_back( 
            std::pair<Card*,int>( 
                pKingdomCard, 
                BASE_KINGDOM_PILE_SIZE ) );
    }


    // Execute Player Turns
    playerIterator = m_Players.begin();

    while( !IsGameOver() )
    {
        Player* currentPlayer = *playerIterator;

        Turn playerTurn( 
            TURN_INITIAL_BUYS,
            TURN_INITIAL_ACTIONS,
            TURN_INITIAL_TREASURE );

        playerTurn.Execute(
            this,
            currentPlayer );

        playerIterator++;

        // Restart the player iterator
        if( playerIterator == m_Players.end() )
        {
            playerIterator = m_Players.begin();
        }
    }
}

bool Game::TakeEstate( void )
{
    if( m_Estates.second > 0 ){ m_Estates.second--; return true; }
    else return false;
}

bool Game::TakeDuchy( void )
{
    if( m_Duchies.second > 0 ){ m_Duchies.second--; return true; }
    else return false;
}

bool Game::TakeProvince( void )
{
    if( m_Provinces.second > 0 ){ m_Provinces.second--; return true; }
    else return false;
}

bool Game::TakeCopper( void )
{
    if( m_Coppers.second > 0 ){ m_Coppers.second--; return true; }
    else return false;
}

bool Game::TakeSilver( void )
{
    if( m_Silvers.second > 0 ){ m_Silvers.second--; return true; }
    else return false;
}

bool Game::TakeGold( void )
{
    if( m_Golds.second > 0 ){ m_Golds.second--; return true; }
    else return false;
}

bool Game::TakeCurse( void )
{
    if( m_Curses.second > 0 ){ m_Curses.second--; return true; }
    else return false;
}

bool Game::TakeKingdomCard( Card* pCard )
{
    bool success = true;

    std::vector< std::pair<Card*,int> >::iterator pileItr = m_KingdomCards.begin();

    while( pileItr != m_KingdomCards.end() && success )
    {
        std::pair<Card*,int> cardPile = *pileItr;

        if( cardPile.first == pCard )
        {
            if( cardPile.second > 0 )
            {
                cardPile.second--;
            }
            else
            {
                success = false;
            }
        }

        pileItr++;
    }

    return success;
}

void Game::GetAvailableCards( std::vector<Card*>& cards )
{
    cards.clear();

    if( m_Coppers.second > 0 )      cards.push_back( m_Coppers.first );
    if( m_Silvers.second > 0 )      cards.push_back( m_Silvers.first );
    if( m_Golds.second > 0 )        cards.push_back( m_Golds.first );
    if( m_Curses.second > 0 )       cards.push_back( m_Curses.first );
    if( m_Estates.second > 0 )      cards.push_back( m_Estates.first );
    if( m_Duchies.second > 0 )      cards.push_back( m_Duchies.first );
    if( m_Provinces.second > 0 )    cards.push_back( m_Provinces.first );

    std::vector< std::pair<Card*,int> >::iterator pileItr = m_KingdomCards.begin();

    while( pileItr != m_KingdomCards.end() )
    {
        if( (*pileItr).second > 0 )
        {
            cards.push_back( (*pileItr).first );
        }
        pileItr++;
    }
}

Deck* Game::GetDeck( void )
{
    return m_pDeck;
}


AI::IDomCard* Game::GetCard( CARDID id )
{
    return m_pDeck->GetCard( id );
}

AI::IDomCard* Game::GetCopper( void ){      return m_pDeck->GetCopper();  }
AI::IDomCard* Game::GetSilver( void ){      return m_pDeck->GetSilver();  }
AI::IDomCard* Game::GetGold( void ){        return m_pDeck->GetGold();  }
AI::IDomCard* Game::GetEstate( void ){      return m_pDeck->GetEstate();  }
AI::IDomCard* Game::GetDuchy( void ){       return m_pDeck->GetDuchy();  }
AI::IDomCard* Game::GetProvince( void ){    return m_pDeck->GetProvince();  }
AI::IDomCard* Game::GetCurse( void ){       return m_pDeck->GetCurse();  }

void Game::InitializePlayer( Player* player )
{
    // Gain initial coppers
    for( int i = 0; i < PLAYER_INITIAL_COPPERS; i++ )
    {
        player->GainCard( m_Coppers.first );
    }
    m_Coppers.second -= PLAYER_INITIAL_COPPERS;

    // Gain initial estates
    for( int i = 0; i < PLAYER_INITIAL_ESTATES; i++ )
    {
        player->GainCard( m_Estates.first );
    }
    m_Estates.second -= PLAYER_INITIAL_ESTATES;

    // Shuffle Discard into Draw
    player->ShuffleDiscardIntoDraw();

    // Draw the initial hand
    for( int i = 0; i < CARDS_PER_HAND; i++ )
    {
        player->DrawCard();
    }
}

int Game::GetPlayerCount( void ) const
{
    return m_Players.size();
}

bool Game::IsGameOver( void ) const
{
    bool isOver = false;

    if( m_Provinces.second == 0 )
    {
        isOver = true;
    }
    else
    {
        // check for 3 empty kingdom cards
    }

    return isOver;
}

void Game::RegisterPlayer( AI::IPlayer* pPlayerAI )
{
    pPlayerAI->SetGameEngine( this );

    Player* pNewPlayer = new Player( pPlayerAI );

    m_Players.push_back( pNewPlayer );
}

void Game::RequireCard( CARDID id )
{
    if( id != CARDID_UNKNOWN )
    {
        Card* pCard = m_pDeck->GetCard( id );

        // Validate duplicates
        bool isDuplicate = false;
        std::vector<Card*>::iterator cardItr = m_pRequiredCards.begin();
        while( cardItr != m_pRequiredCards.end() )
        {
            if( (*cardItr)->CardId() == id )
            {
                isDuplicate = true;
                break;
            }

            cardItr++;
        }

        if( !isDuplicate )
        {
            m_pRequiredCards.push_back( pCard );
        }
    }
}

}