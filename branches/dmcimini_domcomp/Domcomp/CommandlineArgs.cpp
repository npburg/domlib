#include "stdafx.h"
#include "CommandlineArgs.h"

bool CommandlineSettings::ParseCommandlineArguments(
    int argc,
    _TCHAR* argv[] )
{
    bool success = true;

    CommandlineArgumentList commandLineArguments;

    for( int i = 1; i < argc; i++ )
    {
        commandLineArguments.push_back( std::wstring( argv[ i ] ) );
    }

    CommandlineArgumentList::iterator argItr = commandLineArguments.begin();
    while( argItr != commandLineArguments.end() )
    {
        std::wstring currentArgument = *argItr;

        if( currentArgument == L"-b" )
        {
            SelectedCardSets.Base = true;
        }
        else if( currentArgument == L"-i" )
        {
            SelectedCardSets.Intrigue = true;
        }
        else if( currentArgument == L"-s" )
        {
            SelectedCardSets.Seaside = true;
        }
        else if( currentArgument == L"-a" )
        {
            SelectedCardSets.Alchemy = true;
        }
        else if( currentArgument == L"-p" )
        {
            SelectedCardSets.Prosperity = true;
        }
        else if( currentArgument == L"-x" )
        {
            SelectedCardSets.Alchemy = true;
            SelectedCardSets.Base = true;
            SelectedCardSets.Intrigue = true;
            SelectedCardSets.Prosperity = true;
            SelectedCardSets.Seaside = true;
        }
        else if( currentArgument == L"-h" )
        {
            PrintHelp = true;
        }
        else if( currentArgument == L"-g" )
        {
            argItr++;

            std::wistringstream intStream( *argItr );
            intStream >> GameCount;
        }
        else if( currentArgument == L"-r" )
        {
            argItr++;

            std::wistringstream intStream( *argItr );
            intStream >> RerunCountPerGame;
        }
        else
        {
            // Must be a dll
            DllList.push_back( currentArgument );
        }

        argItr++;
    }

    if( success )
    {
        success = Validate();
    }

    return success;
}

void CommandlineSettings::Help( std::wostream& out )
{
    out << L"Domcomp.exe [args] a.dll b.dll ..." << std::endl;
    out << std::endl;
    out << L"Game Controls (required)" << std::endl;
    out << L"    -g X    Run X games." << std::endl;
    out << L"    -r Y    Run an individual game Y times ( default = 1 )" << std::endl;
    out << std::endl;
    out << L"Card Sets (optional)" << std::endl;
    out << L"    -b      Use Base cards" << std::endl;
    out << L"    -i      Use Intrigue cards" << std::endl;
    out << L"    -s      Use Seaside cards" << std::endl;
    out << L"    -a      Use Alchemy cards" << std::endl;
    out << L"    -p      Use Prosperity cards" << std::endl;
    out << L"    -x      Use All cards ( default )" << std::endl;
    out << std::endl;
    out << L"Notes:" << std::endl;
    out << L"At least two DLLs are required. To run the same DLL against itself, specify" << std::endl;
    out << L"same DLL name multiple times." << std::endl;
    out << std::endl;
    out << L"Samples:" << std::endl;
    out << L"Domcomp.exe -g 100000 -r 100 A.dll B.dll C.dll" << std::endl;
    out << L"    Run 100,000 games," << std::endl;
    out << L"    Re-running each game 100 times," << std::endl;
    out << L"    Using all decks," << std::endl;
    out << L"    With competitor AIs A, B, C." << std::endl;
    out << std::endl;
    out << L"Domcomp.exe -g 1000 A.dll A.dll A.dll" << std::endl;
    out << L"    Run 1,000 games," << std::endl;
    out << L"    Re-running each game once," << std::endl;
    out << L"    Using all decks," << std::endl;
    out << L"    With the same three competitor AIs." << std::endl;
    out << std::endl;
    out << L"DomComp.exe -g 1000 -b -i A.dll B.dll C.dll" << std::endl;
    out << L"    Run 1,000 games," << std::endl;
    out << L"    Re-running each game once," << std::endl;
    out << L"    Using only Base and Intrigue cards," << std::endl;
    out << L"    With competitor AIs A, B, C." << std::endl;
}

bool CommandlineSettings::Validate( void )
{
    bool success = true;

    // If no card set selected, default to all
    if( !SelectedCardSets.Base &&
        !SelectedCardSets.Alchemy &&
        !SelectedCardSets.Intrigue &&
        !SelectedCardSets.Prosperity &&
        !SelectedCardSets.Seaside )
    {
        SelectedCardSets.Alchemy = true;
        SelectedCardSets.Base = true;
        SelectedCardSets.Intrigue = true;
        SelectedCardSets.Prosperity = true;
        SelectedCardSets.Seaside = true;
    }

    return success;
}

