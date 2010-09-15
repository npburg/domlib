#pragma once
#include "card.h"

namespace Domlib
{

class WorkshopCard :
    public Domlib::Card
{
public:
    virtual ~WorkshopCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    WorkshopCard( void );

    friend Card;
};

} // namespace Domlib