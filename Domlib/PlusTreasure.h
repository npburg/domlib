#pragma once

#include "Action.h"
#include "Turn.h"

namespace Domlib
{

namespace BaseActions
{

template< int _TAmount >
class PlusTreasure
    :
    public Action
{
public:
    PlusTreasure( void )
    {

    };

    virtual ~PlusTreasure( void )
    {

    };

    virtual void Execute( Turn* turn )
    {
        // TBD
    }
};

}; // namespace Domlib::BaseActions

}; // namespace Domlib