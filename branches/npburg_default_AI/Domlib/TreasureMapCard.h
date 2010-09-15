#pragma once
#include "card.h"

namespace Domlib
{

class TreasureMapCard :
    public Domlib::Card
{
public:
    TreasureMapCard( void );
    virtual ~TreasureMapCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib