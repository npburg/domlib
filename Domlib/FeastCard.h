#pragma once
#include "card.h"

namespace Domlib
{

class FeastCard :
    public Domlib::Card
{
public:
    virtual ~FeastCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    FeastCard( void );
    
    friend Card;
};

} // namespace Domlib