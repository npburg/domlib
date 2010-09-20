#pragma once
#include "card.h"

namespace Domlib
{

class BaronCard :
    public Domlib::Card
{
public:
    virtual ~BaronCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    BaronCard( void );

    friend Card;
};

} // namespace Domlib