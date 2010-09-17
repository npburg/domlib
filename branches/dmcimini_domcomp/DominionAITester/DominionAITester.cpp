#include "stdafx.h"
#include "Domlib.h"
#include "DefaultAI.h"

int _tmain( int argc, _TCHAR* argv[] )
{
    Domlib::IGame game;

    game.RandomizeKingdomCards( Domlib::CARDSET_BASE | Domlib::CARDSET_INTRIGUE );

    game.RegisterAI( new DefaultAI() );
    game.RegisterAI( new DefaultAI() );
    game.RegisterAI( new DefaultAI() );
    game.RegisterAI( new DefaultAI() );

    game.Play();

    game.GetResults();

    return 0;
}

