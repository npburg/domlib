#pragma once
#include "card.h"

namespace Domlib
{

class UniversityCard :
    public Domlib::Card
{
public:
    UniversityCard( void );
    virtual ~UniversityCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib