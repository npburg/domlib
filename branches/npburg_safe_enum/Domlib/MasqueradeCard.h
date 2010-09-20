#pragma once
#include "card.h"

namespace Domlib
{

class MasqueradeCard :
    public Domlib::Card
{
public:
    virtual ~MasqueradeCard( void );

    void OnActionPhase( Engine* pEngine );

private: 
    MasqueradeCard( void );

    friend Card;
};

} // namespace Domlib