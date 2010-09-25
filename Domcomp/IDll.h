#pragma once
#include "Domlib.h"

class IDll
{
public:

    static bool Create(
                    const std::wstring& dll,
                    IDll* &pIDll );

    static bool Delete( IDll* &pIDll );

    bool    CreateAI( Domlib::AI* &pAI ) const;

    bool    DeleteAI( Domlib::AI* &pAI ) const;

private:

    IDll( void );

    ~IDll( void );

    bool    LoadDll( const std::wstring& dll );

    bool    UnloadDll( void );

    // DLL Handles
    HMODULE m_hModule;

    // Function pointers
    typedef bool (__cdecl  *FuncPtrCreateAI)( Domlib::AI* &pAI );
    typedef bool (__cdecl *FuncPtrDestroyAI)( Domlib::AI* &pAI );

    FuncPtrCreateAI     m_pFuncCreateAI;
    FuncPtrDestroyAI    m_pFuncDestroyAI;
};



// Error Utility
std::wstring GetWindowsErrorString( void );
