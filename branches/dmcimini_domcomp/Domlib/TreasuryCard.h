#pragma once
#include "card.h"

namespace Domlib
{

class TreasuryCard :
    public Domlib::Card
{
public:
    TreasuryCard( void );
    virtual ~TreasuryCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib