// DominionAITester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Domlib.h"
//#include "BigMoneyAI.h"
#include "DefaultAI.h"

const int numGames = 1;

int _tmain(int argc, _TCHAR* argv[])
{
    Domlib::IGame game;

    game.RandomizeKingdomCards( Domlib::CARDSET::BASE | Domlib::CARDSET::INTRIGUE );

    // TODO: Need to implement BigMoneyAI or DefaultAI.
    game.RegisterAI( new DefaultAI() );
    game.RegisterAI( new DefaultAI() );
    game.RegisterAI( new DefaultAI() );
    game.RegisterAI( new DefaultAI() );

    game.Play();

    game.GetResults();

    return 0;
}

