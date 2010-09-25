#include "Domlib.h"

#ifdef DOMAIDLL_EXPORTS
#define DOMAIDLL_API __declspec(dllexport)
#else
#define DOMAIDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

DOMAIDLL_API bool CreateAI( Domlib::AI* &pAI );

DOMAIDLL_API bool DestroyAI( Domlib::AI* &pAI );

#ifdef __cplusplus
}
#endif
