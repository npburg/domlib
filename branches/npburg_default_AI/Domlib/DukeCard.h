#pragma once
#include "card.h"

namespace Domlib
{

class DukeCard :
    public Domlib::Card
{
public:
    DukeCard( void );
    virtual ~DukeCard( void );

    int OnScoring( Engine* pEngine );
};

} // namespace Domlib