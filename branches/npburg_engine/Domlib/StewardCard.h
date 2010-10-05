#pragma once
#include "card.h"

namespace Domlib
{

class StewardCard :
    public Domlib::Card
{
public:
    virtual ~StewardCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    StewardCard( void );

    friend Card;
};

} // namespace Domlib