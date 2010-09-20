#pragma once
#include "card.h"

namespace Domlib
{

class WharfCard :
    public Domlib::Card
{
public:
    virtual ~WharfCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnDurationPhase( Engine* pEngine );

private:
    WharfCard( void );

    friend Card;
};

} // namespace Domlib