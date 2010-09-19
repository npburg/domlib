#pragma once
#include "card.h"

namespace Domlib
{

class NoblesCard :
    public Domlib::Card
{
public:
    virtual ~NoblesCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    NoblesCard( void );

    friend Card;
};

} // namespace Domlib