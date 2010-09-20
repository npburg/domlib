#pragma once
#include "card.h"

namespace Domlib
{

class PearlDiverCard :
    public Domlib::Card
{
public:
    virtual ~PearlDiverCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    PearlDiverCard( void );

    friend Card;
};

} // namespace Domlib