#pragma once
#include "card.h"

namespace Domlib
{

class ApprenticeCard :
    public Domlib::Card
{
public:
    virtual ~ApprenticeCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    ApprenticeCard( void );

    friend Card;
};

} // namespace Domlib