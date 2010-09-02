#pragma once

#include "Action.h"
#include "Turn.h"

namespace Domlib
{

namespace BaseActions
{

template< int _TAmount >
class PlusBuys
    :
    public Action
{
public:
    PlusBuys( void )
    {

    };

    virtual ~PlusBuys( void )
    {

    };

    virtual void Execute( Turn* turn )
    {
        turn->AddBuys( _TAmount );
    }
};

}; // namespace Domlib::BaseActions

}; // namespace Domlib