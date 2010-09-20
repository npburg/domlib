#pragma once
#include "card.h"

namespace Domlib
{

class RemodelCard :
    public Domlib::Card
{
public:
    virtual ~RemodelCard( void );

    void OnActionPhase( Engine* pEngine );

private:
    RemodelCard( void );

    friend Card;
};

} // namespace Domlib