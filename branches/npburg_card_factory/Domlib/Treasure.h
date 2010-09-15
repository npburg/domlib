#pragma once

#include "Domlib.h"

namespace Domlib
{

class Treasure
{
public:
    Treasure( void );
    //Treasure( Treasure& treasure );
    Treasure( const int coins, const int potions );
    virtual ~Treasure( void );

    const Treasure operator+  (const Treasure t) const;
          Treasure operator+= (const Treasure t);
    const Treasure operator-  (const Treasure t) const;
          Treasure operator-= (const Treasure t);

    const bool     operator<  (const Treasure t) const;
    const bool     operator<= (const Treasure t) const;
    const bool     operator>  (const Treasure t) const;
    const bool     operator>= (const Treasure t) const;
    const bool     operator== (const Treasure t) const;
    const bool     operator!= (const Treasure t) const;

    int      Coins( void ) const;
    int      Potions( void ) const;

private:
    int m_Coins;
    int m_Potions;
};

} // namespace Domlib