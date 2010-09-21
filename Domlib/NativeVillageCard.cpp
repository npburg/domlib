#include "StdAfx.h"
#include "NativeVillageCard.h"

namespace Domlib
{

NativeVillageCard::NativeVillageCard( void )
    : Card( 
        L"Native Village",
        CARDID::NATIVEVILLAGE,
        CARDTYPE::ACTION,
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
    IAI* pAI = pPlayer->GetAI();
    
    pPlayer->PlusActions( 2 );
    NativeVillageOpt nativeVillageOpt = pAI->OnNativeVillage();
    
    switch( nativeVillageOpt )
    {
    case NativeVillageOpt::DRAW_CARDS:
        pPlayer->DrawCardsFromNativeVillage();
        break;
    case NativeVillageOpt::SET_ASIDE_CARD:
        pPlayer->DrawCardToNativeVillage();
        break;
    default:
        // TODO: report error
        throw std::wstring( L"Error: NativeVillageCard::OnActionPhase" );
        break;
    }    
}

} // namespace Domlib