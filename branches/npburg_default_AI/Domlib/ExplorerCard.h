#pragma once
#include "card.h"

namespace Domlib
{

class ExplorerCard :
    public Domlib::Card
{
public:
    ExplorerCard( void );
    virtual ~ExplorerCard( void );
    
    void OnActionPhase( Engine* pEngine );
};

} // namespace Domlib