#include "stdafx.h"
#include "Domlib.h"
#include "CommandlineArgs.h"

int _tmain( int argc, _TCHAR* argv[] )
{
    CommandlineSettings::PrintHelp( std::wcout );

    CommandlineSettings args;

    bool success = args.ParseCommandlineArguments( argc, argv );

    if( success )
    {

    }

	return 0;
}
