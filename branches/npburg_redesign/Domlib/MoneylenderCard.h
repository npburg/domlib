#pragma once
#include "card.h"

namespace Domlib
{

class MoneylenderCard :
    public Domlib::Card
{
public:
    virtual ~MoneylenderCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    MoneylenderCard( void );

    friend Card;
};

} // namespace Domlib