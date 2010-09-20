#include "StdAfx.h"
#include "MintCard.h"

namespace Domlib
{

MintCard::MintCard(void)
    : Card( 
        L"Mint",
        CARDID::MINT,
        CARDTYPE::ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 5, 0 ) )
{
}

MintCard::~MintCard(void)
{
}

void MintCard::OnActionPhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    
    if( pPlayer->CardsInHand( CARDTYPE::TREASURE ) )
    {
        IAI* pAI = pPlayer->GetAI();
        Card* pTreasureCard = pAI->OnMint();
        
        if( pTreasureCard->IsTreasureCard() &&
            pPlayer->IsCardInHand( pTreasureCard ) )
        {
            pPlayer->GainCardOnDiscard( pTreasureCard );
        }
        else
        {
            // TODO: report error
            throw std::wstring( L"Error: MintCard::OnActionPhase" );
        }
    }
}

void MintCard::OnBuy( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();

    pPlayer->TrashFromInPlay( CARDTYPE::TREASURE );
}

} // namespace Domlib