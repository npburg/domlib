#pragma once
#include "card.h"

namespace Domlib
{

class EmbargoCard :
    public Domlib::Card
{
public:
    virtual ~EmbargoCard( void );
    
    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    EmbargoCard( void );

    friend Card;
};

} // namespace Domlib