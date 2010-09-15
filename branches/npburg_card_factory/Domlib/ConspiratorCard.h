#pragma once
#include "card.h"

namespace Domlib
{

class ConspiratorCard :
    public Domlib::Card
{
public:
    virtual ~ConspiratorCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ConspiratorCard( void );

    friend Card;
};

} // namespace Domlib