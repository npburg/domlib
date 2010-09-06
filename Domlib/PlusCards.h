#pragma once

#include "Action.h"
#include "Turn.h"

namespace Domlib
{

namespace BaseActions
{

template< int _TAmount >
class PlusCards
    :
    public Action
{
public:
    PlusCards( void )
    {

    };

    virtual ~PlusCards( void )
    {

    };

    virtual void Execute(
        Game* pGame,
        Turn* pTurn,
        Player* pPlayer )
    {
        // TBD
    }
};

}; // namespace Domlib::BaseActions

}; // namespace Domlib