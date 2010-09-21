#include "stdafx.h"
#include "Domlib.h"
#include "Domcomp.h"
#include "CommandlineArgs.h"

int _tmain( int argc, _TCHAR* argv[] )
{
    SetConsoleTitle( L"Domcomp" );

    int retValue = 0;
    CommandlineSettings args;

    bool success = args.ParseCommandlineArguments( argc, argv );

    if( success )
    {
        if( args.PrintHelp )
        {
            CommandlineSettings::Help( std::wcout );
        }
        else
        {
            // Load DLLs
            HMODULE hDllHandle = LoadLibrary( L"DomcompDLL.dll" );

            if( hDllHandle != NULL )
            {
                FuncPtrCreateAI pCreateAI = NULL;
                FuncPtrDestroyAI pDestroyAI = NULL;

                // Get CreateAI Procedure
                if( success )
                {
                    pCreateAI = (FuncPtrCreateAI)GetProcAddress(
                        hDllHandle,
                        "CreateAI" );

                    if( pCreateAI == NULL )
                    {
                        std::wcout << L"Error resolving CreateAI DLL procedure" << std::endl;
                        std::wcout << GetWindowsErrorString() << std::endl;
                        success = false;
                    }
                }

                // Get DestroyAI Procedure
                if( success )
                {
                    pDestroyAI = (FuncPtrDestroyAI)GetProcAddress(
                        hDllHandle,
                        "DestroyAI" );

                    if( pDestroyAI == NULL )
                    {
                        std::wcout << L"Error resolving DestroyAI DLL procedure" << std::endl;
                        std::wcout << GetWindowsErrorString() << std::endl;
                        success = false;
                    }
                }

                // Test Callbacks
                if( success )
                {
                    (pCreateAI)();
                    (pCreateAI)();
                }

                FreeLibrary( hDllHandle );
                pCreateAI = NULL;
                pDestroyAI = NULL;
            }
            else
            {
                success = false;
            }
        }
    }

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

