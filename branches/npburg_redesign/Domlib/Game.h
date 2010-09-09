#pragma once

#include "Domlib.h"
#include "Engine.h"

namespace Domlib
{

class Game:
    public IGame
{
public:
    Game( void );
    virtual ~Game( void );

    // IGame Interfaces
    virtual void    RegisterAI( AI* pAi );
    virtual void    RandomizeKingdomCards( int cardSet );
    virtual void    Play( void );
    virtual void*   GetResults( void );

private:
    const Engine    m_Engine;
};

} // namespace Domlib