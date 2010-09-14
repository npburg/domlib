#pragma once
#include "card.h"

namespace Domlib
{

class AlchemistCard :
    public Domlib::Card
{
public:
    AlchemistCard( void );
    virtual ~AlchemistCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib