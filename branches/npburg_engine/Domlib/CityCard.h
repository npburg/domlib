#pragma once
#include "card.h"

namespace Domlib
{

class CityCard :
    public Domlib::Card
{
public:
    virtual ~CityCard(void);
    
    void OnActionPhase( Engine* pEngine );

private:
    CityCard(void);

    friend Card;
};

} // namespace Domlib