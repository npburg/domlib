#ifdef DOMAIDLL_EXPORTS
#define DOMAIDLL_API __declspec(dllexport)
#else
#define DOMAIDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif


DOMAIDLL_API void CreateAI( void );

DOMAIDLL_API void DestroyAI( void );


#ifdef __cplusplus
}
#endif
