#include <time.h>
#include <algorithm>
#include "Deck.h"
#include "PlusActions.h"
#include "PlusBuys.h"
#include "PlusCards.h"
#include "PlusTreasure.h"
#include "BaseDeck.h"

namespace Domlib
{

Deck::Deck( CARDSET set )
{
    // Common Cards
    m_Copper    = new Card( CARDID_COPPER,      false,   true,  false,  0,  1 );
    m_Silver    = new Card( CARDID_SILVER,      false,   true,  false,  3,  2 );
    m_Gold      = new Card( CARDID_GOLD,        false,   true,  false,  6,  3 );

    m_Estate    = new Card( CARDID_ESTATE,      false,  false,   true,  2,  1 );
    m_Duchy     = new Card( CARDID_DUCHY,       false,  false,   true,  5,  3 );
    m_Province  = new Card( CARDID_PROVINCE,    false,  false,   true,  8,  6 );

    m_Curse     = new Card( CARDID_CURSE,       false,  false,  false,  0,  -1 );

    switch( set )
    {
    case CARDSET_BASE:
        CreateBaseCardSet();
        break;
    default:
        break;
    }
}

Deck::~Deck( void )
{

}

Card* Deck::GetCard( CARDID id )
{
    Card* pCardOut = NULL;
    std::vector<Card*>::iterator cardItr = m_KingdomCards.begin();

    switch( id )
    {
        case CARDID_COPPER:     pCardOut = GetCopper(); break;
        case CARDID_SILVER:     pCardOut = GetSilver(); break;
        case CARDID_GOLD:       pCardOut = GetGold(); break;
        case CARDID_ESTATE:     pCardOut = GetEstate(); break;
        case CARDID_DUCHY:      pCardOut = GetDuchy(); break;
        case CARDID_PROVINCE:   pCardOut = GetProvince(); break;
        case CARDID_CURSE:      pCardOut = GetCurse(); break;
        default:
            {
                while( cardItr != m_KingdomCards.end() && pCardOut == NULL )
                {
                    Card* pCard = *cardItr;

                    if( pCard->CardId() == id )
                    {
                        pCardOut = pCard;
                    }

                    cardItr++;
                }
            }
            break;
    };

    return pCardOut;
}

Card* Deck::GetCopper( void ){      return m_Copper;    }
Card* Deck::GetSilver( void ){      return m_Silver;    }
Card* Deck::GetGold( void ){        return m_Gold;      }
Card* Deck::GetEstate( void ){      return m_Estate;    }
Card* Deck::GetDuchy( void ){       return m_Duchy;     }
Card* Deck::GetProvince( void ){    return m_Province;  }
Card* Deck::GetCurse( void ){       return m_Curse;     }

void Deck::SelectRandomKingdomCards(
    int amount,
    std::vector<Card*>& outContainer )
{
    // Seed once
    static bool seeded = false;
    if( !seeded )
    {
        srand( (unsigned int)time( NULL ) );
    }

    if( amount <= (int)m_KingdomCards.size() )
    {
        std::random_shuffle( 
            m_KingdomCards.begin(), 
            m_KingdomCards.end() );

        while( amount )
        {
            outContainer.push_back( m_KingdomCards.at( amount ) );

            amount--;
        }
    }
}

void Deck::CreateBaseCardSet( void )
{
    Card* pKingdomCard = NULL;

    pKingdomCard = new Card( CARDID_CELLAR, true, false, false, 2, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusActions<1>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_CHAPEL, true, false, false, 2, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_MOAT, true, false, false, 2, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusCards<2>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_CHANCELLOR, true, false, false, 3, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusTreasure<2>() );
    m_KingdomCards.push_back( pKingdomCard );

    m_KingdomCards.push_back( new Village() );

    pKingdomCard = new Card( CARDID_WOODCUTTER, true, false, false, 3, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusBuys<1>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusTreasure<2>() );
    m_KingdomCards.push_back( pKingdomCard );

    m_KingdomCards.push_back( new Workshop() );

    pKingdomCard = new Card( CARDID_BUREAUCRAT, true, false, false, 4, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_FEAST, true, false, false, 4, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_GARDENS, true, false, false, 4, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_MILITIA, true, false, false, 4, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusTreasure<2>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_MONEYLENDER, true, false, false, 4, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_REMODEL, true, false, false, 4, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_SMITHY, true, false, false, 4, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusCards<3>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_SPY, true, false, false, 4, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusCards<1>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusActions<1>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_THIEF, true, false, false, 4, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_THRONEROOM, true, false, false, 4, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_COUNCILROOM, true, false, false, 5, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusCards<4>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusBuys<1>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_FESTIVAL, true, false, false, 5, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusActions<2>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusBuys<1>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusTreasure<2>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_LABORATORY, true, false, false, 5, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusCards<2>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusActions<1>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_LIBRARY, true, false, false, 5, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_MARKET, true, false, false, 5, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusCards<1>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusActions<1>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusBuys<1>() );
    pKingdomCard->AddBaseAction( new BaseActions::PlusTreasure<1>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_MINE, true, false, false, 5, 0 );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_WITCH, true, false, false, 5, 0 );
    pKingdomCard->AddBaseAction( new BaseActions::PlusCards<2>() );
    m_KingdomCards.push_back( pKingdomCard );

    pKingdomCard = new Card( CARDID_ADVENTURER, true, false, false, 6, 0 );
    m_KingdomCards.push_back( pKingdomCard );
}

} // namespace Domlib