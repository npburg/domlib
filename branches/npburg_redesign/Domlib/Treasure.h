#pragma once

#include "Domlib.h"

namespace Domlib
{

class Treasure
    : public ITreasure
{
public:
    Treasure( int coins, int potions );
    virtual ~Treasure( void );

    virtual Treasure operator+  (const Treasure t) const;
    virtual Treasure operator+= (const Treasure t);
    virtual Treasure operator-  (const Treasure t) const;
    virtual Treasure operator-= (const Treasure t);

    virtual bool     operator<  (const Treasure t) const;
    virtual bool     operator<= (const Treasure t) const;
    virtual bool     operator>  (const Treasure t) const;
    virtual bool     operator>= (const Treasure t) const;
    virtual bool     operator== (const Treasure t) const;
    virtual bool     operator!= (const Treasure t) const;

    virtual int      Coins( void ) const;
    virtual int      Potions( void ) const;

private:
    int m_Coins;
    int m_Potions;
};

} // namespace Domlib