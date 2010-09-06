#pragma once

#include "Action.h"
#include "Turn.h"

namespace Domlib
{

namespace BaseActions
{

template< int _TAmount >
class PlusActions
    :
    public Action
{
public:
    PlusActions( void )
    {

    };

    virtual ~PlusActions( void )
    {

    };

    virtual void Execute(
        Game* pGame,
        Turn* pTurn,
        Player* pPlayer )
    {
        pTurn->AddActions( _TAmount );
    }
};

}; // namespace Domlib::BaseActions

}; // namespace Domlib