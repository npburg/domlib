#pragma once
#include "card.h"

namespace Domlib
{

class CoppersmithCard :
    public Domlib::Card
{
public:
    CoppersmithCard( void );
    virtual ~CoppersmithCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib