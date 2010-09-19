#pragma once
#include "card.h"

namespace Domlib
{

class ExplorerCard :
    public Domlib::Card
{
public:
    virtual ~ExplorerCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    ExplorerCard( void );

    friend Card;
};

} // namespace Domlib