#pragma once
#include "card.h"

namespace Domlib
{

class TacticianCard :
    public Domlib::Card
{
public:
    TacticianCard( void );
    virtual ~TacticianCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );
};

} // namespace Domlib