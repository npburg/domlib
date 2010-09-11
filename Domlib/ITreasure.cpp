#include "StdAfx.h"
#include "Domlib.h"
#include "Treasure.h"

namespace Domlib
{

ITreasure::ITreasure( void )
{
    m_pTreasure = new Treasure();
}

ITreasure::ITreasure( const Treasure& treasure )
{
    m_pTreasure = new Treasure( treasure );
}


ITreasure::ITreasure( const int coins, const int potions )
{
    m_pTreasure = new Treasure(coins, potions);
}

ITreasure::~ITreasure( void )
{
    delete m_pTreasure;
}

const ITreasure ITreasure::operator+  (const ITreasure t) const
{
    ITreasure result;
    
    *result.m_pTreasure = *m_pTreasure + *t.m_pTreasure;
    
    return result;
}

ITreasure ITreasure::operator+= (const ITreasure t)
{
    *m_pTreasure += *t.m_pTreasure;
    
    return *this;
}

const ITreasure ITreasure::operator-  (const ITreasure t) const
{
    ITreasure result;
    
    *result.m_pTreasure = *m_pTreasure - *t.m_pTreasure;
    
    return result;
}

ITreasure ITreasure::operator-= (const ITreasure t)
{
    *m_pTreasure -= *t.m_pTreasure;
    
    return *this;
}


const bool ITreasure::operator<  (const ITreasure t) const
{
    return ( *m_pTreasure < *t.m_pTreasure );
}

const bool ITreasure::operator<= (const ITreasure t) const
{
    return ( *m_pTreasure <= *t.m_pTreasure );
}

const bool ITreasure::operator>  (const ITreasure t) const
{
    return ( *m_pTreasure > *t.m_pTreasure );
}

const bool ITreasure::operator>= (const ITreasure t) const
{
    return ( *m_pTreasure >= *t.m_pTreasure );
}

const bool ITreasure::operator== (const ITreasure t) const
{
    return ( *m_pTreasure == *t.m_pTreasure );
}


const bool ITreasure::operator!= (const ITreasure t) const
{
    return ( *m_pTreasure != *t.m_pTreasure );
}

int ITreasure::Coins( void ) const
{
    return m_pTreasure->Coins();
}

int ITreasure::Potions( void ) const
{
    return m_pTreasure->Potions();
}

} // namespace Domlib