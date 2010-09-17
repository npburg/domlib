#pragma once
#include "card.h"

namespace Domlib
{

class PearlDiverCard :
    public Domlib::Card
{
public:
    PearlDiverCard( void );
    virtual ~PearlDiverCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib