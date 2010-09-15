#pragma once
#include "card.h"

namespace Domlib
{

class TacticianCard :
    public Domlib::Card
{
public:
    virtual ~TacticianCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    TacticianCard( void );

    friend Card;
};

} // namespace Domlib