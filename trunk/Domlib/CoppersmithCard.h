#pragma once
#include "card.h"

namespace Domlib
{

class CoppersmithCard :
    public Domlib::Card
{
public:
    virtual ~CoppersmithCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    CoppersmithCard( void );

    friend Card;
};

} // namespace Domlib