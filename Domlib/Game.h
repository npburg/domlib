#pragma once

#include <vector>
#include "Deck.h"
#include "IGameEngine.h"

namespace Domlib
{

class Card;
class Player;

namespace Decks
{
    class Deck;
}

namespace AI
{
    class IPlayer;
    class IDomCard;
}

class Game
    :
    public AI::IGameEngine
{
public:

    // Standard Dominion Rule Constants
    const static int    VICTORY_MAX_2_PLAYER    = 7;    // Starting victory pile size in a 1-2 player game
    const static int    VICTORY_MAX_3_4_PLAYER  = 12;   // Starting victory pile size in a 3-4 player game
    const static int    KINGDOM_PILES           = 10;   // Number of kingdom piles
    const static int    BASE_KINGDOM_PILE_SIZE  = 10;   // Number of cards for each kingdom card

    // Note: this should probably be a property of the deck...
    const static int    COPPER_MAX              = 60;   // Maximum coppers available
    const static int    SILVER_MAX              = 40;   // Maximum silvers available
    const static int    GOLD_MAX                = 30;   // Maximum golds available
    const static int    ESTATES_MAX             = 24;   // Maximum estates available
    const static int    DUCHIES_MAX             = 12;   // Maximum duchies available
    const static int    PROVINCE_MAX            = 12;   // Maximum provinces available

    const static int    CURSE_MAX_2_PLAYER      = 10;   // Starting curse pile size in a 2 player game
    const static int    CURSE_MAX_3_PLAYER      = 20;   // Starting curse pile size in a 3 player game
    const static int    CURSE_MAX_4_PLAYER      = 30;   // Starting curse pile size in a 4 player game
    const static int    TURN_INITIAL_BUYS       = 1;    // Initial buys per turn
    const static int    TURN_INITIAL_ACTIONS    = 1;    // Initial actions per turn
    const static int    TURN_INITIAL_TREASURE   = 0;    // Initial treasure per turn
    const static int    PLAYER_INITIAL_COPPERS  = 7;    // Starting copper count
    const static int    PLAYER_INITIAL_ESTATES  = 3;    // Starting estate count
    const static int    CARDS_PER_HAND          = 5;    // Initial card count per hand

    Game( Deck::CARDSET set );

    ~Game( void );

    void RegisterPlayer( AI::IPlayer* player );

    void Play( void );

    Deck*                   GetDeck( void );

    bool                    TakeEstate( void );
    bool                    TakeDuchy( void );
    bool                    TakeProvince( void );
    bool                    TakeCopper( void );
    bool                    TakeSilver( void );
    bool                    TakeGold( void );
    bool                    TakeCurse( void );
    bool                    TakeKingdomCard( Card* pCard );

    // IGameEngine interfaces
    virtual AI::IDomCard*   GetCard( CARDID id );
    virtual AI::IDomCard*   GetCopper( void );
    virtual AI::IDomCard*   GetSilver( void );
    virtual AI::IDomCard*   GetGold( void );
    virtual AI::IDomCard*   GetEstate( void );
    virtual AI::IDomCard*   GetDuchy( void );
    virtual AI::IDomCard*   GetProvince( void );
    virtual AI::IDomCard*   GetCurse( void );

protected:

    bool    IsGameOver( void ) const;

    void    InitializePlayer( Player* player );

    int     GetPlayerCount( void ) const;

private:
    // Trash Pile
    std::vector<Card*>                  m_Trash;

    // Victory Piles
    std::pair<Card*,int>                m_Estates;
    std::pair<Card*,int>                m_Duchies;
    std::pair<Card*,int>                m_Provinces;

    // Treasure Piles
    std::pair<Card*,int>                m_Coppers;
    std::pair<Card*,int>                m_Silvers;
    std::pair<Card*,int>                m_Golds;

    // Curse Pile
    std::pair<Card*,int>                m_Curses;

    // Kingdom Pile
    std::vector< std::pair<Card*,int> > m_KingdomCards;

    // Players
    std::vector<Player*>                m_Players;

    // Cards ( not all in play )
    Deck*                               m_pDeck;
};

}