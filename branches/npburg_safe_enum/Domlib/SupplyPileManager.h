#pragma once

#include "Domlib.h"

namespace Domlib
{

class SupplyPile;

typedef std::map<CARDID, SupplyPile*>   SupplyPileMap;
typedef SupplyPileMap::iterator         SupplyPileMapIter;
typedef SupplyPileMap::const_iterator   SupplyPileMapConstIter;
typedef std::pair<CARDID, SupplyPile*>  SupplyPilePair;

class SupplyPileManager
{
public:
    SupplyPileManager( void );
    virtual ~SupplyPileManager( void );

    void    AddPile( const CARDID cardId, const int cardsAvailable );
    int     NumEmptyPiles( void ) const;
    bool    IsPileEmpty( const CARDID cardId ) const;
    int     CardsAvailable( const CARDID cardId ) const;
    void    AddCard( const CARDID cardId );
    void    RemoveCard( const CARDID cardId );
    void    Clear( void );

private:
    const SupplyPile* SupplyPileManager::Find( const CARDID cardId ) const;
          SupplyPile* SupplyPileManager::Find( const CARDID cardId );

    SupplyPile*     m_pNullPile;
    SupplyPileMap   m_SupplyPiles;
};

} // namespace Domlib