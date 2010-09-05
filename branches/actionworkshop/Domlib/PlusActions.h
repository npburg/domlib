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

    virtual void Execute( Turn* turn )
    {
        turn->AddActions( _TAmount );
    }
};

}; // namespace Domlib::BaseActions

}; // namespace Domlib