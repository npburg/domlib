#pragma once

// DLL Function Pointer Typedefs
typedef void (__cdecl *FuncPtrCreateAI)(void);
typedef void (__cdecl *FuncPtrDestroyAI)(void);

// Error Utility
std::wstring GetWindowsErrorString( void );