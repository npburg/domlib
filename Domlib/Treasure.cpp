#include "StdAfx.h"
#include "Domlib.h"

namespace Domlib
{

Treasure::Treasure( int coins, int potions )
    :
    m_Coins( coins ),
    m_Potions( potions )
{
}

Treasure::~Treasure( void )
{
}

} // namespace Domlib