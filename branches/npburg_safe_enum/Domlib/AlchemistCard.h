#pragma once
#include "card.h"

namespace Domlib
{

class AlchemistCard :
    public Domlib::Card
{
public:
    virtual ~AlchemistCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    AlchemistCard( void );

    friend Card;
};

} // namespace Domlib