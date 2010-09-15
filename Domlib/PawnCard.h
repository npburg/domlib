#pragma once
#include "card.h"

namespace Domlib
{

class PawnCard :
    public Domlib::Card
{
public:
    virtual ~PawnCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    PawnCard( void );

    friend Card;
};

} // namespace Domlib