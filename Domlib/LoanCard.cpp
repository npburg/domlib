#include "StdAfx.h"
#include "LoanCard.h"

namespace Domlib
{

LoanCard::LoanCard(void)
    : Card( 
        L"Loan",
        CARDID::LOAN,
        CARDTYPE::TREASURE,
        0,
        Treasure( 1, 0 ),
        Treasure( 3, 0 ) )
{
}

LoanCard::~LoanCard(void)
{
}

Treasure LoanCard::OnTreasurePhase( Engine* pEngine )
{
    Player* pPlayer = pEngine->GetCurrentPlayer();
    CardList revealedCardList;
    Card* pRevealedCard = Card::GetCard( CARDID::NULLCARD );

    do
    {
        pRevealedCard = pPlayer->RevealCardFromDeck();
        if( pRevealedCard->IsTreasureCard() )
        {
            IAI* pAI = pPlayer->GetAI();
            LoanOpt loanOpt = pAI->OnLoan( pRevealedCard );
            
            switch( loanOpt )
            {
            case LoanOpt::DISCARD_CARD:
                revealedCardList.push_back( pRevealedCard );
                break;
            case LoanOpt::TRASH_CARD:
                pEngine->PutCardInTrash( pRevealedCard );
                break;
            default:
                // TODO: report error
                throw std::wstring( L"Error: LoanCard::OnTreasurePhase" );
                break;
            }
            
            break;
        }
        else if( !pRevealedCard->IsNullCard() )
        {
            revealedCardList.push_back( pRevealedCard );
        }
        else
        {
            // Do nothing
        }
    }
    while( !pRevealedCard->IsNullCard() );
    
    pPlayer->PutCardsInDiscard( revealedCardList );
    
    return m_TreasureValue;
}

} // namespace Domlib