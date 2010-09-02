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

    virtual void Execute( Turn* turn )
    {
        // TBD
    }
};

}; // namespace Domlib::BaseActions

}; // namespace Domlib