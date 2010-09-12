#pragma once

#include "Domlib.h"
#include "Engine.h"

namespace Domlib
{

class Game
{
public:
    Game( void );
    virtual ~Game( void );

    // IGame Interfaces
    void    RegisterAI( AI* pAI );
    void    RandomizeKingdomCards( int cardSet );
    void    Play( void );
    void*   GetResults( void );

private:
    const Engine    m_Engine;
};

} // namespace Domlib