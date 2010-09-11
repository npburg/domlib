#pragma once

#include "Domlib.h"
#include "Engine.h"
#include "Player.h"
#include "Treasure.h"

namespace Domlib
{

class Card;

typedef std::list<Card*>            CardList;
typedef CardList::iterator          CardListIter;
typedef CardList::const_iterator    CardListConstIter;

enum AttackWhom
{
    ATTACK_OTHERS,
    ATTACK_ALL,
};

class Card
{
public:
    virtual ~Card( void );

    // Engine Interfaces
    virtual void        OnDurationPhase( Engine* pEngine );
    virtual void        OnActionPhase( Engine* pEngine );
    virtual Treasure    OnTreasurePhase( Engine* pEngine );
    virtual void        OnBuyPhase( Engine* pEngine, Card* pCard );
    virtual void        OnCleanUpPhase( Engine* pEngine );
    virtual void        OnBuy( Engine* pEngine );
    virtual int         OnScoring( Engine* pEngine );

    // AI Interfaces ( class ICard )
    static  Card*               GetCard( CARDID cardId );
    virtual CARDID              CardId( void ) const;
    virtual CARDTYPE            CardType( void ) const;
    virtual int                 VictoryPoints( Engine* pEngine ) const;
    virtual Treasure            Cost( Engine* pEngine ) const;
    virtual Treasure            TreasureValue( Engine* pEngine ) const;
    virtual bool                InList( Engine* pEngine, CardList cardList ) const;

    virtual bool        IsActionCard( void ) const;
    virtual bool        IsAttackCard( void ) const;
    virtual bool        IsReactionCard( void ) const;
    virtual bool        IsDurationCard( void ) const;
    virtual bool        IsTreasureCard( void ) const;
    virtual bool        IsVictoryCard( void ) const;
    virtual bool        IsCurseCard( void ) const;
    virtual bool        IsNullCard( void ) const;

    static bool         CardListsMatch( CardList listA, 
                                        CardList listB );

protected:
    Card( 
        std::wstring name,
        CARDID cardId, 
        CARDTYPE cardType, 
        int victoryPoints,
        Treasure treasureValue,
        Treasure cost );

    void Attack( Engine* pEngine, AttackWhom attackWhom );
    virtual void OnAttack( Engine* pEngine, Player* pPlayer );
    virtual void OnReaction( Engine* pEngine, Player* pPlayer );

    const std::wstring      m_Name;
    const CARDID            m_CardId;
    const CARDTYPE          m_CardType;
    const int               m_VictoryPoints;
    const Treasure          m_TreasureValue;
    const Treasure          m_Cost;

private:
    typedef std::map<CARDID, Card*>     CardMap;
    typedef CardMap::const_iterator     CardMapConstIter;
    typedef std::pair<CARDID, Card*>    CardMapPair;

    class CardFactory
    {
    public:
        CardFactory( void );
        ~CardFactory( void );

        Card*  GetCard( CARDID cardId );

    private:
        void    AddCard( Card* pCard );
        Card*   CreateCard( CARDID cardId );

        CardMap m_CardMap;
        Card*  m_pNullCard;
    };

    static CardFactory m_CardDeck;
};


} // namespace Domlib