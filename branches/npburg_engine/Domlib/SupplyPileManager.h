#pragma once

#include "Domlib.h"

namespace Domlib
{

class SupplyPile;

typedef std::map<CARDID, SupplyPile*>   SupplyPileMap;
typedef SupplyPileMap::iterator         SupplyPileMapIter;
typedef SupplyPileMap::const_iterator   SupplyPileMapConstIter;
typedef std::pair<CARDID, SupplyPile*>  SupplyPilePair;

enum
{
    NUM_KINGDOM_CARD_PILES = 10,
};

class SupplyPileManager
{
public:
    SupplyPileManager( void );
    virtual ~SupplyPileManager( void );

    void        InitializePiles( int numPlayers );
    void        RandomizeKingdomCards( int cardSet );
    void        AddPile( const CARDID cardId, const int cardsAvailable );
    int         NumEmptyPiles( void ) const;
    bool        IsPileEmpty( const CARDID cardId ) const;
    int         CardsAvailable( const CARDID cardId ) const;
    void        AddCard( const Card* pCard );
    void        AddCard( const CARDID cardId );
    void        RemoveCard( const CARDID cardId );
    void        Clear( void );
    bool        IsPileAvailable( const CARDID cardId );
    bool        IsPileAvailable( const Card* pCard );
    CardList    PilesAvailable( void );
    bool        PileExists( const CARDID cardId ) const;
    void        SetContrabandCard( const Card* pCard );
    void        ClearContrabandCards( void );
    void        Embargo( const Card* pCard );

private:
    const SupplyPile* SupplyPileManager::Find( const CARDID cardId ) const;
          SupplyPile* SupplyPileManager::Find( const CARDID cardId );

    SupplyPile*     m_pNullPile;
    SupplyPileMap   m_SupplyPiles;
};

} // namespace Domlib