#include "StdAfx.h"
#include "Treasure.h"

namespace Domlib
{

Treasure::Treasure( void )
{
}


Treasure::Treasure( const ITreasure& treasure )
    :
    m_Coins( treasure.Coins() ),
    m_Potions( treasure.Potions() )
{
}


Treasure::Treasure( const int coins, const int potions )
    :
    m_Coins( coins ),
    m_Potions( potions )
{
}


Treasure::~Treasure( void )
{
}


const Treasure Treasure::operator+  (const Treasure t) const
{
    Treasure result;

    result.m_Coins    = m_Coins + t.m_Coins;
    result.m_Potions  = m_Potions + t.m_Potions;

    return result;
}


Treasure Treasure::operator+= (const Treasure t)
{
    m_Coins     += t.m_Coins;
    m_Potions   += t.m_Potions;
    
    return *this;
}


const Treasure Treasure::operator-  (const Treasure t) const
{
    Treasure result;
    
    result.m_Coins      = this->m_Coins - t.m_Coins;
    result.m_Potions    = this->m_Potions - t.m_Potions;
    
    return result;
}


Treasure Treasure::operator-= (const Treasure t)
{
    m_Coins     -= t.m_Coins;
    m_Potions   -= t.m_Potions;

    return *this;
}


const bool Treasure::operator<  (const Treasure t) const
{
    return ( m_Coins < t.m_Coins ) && ( m_Potions < t.m_Potions );
}


const bool Treasure::operator<= (const Treasure t) const
{
    return ( m_Coins <= t.m_Coins ) && ( m_Potions <= t.m_Potions );
}


const bool Treasure::operator>  (const Treasure t) const
{
    return ( m_Coins > t.m_Coins ) && ( m_Potions > t.m_Potions );
}


const bool Treasure::operator>= (const Treasure t) const
{
    return ( m_Coins >= t.m_Coins ) && ( m_Potions >= t.m_Potions );
}


const bool Treasure::operator== (const Treasure t) const
{
    return ( m_Coins == t.m_Coins ) && ( m_Potions == t.m_Potions );
}


const bool Treasure::operator!= (const Treasure t) const
{
    return ( m_Coins != t.m_Coins ) && ( m_Potions != t.m_Potions );
}


int Treasure::Coins( void ) const
{
    return m_Coins;
}


int Treasure::Potions( void ) const
{
    return m_Potions;
}


} // namespace Domlib