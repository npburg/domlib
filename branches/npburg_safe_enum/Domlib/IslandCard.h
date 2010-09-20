#pragma once
#include "card.h"

namespace Domlib
{

class IslandCard :
    public Domlib::Card
{
public:
    virtual ~IslandCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    IslandCard( void );

    friend Card;
};

} // namespace Domlib