#include "stdafx.h"
#include "IDll.h"

bool IDll::Create(
    const std::wstring& dll,
    IDll* &pIDll )
{
    bool success = true;

    // Create and load DLL
    if( success )
    {
        pIDll = new IDll();

        success = pIDll->LoadDll( dll );
    }

    return success;
}

bool IDll::Delete( IDll* &pIDll )
{
    bool success = true;

    if( pIDll )
    {
        success = pIDll->UnloadDll();
    }

    if( success )
    {
        delete pIDll;
    }

    return success;
}

IDll::IDll( void )
    :
    m_hModule( NULL ),
    m_pFuncCreateAI( NULL ),
    m_pFuncDestroyAI( NULL )
{
}

IDll::~IDll( void )
{
}

bool IDll::LoadDll( const std::wstring& dll )
{
    bool success = true;

    // Load DLLs
    m_hModule = LoadLibrary( dll.c_str() );

    if( m_hModule == NULL )
    {
        success = false;
    }

    // Get CreateAI Procedure
    if( success )
    {
        m_pFuncCreateAI = (FuncPtrCreateAI)GetProcAddress(
            m_hModule,
            "CreateAI" );

        if( m_pFuncCreateAI == NULL )
        {
            success = false;
        }
    }

    // Get DestroyAI Procedure
    if( success )
    {
        m_pFuncDestroyAI = (FuncPtrDestroyAI)GetProcAddress(
            m_hModule,
            "DestroyAI" );

        if( m_pFuncDestroyAI == NULL )
        {
            success = false;
        }
    }

    return success;
}

bool IDll::UnloadDll( void )
{
    bool success = true;

    if( m_hModule != NULL )
    {
        if( !FreeLibrary( m_hModule ) )
        {
            success = false;
        }
        else
        {
            m_hModule           = NULL;
            m_pFuncCreateAI     = NULL;
            m_pFuncDestroyAI    = NULL;
        }
    }

    return success;
}

bool IDll::CreateAI( Domlib::AI* &pAI ) const
{
    bool success = true;

    if( m_pFuncCreateAI )
    {
        success = (m_pFuncCreateAI)(pAI);
    }
    else
    {
        success = false;
    }

    return success;
}

bool IDll::DeleteAI( Domlib::AI* &pAI ) const
{
    bool success = true;

    if( m_pFuncDestroyAI )
    {
        success = (m_pFuncDestroyAI)(pAI);
    }
    else
    {
        success = false;
    }

    return success;
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
