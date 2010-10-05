#pragma once
#include "card.h"

namespace Domlib
{

class TreasuryCard :
    public Domlib::Card
{
public:
    virtual ~TreasuryCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    TreasuryCard( void );

    friend Card;
};

} // namespace Domlib