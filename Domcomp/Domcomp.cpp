#include "stdafx.h"
#include "Domlib.h"
#include "Domcomp.h"
#include "CommandlineArgs.h"
#include "IDll.h"

int _tmain( int argc, _TCHAR* argv[] )
{
    SetConsoleTitle( L"Domcomp" );

    int retValue = 0;

    CommandlineSettings args;
    bool success = args.ParseCommandlineArguments( argc, argv );

    // Print Help
    if( success )
    {
        if( args.PrintHelp )
        {
            CommandlineSettings::Help( std::wcout );
        }
    }

    // Load DLLs
    std::vector<IDll*> DLLs;

    if( success )
    {
        IDll* pDllInstance = NULL;

        std::vector<std::wstring>::const_iterator dllNameItr = args.DllList.begin();

        while( dllNameItr != args.DllList.end() && success )
        {
            success = IDll::Create( 
                *dllNameItr, 
                pDllInstance );

            if( success )
            {
                DLLs.push_back( pDllInstance );
            }

            dllNameItr++;
        }
    }

    // Run the game simulations
    if( success )
    {
        const int& GameCount    = args.GameCount;
        const int& RerunCount   = args.RerunCountPerGame;

        for( int i = 0; i < GameCount && success; i++ )
        {
            success = RunGame( DLLs );
        }
    }

    // Clean-up DLLs
    std::vector<IDll*>::iterator dllItr = DLLs.begin();
    while( dllItr != DLLs.end() )
    {
        IDll* pCurrentDLL = *dllItr;

        success = IDll::Delete( pCurrentDLL );

        dllItr++;
    }
    DLLs.clear();

    if( !success )
    {
        retValue = -1;
    }

	return 0;
}

bool RunGame(
    const std::vector<IDll*>& dllList )
{
    bool success = true;

    std::vector< std::pair< Domlib::AI*, IDll* > >   AIList;

    // Create one AI from each DLL
    std::vector<IDll*>::const_iterator curDllItr = dllList.begin();
    while( curDllItr != dllList.end() && success)
    {
        IDll* pCurrentDLL = *curDllItr;
        
        Domlib::AI* newAI = NULL;

        success = pCurrentDLL->CreateAI( newAI );

        if( success )
        {
            AIList.push_back( std::pair< Domlib::AI*, IDll* >( newAI, pCurrentDLL ) );
        }

        curDllItr++;
    }

    // Execute the Game
    if( success )
    {

    }

    // Clean-UP the AIs
    std::vector< std::pair< Domlib::AI*, IDll* > >::iterator aiItr = AIList.begin();
    while( aiItr != AIList.end() )
    {
        std::pair< Domlib::AI*, IDll* > currentAiDLL = *aiItr;

        Domlib::AI* pChildAI    = currentAiDLL.first;
        IDll*       pParentAI   = currentAiDLL.second;

        success = pParentAI->DeleteAI( pChildAI );

        aiItr++;
    }
    AIList.clear();

    return success;
}