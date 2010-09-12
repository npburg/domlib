#include "StdAfx.h"
#include "NativeVillageCard.h"

namespace Domlib
{

NativeVillageCard::NativeVillageCard( void )
    : Card( 
        L"Native Village",
        CARDID_NATIVEVILLAGE,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 2, 0 ) )
{
}

NativeVillageCard::~NativeVillageCard( void )
{
}

void NativeVillageCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    
    pPlayer->PlusActions( 2 );
    NativeVillageOpt nativeVillageOpt = pAi->OnNativeVillage();
    
    switch( nativeVillageOpt )
    {
    case NATIVEVILLAGE_DRAW_CARDS:
        pPlayer->DrawCardsFromNativeVillage();
        break;
    case NATIVEVILLAGE_SET_ASIDE_CARD:
        pPlayer->DrawCardToNativeVillage();
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: NativeVillageCard::OnActionPhase" );
        break;
    }    
}

} // namespace Domlib