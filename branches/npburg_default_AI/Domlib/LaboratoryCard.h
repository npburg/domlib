#pragma once
#include "card.h"

namespace Domlib
{

class LaboratoryCard :
    public Domlib::Card
{
public:
    virtual ~LaboratoryCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    LaboratoryCard( void );

    friend Card;
};

} // namespace Domlib