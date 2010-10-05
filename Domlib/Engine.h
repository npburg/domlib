#pragma once

#include "Domlib.h"
#include "SupplyPileManager.h"

namespace Domlib
{

class Player;
class Treasure;

typedef std::list<Player*>          PlayerList;
typedef PlayerList::iterator        PlayerListIter;
typedef PlayerList::const_iterator  PlayerListConstIter;

class Engine
{
public:
    Engine( void );
    virtual ~Engine( void );

    // IEngine Interfaces
    bool        IsCardInStock( CARDID cardId );
    CardList    PilesAvailable( void );
    int         CardsAvailable( CARDID cardId );
    CardList    CardsCostingExactly( const Treasure* cost );

    void        RandomizeKingdomCards( int cardSet );
    void        RegisterPlayer( AI* pAI );
    void        Play( void );

    Player*     GetFirstPlayer( void );
    Player*     GetPreviousPlayer( Player* pPlayer );
    Player*     GetCurrentPlayer( void );
    Player*     GetNextPlayer( Player* pPlayer );
    Player*     GetLastPlayer( void );
    void        PutCardInTrash( Card* pCard );
    void        PutCardInStock( Card* pCard );
    void        PutCardInSupply( Card* pCard );
    void        SetAmbassadorCard( Card* pCard );
    Card*       GetAmbassadorCard( void );
    void        OnEmbargo( Card* pCard );
    void        SetOutpostFlag( bool flag );
    void        SetPossessionFlag( bool flag );
    int         SupplyPilesEmpty( void );
    void        SetContrabandCard( Card* pCard );
    void        ClearContrabandCards( void );
    int         TradeTokens( void );

protected:
    bool IsGameOver( void ) const;

private:
    int                 m_CardSet;
    Player*             m_pNullPlayer;
    Player*             m_pCurrentPlayer;
    PlayerList          m_PlayerList;
    SupplyPileManager   m_SupplyPileManager;
    CardList            m_TrashList;
    int                 m_TradeRouteMat;
    bool                m_OutpostFlag;
    bool                m_PossessionFlag;
    Card*               m_pAmbassadorCard;
};

} // namespace Domlib