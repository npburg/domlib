#pragma once
#include "card.h"

namespace Domlib
{

class CityCard :
    public Domlib::Card
{
public:
    CityCard(void);
    virtual ~CityCard(void);
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib