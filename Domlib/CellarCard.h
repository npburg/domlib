#pragma once

#include "Card.h"

namespace Domlib
{

class CellarCard :
    public Domlib::Card
{
public:
    virtual ~CellarCard();

    void OnActionPhase( Engine* pEngine );

private:
    CellarCard( void );

    friend Card;
};

} // namespace Domlib