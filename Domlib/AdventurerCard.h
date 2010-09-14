#pragma once
#include "card.h"

namespace Domlib
{

class AdventurerCard :
    public Domlib::Card
{
public:
    virtual ~AdventurerCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    AdventurerCard( void );

    friend Card;
};

} // namespace Domlib