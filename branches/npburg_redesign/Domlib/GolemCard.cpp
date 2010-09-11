#include "StdAfx.h"
#include "GolemCard.h"

namespace Domlib
{

GolemCard::GolemCard( void )
    : Card( 
        L"Golem",
        CARDID_GOLEM,
        CARDTYPE_ACTION,
        0,
        Treasure( 0, 0 ),
        Treasure( 4, 1 ) )
{
}

GolemCard::~GolemCard( void )
{
}

void GolemCard::OnActionPhase( Engine* pEngine )
{
    // TODO: Not sure how to implement the Golem playing two cards since it is
    // not the player playing the cards since the cards in Hand are not
    // avaliable
    throw std::wstring( L"GolemCard::OnActionPhase - To be implemented..." );

    Player* pPlayer = pEngine->GetCurrentPlayer();
    IAI* pAi = pPlayer->GetAI();
    CardList revealedCardList;
    CardList actionCardList;

    do
    {
        Card* pRevealedCard = pPlayer->RevealCardFromDeck();

        if( pRevealedCard->IsNullCard() )
        {
            break;
        }
        else if( pRevealedCard->IsActionCard() &&
                 pRevealedCard->CardId() != CARDID_GOLEM )
        {
            actionCardList.push_back( pRevealedCard );
        }
        else
        {
            revealedCardList.push_back( pRevealedCard );
        }
    }
    while( actionCardList.size() < 2 );

    pPlayer->PutCardsInDiscard( revealedCardList );

    CardList reorderedCardList = 
        pAi->OnGolem( revealedCardList );

    if( Card::CardListsMatch( revealedCardList, reorderedCardList ) )
    {
        CardListIter cardIter;

        pPlayer->SetGolemFlag( true );

        for( cardIter = reorderedCardList.begin();
             cardIter != reorderedCardList.end();
             cardIter++ )
        {
            Card* pCardToPlay = (Card*)*cardIter;
            pCardToPlay->OnActionPhase( pEngine );
        }

        pPlayer->SetGolemFlag( false );

        pPlayer->PutCardsInPlay( actionCardList );
    }
    else
    {
        // TODO: report error
        throw std::wstring( L"Error: ScoutCard::OnActionPhase" );
    }
}

} // namespace Domlib