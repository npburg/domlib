#pragma once
#include "card.h"

namespace Domlib
{

class BaronCard :
    public Domlib::Card
{
public:
    BaronCard( void );
    virtual ~BaronCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib