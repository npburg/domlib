#pragma once
#include "card.h"

namespace Domlib
{

class HerbalistCard :
    public Domlib::Card
{
public:
    HerbalistCard( void );
    virtual ~HerbalistCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib