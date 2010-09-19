#pragma once
#include "card.h"

namespace Domlib
{

class TreasureMapCard :
    public Domlib::Card
{
public:
    virtual ~TreasureMapCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    TreasureMapCard( void );

    friend Card;
};

} // namespace Domlib