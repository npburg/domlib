#pragma once

#include "Card.h"
#include "Game.h"
#include "Player.h"

namespace Domlib
{

class Turn;

class Village
    :
    public Card
{
public:

    Village( void )
        :
        Card( CARDID_VILLAGE, true, false, false, 3, 0 )
    {
        AddBaseAction( new BaseActions::PlusCards<1>() );
        AddBaseAction( new BaseActions::PlusActions<2>() );
    }

    virtual ~Village( void )
    {
    }

};

}; // namespace Domlib