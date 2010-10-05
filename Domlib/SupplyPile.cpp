#include "StdAfx.h"
#include "SupplyPile.h"
#include "Card.h"

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
    if( Card::GetCard( cardId )->IsVictoryCard() )
    {
        m_TradeRouteToken = 1;
    }
    else
    {
        m_TradeRouteToken = 0;
    }
    m_ContrabandFlag    = false;
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

bool SupplyPile::IsEmpty( void ) const
{
    if( m_CardsAvailable > 0 )
    {
        return false;
    }

    return true;
}

void SupplyPile::SetSize( int quantity )
{
    m_CardsAvailable = quantity;
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

void SupplyPile::AddEmbargoToken( void ) 
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

void SupplyPile::SetContrabandFlag( bool flag )
{
    m_ContrabandFlag = flag;
}

} // namespace Domlib