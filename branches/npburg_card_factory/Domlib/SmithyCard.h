#pragma once
#include "card.h"

namespace Domlib
{

class SmithyCard :
    public Domlib::Card
{
public:
    virtual ~SmithyCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    SmithyCard( void );

    friend Card;
};

} // namespace Domlib