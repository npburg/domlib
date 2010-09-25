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

    IDll* pDllInstance = NULL;
    Domlib::AI* pAIInstance = NULL;

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
    if( success )
    {
        success = IDll::Create( 
            L"DomAIDll.dll", 
            pDllInstance );
    }

    // Create AI Instance for that DLL
    if( success )
    {
        success = pDllInstance->CreateAI( pAIInstance );
    }

    // Delete AI Instance for that DLL
    if( success )
    {
        success = pDllInstance->DeleteAI( pAIInstance );
    }

    IDll::Delete( pDllInstance );

    if( !success )
    {
        retValue = -1;
    }

	return 0;
}

std::wstring GetWindowsErrorString( void )
{
    LPVOID lpMsgBuf;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        GetLastError(),
        MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),
        (LPTSTR) &lpMsgBuf,
        0,
        NULL );

    std::wstring errorString( (LPTSTR) lpMsgBuf );

    LocalFree(lpMsgBuf);
    return errorString;
}

