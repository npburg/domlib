#pragma once
#include "card.h"

namespace Domlib
{

class SmugglersCard :
    public Domlib::Card
{
public:
    virtual ~SmugglersCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    SmugglersCard( void );

    friend Card;
};

} // namespace Domlib