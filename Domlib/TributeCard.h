#pragma once
#include "card.h"

namespace Domlib
{

class TributeCard :
    public Domlib::Card
{
public:
    virtual ~TributeCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    TributeCard( void );

    friend Card;
};

} // namespace Domlib