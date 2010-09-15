#include "StdAfx.h"
#include "SupplyPile.h"

namespace Domlib
{

SupplyPile::SupplyPile( 
           const CARDID cardId,
           const int cardsAvailable
           )
{
    m_CardId            = cardId;
    m_CardsAvailable    = cardsAvailable;
    m_EmbargoTokens     = 0;
    m_TradeRouteToken   = 1;
}

CARDID SupplyPile::GetCardId( void ) const    
{ 
    return m_CardId; 
}

int SupplyPile::CardsAvailable( void ) const  
{ 
    return m_CardsAvailable; 
}

int SupplyPile::EmbargoTokens( void ) const  
{ 
    return m_EmbargoTokens; 
}

int SupplyPile::TradeRouteTokens( void ) const
{
    return m_TradeRouteToken;
}

void SupplyPile::AddCard( void )
{
    m_CardsAvailable++;
}

void SupplyPile::RemoveCard( void )
{
    if( m_CardsAvailable > 0 )
    {
        m_CardsAvailable--;
    }
    else
    {
        // TODO: Add error message
        throw std::wstring( L"Error: SupplyPile::RemoveCard" );
    }
}

void SupplyPile::AddEmbargoTokens( void ) 
{ 
    m_EmbargoTokens++; 
}

void SupplyPile::RemoveTradeRouteToken( void )
{
    if( m_TradeRouteToken > 0 )
    {
        m_TradeRouteToken = 0;
    }
}

} // namespace Domlib