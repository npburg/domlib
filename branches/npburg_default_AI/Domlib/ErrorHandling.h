#pragma once

// Basic library specific assert macro
#if defined(_DEBUG) || defined( DEBUG )
    #define DOMLIB_ASSERT( x )  \
        do                      \
        {                       \
            if( ( x ) != true ) \
            {                   \
                __debugbreak(); \
            }                   \
        } while( false )
#else
    #define DOMLIB_ASSERT( x )
#endif

// Convenience macro for notification of unimplemented code
#define DOMLIB_NOT_IMPLEMENTED  DOMLIB_ASSERT( 0 )

namespace Domlib
{

}; // namespace Domlib