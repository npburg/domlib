#ifdef DOMCOMPDLL_EXPORTS
#define DOMCOMPDLL_API __declspec(dllexport)
#else
#define DOMCOMPDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif


DOMCOMPDLL_API void CreateAI( void );

DOMCOMPDLL_API void DestroyAI( void );


#ifdef __cplusplus
}
#endif
