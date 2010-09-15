#pragma once
#include "card.h"

namespace Domlib
{

class DukeCard :
    public Domlib::Card
{
public:
    virtual ~DukeCard( void );

    int OnScoring( Engine* pEngine );

private:
    DukeCard( void );

    friend Card;
};

} // namespace Domlib