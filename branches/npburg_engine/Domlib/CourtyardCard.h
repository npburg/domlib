#pragma once
#include "card.h"

namespace Domlib
{

class CourtyardCard :
    public Domlib::Card
{
public:
    virtual ~CourtyardCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    CourtyardCard( void );

    friend Card;
};

} // namespace Domlib