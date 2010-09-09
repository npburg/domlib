#pragma once
#include "card.h"

namespace Domlib
{

class TransmuteCard :
    public Domlib::Card
{
public:
    TransmuteCard( void );
    virtual ~TransmuteCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib