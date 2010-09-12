#pragma once
#include "card.h"

namespace Domlib
{

class HoardCard :
    public Domlib::Card
{
public:
    HoardCard(void);
    virtual ~HoardCard(void);

    void OnCleanUpPhase( Engine* pEngine );
};

} // namespace Domlib