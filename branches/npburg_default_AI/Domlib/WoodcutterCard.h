#pragma once
#include "card.h"

namespace Domlib
{

class WoodcutterCard :
    public Domlib::Card
{
public:
    virtual ~WoodcutterCard( void );
    
    void OnActionPhase( Engine* pEngine );

private:
    WoodcutterCard( void );

    friend Card;
};

} // namespace Domlib