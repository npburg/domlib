#pragma once
#include "card.h"

namespace Domlib
{

class CourtyardCard :
    public Domlib::Card
{
public:
    CourtyardCard( void );
    virtual ~CourtyardCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib