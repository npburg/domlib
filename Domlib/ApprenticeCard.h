#pragma once
#include "card.h"

namespace Domlib
{

class ApprenticeCard :
    public Domlib::Card
{
public:
    ApprenticeCard( void );
    virtual ~ApprenticeCard( void );

    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib