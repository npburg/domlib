#pragma once
#include "card.h"

namespace Domlib
{

class MineCard :
    public Domlib::Card
{
public:
    virtual ~MineCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    MineCard( void );

    friend Card;
};

} // namespace Domlib