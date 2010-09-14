#pragma once

namespace Domlib
{

enum CARDID;

class SupplyPile
{
public:
    SupplyPile( const CARDID cardId, const int CardsAvailable );
    ~SupplyPile( void ) {};

    CARDID GetCardId( void ) const;
    int CardsAvailable( void ) const;
    int EmbargoTokens( void ) const;
    int TradeRouteTokens( void ) const;

    void AddCard( void );
    void RemoveCard( void );
    void AddEmbargoTokens( void );
    void RemoveTradeRouteToken( void );
    
private:
    CARDID m_CardId;
    int m_CardsAvailable;
    int m_EmbargoTokens;
    int m_TradeRouteToken;
};

} // namespace Domlib