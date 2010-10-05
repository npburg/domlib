#pragma once
#include "Domlib.h"

namespace Domlib
{

class SupplyPile
{
public:
    SupplyPile( const CARDID cardId, const int CardsAvailable );
    ~SupplyPile( void ) {};

    CARDID GetCardId( void ) const;
    int    CardsAvailable( void ) const;
    int    EmbargoTokens( void ) const;
    int    TradeRouteTokens( void ) const;
    bool   IsEmpty( void ) const;

    void SetSize( int );
    void AddCard( void );
    void RemoveCard( void );
    void AddEmbargoToken( void );
    void RemoveTradeRouteToken( void );
    void SetContrabandFlag( bool flag );
    
private:
    CARDID  m_CardId;
    int     m_CardsAvailable;
    int     m_EmbargoTokens;
    int     m_TradeRouteToken;
    bool    m_ContrabandFlag;
};

} // namespace Domlib