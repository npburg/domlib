#pragma once
#include "card.h"

namespace Domlib
{

class FestivalCard :
    public Domlib::Card
{
public:
    virtual ~FestivalCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    FestivalCard( void );

    friend Card;
};

} // namespace Domlib