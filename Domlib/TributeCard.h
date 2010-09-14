#pragma once
#include "card.h"

namespace Domlib
{

class TributeCard :
    public Domlib::Card
{
public:
    TributeCard( void );
    virtual ~TributeCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib