#pragma once

#include "Domlib.h"
#include "SupplyPileManager.h"

namespace Domlib
{

class Player;

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
    bool        CardsAvailable( CARDID cardId );

    void        RegisterPlayer( AI* pAi );
    void        Play( void );

    Player*     GetFirstPlayer( void );
    Player*     GetPreviousPlayer( Player* pPlayer );
    Player*     GetCurrentPlayer( void );
    Player*     GetNextPlayer( Player* pPlayer );
    Player*     GetLastPlayer( void );
    void        PutInTrash( Card* pCard );

protected:
    bool IsGameOver( void ) const;

private:
    Player*             m_pCurrentPlayer;
    PlayerList          m_PlayerList;
    SupplyPileManager   m_SupplyPileManager;
    ICardList    m_TrashList;
    int                 m_TradeRouteMat;
    bool                m_OutpostFlag;
    bool                m_PossessionFlag;
};

} // namespace Domlib