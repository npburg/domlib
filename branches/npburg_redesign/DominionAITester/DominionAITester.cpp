// DominionAITester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Domlib.h"
#include "BigMoneyAI.h"

const int numGames = 1;

int _tmain(int argc, _TCHAR* argv[])
{
    Domlib::IGame* pGame = Domlib::CreateGame();

    pGame->RandomizeKingdomCards( Domlib::CARDSET_BASE | Domlib::CARDSET_INTRIGUE );

    // TODO: Need to implement BigMoneyAI or DefaultAI.
    //pGame->RegisterAI( new BigMoneyAI() );
    //pGame->RegisterAI( new BigMoneyAI() );
    //pGame->RegisterAI( new BigMoneyAI() );
    //pGame->RegisterAI( new BigMoneyAI() );

    pGame->Play();

    pGame->GetResults();

	return 0;
}

