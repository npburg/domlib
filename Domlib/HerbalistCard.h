#pragma once
#include "card.h"

namespace Domlib
{

class HerbalistCard :
    public Domlib::Card
{
public:
    virtual ~HerbalistCard( void );

    void OnActionPhase( Engine* pEngine );
    void OnCleanUpPhase( Engine* pEngine );

private:
    HerbalistCard( void );

    friend Card;
};

} // namespace Domlib