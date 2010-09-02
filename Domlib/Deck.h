#pragma once

#include "Card.h"

namespace Domlib
{

enum CARDID
{
    CARDID_UNKNOWN,

    // Common Cards
    CARDID_COPPER,
    CARDID_SILVER,
    CARDID_GOLD,
    CARDID_ESTATE,
    CARDID_DUCHY,
    CARDID_PROVINCE,
    CARDID_CURSE,

    // Base Set - Kingdom Cards
    CARDID_CELLAR,
    CARDID_CHAPEL,
    CARDID_MOAT,
    CARDID_CHANCELLOR,
    CARDID_VILLAGE,
    CARDID_WOODCUTTER,
    CARDID_WORKSHOP,
    CARDID_BUREAUCRAT,
    CARDID_FEAST,
    CARDID_GARDENS,
    CARDID_MILITIA,
    CARDID_MONEYLENDER,
    CARDID_REMODEL,
    CARDID_SMITHY,
    CARDID_SPY,
    CARDID_THIEF,
    CARDID_THRONEROOM,
    CARDID_COUNCILROOM,
    CARDID_FESTIVAL,
    CARDID_LABORATORY,
    CARDID_LIBRARY,
    CARDID_MARKET,
    CARDID_MINE,
    CARDID_WITCH,
    CARDID_ADVENTURER,

    // Intrigue - Kingdom Cards
    // TBD

    // Seaside - Kingdom Cards
    // TBD

    // Alchemy - Kingdom Cards
    // TBD

    // Prosperity - Kingdom Cards
    // TBD

    // Promo - Kingdom Cards
    // TBD
};

class Deck
{
public:
    enum CARDSET
    {
        CARDSET_BASE,
        // CARDSET_INTRIGUE,
        // CARDSET_SEASIDE,
        // CARDSET_ALCHEMY,
        // CARDSET_PROSPERITY,
        // CARDSET_PROMO
    };

    Deck( CARDSET set );

    virtual ~Deck( void );

    virtual Card*   GetCard( CARDID id );
    virtual Card*   GetCopper( void );
    virtual Card*   GetSilver( void );
    virtual Card*   GetGold( void );
    virtual Card*   GetEstate( void );
    virtual Card*   GetDuchy( void );
    virtual Card*   GetProvince( void );
    virtual Card*   GetCurse( void );

    virtual void SelectRandomKingdomCards(
                    int amount,
                    std::vector<Card*>& outContainer );

private:
    void    CreateBaseCardSet( void );

    Card*   m_Copper;
    Card*   m_Silver;
    Card*   m_Gold;
    Card*   m_Estate;
    Card*   m_Duchy;
    Card*   m_Province;
    Card*   m_Curse;

    std::vector<Card*>  m_KingdomCards;
};

} // namespace Domlib