#pragma once
#include "card.h"

namespace Domlib
{

class TransmuteCard :
    public Domlib::Card
{
public:
    virtual ~TransmuteCard( void );

    void OnActionPhase( Engine* pEngine );
    
private:
    TransmuteCard( void );

    friend Card;
};

} // namespace Domlib