#pragma once
#include "card.h"

namespace Domlib
{

class UniversityCard :
    public Domlib::Card
{
public:
    virtual ~UniversityCard( void );

    void OnActionPhase( Engine* pEngine );
    
private:
    UniversityCard( void );

    friend Card;
};

} // namespace Domlib