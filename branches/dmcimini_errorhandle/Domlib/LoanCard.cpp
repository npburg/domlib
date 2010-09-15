#include "StdAfx.h"
#include "LoanCard.h"

namespace Domlib
{

LoanCard::LoanCard(void)
    : Card( 
        L"Loan",
        CARDID_LOAN,
        CARDTYPE_TREASURE,
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
    Card* pRevealedCard = Card::GetCard( CARDID_NULL );

    do
    {
        pRevealedCard = pPlayer->RevealCardFromDeck();
        if( pRevealedCard->IsTreasureCard() )
        {
            IAI* pAI = pPlayer->GetAI();
            LoanOpt loanOpt = pAI->OnLoan( pRevealedCard );
            
            switch( loanOpt )
            {
            case LOAN_DISCARD_CARD:
                revealedCardList.push_back( pRevealedCard );
                break;
            case LOAN_TRASH_CARD:
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