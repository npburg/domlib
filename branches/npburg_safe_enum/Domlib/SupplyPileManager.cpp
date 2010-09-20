#include "StdAfx.h"
#include "SupplyPileManager.h"
#include "SupplyPile.h"
#include "Card.h"

namespace Domlib
{

SupplyPileManager::SupplyPileManager()
{
    m_pNullPile = new SupplyPile( CARDID::NULLCARD, 0 );
}

SupplyPileManager::~SupplyPileManager()
{
    for( SupplyPileMapIter iter = m_SupplyPiles.begin();
         iter != m_SupplyPiles.end();
         iter++ )
    {
        delete iter->second;
        m_SupplyPiles.erase( iter );
    }
    delete m_pNullPile;
}

void SupplyPileManager::AddPile( const CARDID cardId, const int cardsAvailable )
{
    m_SupplyPiles.insert( 
        std::pair<CARDID, SupplyPile*>( 
            cardId, 
            new SupplyPile( cardId, cardsAvailable ) ) );
}

const SupplyPile* SupplyPileManager::Find( const CARDID cardId ) const
{
    SupplyPileMapConstIter iter = m_SupplyPiles.find( cardId );

    if( iter != m_SupplyPiles.end() )
    {
        return iter->second;
    }

    return m_pNullPile;
}

SupplyPile* SupplyPileManager::Find( const CARDID cardId )
{
    SupplyPileMapIter iter = m_SupplyPiles.find( cardId );

    if( iter != m_SupplyPiles.end() )
    {
        return iter->second;
    }

    return m_pNullPile;
}

int SupplyPileManager::NumEmptyPiles( void ) const
{
    int numEmptyPiles = 0;

    for( SupplyPileMapConstIter iter = m_SupplyPiles.begin();
         iter != m_SupplyPiles.end();
         iter++ )
    {
        if( iter->second->CardsAvailable() <= 0 )
        {
            numEmptyPiles++;
        }
    }

    return numEmptyPiles;
}

bool SupplyPileManager::IsPileEmpty( const CARDID cardId ) const
{
    return ( this->CardsAvailable( cardId ) <= 0 );
}

int SupplyPileManager::CardsAvailable( const CARDID cardId ) const
{
    const SupplyPile* pSupplyPile = Find( cardId );
    return pSupplyPile->CardsAvailable();    
}

void SupplyPileManager::AddCard( const CARDID cardId )
{
    SupplyPile* pSupplyPile = Find( cardId );
    pSupplyPile->AddCard();
}

void SupplyPileManager::RemoveCard( const CARDID cardId )
{
    SupplyPile* pSupplyPile = Find( cardId );
    pSupplyPile->RemoveCard();
}

void SupplyPileManager::Clear()
{
    m_SupplyPiles.clear();
}

} // namespace Domlib