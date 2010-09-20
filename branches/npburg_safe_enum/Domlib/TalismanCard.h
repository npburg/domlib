#pragma once
#include "card.h"

namespace Domlib
{

class TalismanCard :
    public Domlib::Card
{
public:
    virtual ~TalismanCard(void);

    void OnCleanUpPhase( Engine* pEngine );

protected:
    TalismanCard(void);

    friend Card;
};

} // namespace Domlib