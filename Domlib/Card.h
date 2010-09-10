#pragma once

#include "Domlib.h"
#include "Engine.h"
#include "Player.h"
#include "Treasure.h"

namespace Domlib
{

enum AttackWhom
{
    ATTACK_OTHERS,
    ATTACK_ALL,
};

class Card : 
    public ICard
{
public:
    virtual ~Card( void );

    // Engine Interfaces
    virtual void        OnDurationPhase( Engine* pEngine );
    virtual void        OnActionPhase( Engine* pEngine );
    virtual Treasure    OnTreasurePhase( Engine* pEngine );
    virtual void        OnBuyPhase( Engine* pEngine, ICard* pCard );
    virtual void        OnCleanUpPhase( Engine* pEngine );
    virtual void        OnBuy( Engine* pEngine );
    virtual int         OnScoring( Engine* pEngine );

    // AI Interfaces ( class ICard )
            ICard*              GetCard( CARDID cardId );
    virtual CARDID              CardId( void ) const;
    virtual CARDTYPE            CardType( void ) const;
    virtual int                 VictoryPoints( IEngine* pEngine ) const;
    virtual const ITreasure*    Cost( IEngine* pEngine ) const;
    virtual const ITreasure*    TreasureValue( IEngine* pEngine ) const;
    virtual bool                InList( IEngine* pEngine, ICardList cardList ) const;

    virtual bool        IsActionCard( void ) const;
    virtual bool        IsAttackCard( void ) const;
    virtual bool        IsReactionCard( void ) const;
    virtual bool        IsDurationCard( void ) const;
    virtual bool        IsTreasureCard( void ) const;
    virtual bool        IsVictoryCard( void ) const;
    virtual bool        IsCurseCard( void ) const;
    virtual bool        IsNullCard( void ) const;

    static bool         CardListsMatch( ICardList listA, 
                                        ICardList listB );

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
    typedef std::map<CARDID, ICard*>    ICardMap;
    typedef ICardMap::const_iterator    ICardMapConstIter;
    typedef std::pair<CARDID, ICard*>   ICardMapPair;

    class CardFactory
    {
    public:
        CardFactory( void );
        ~CardFactory( void );

        ICard* GetCard( CARDID cardId );

    private:
        void    AddCard( ICard* pCard );
        ICard*  CreateCard( CARDID cardId );

        ICardMap m_CardMap;
        ICard*  m_pNullCard;
    };

    static CardFactory m_CardDeck;
};

// TODO: Delete this if not used
/*
typedef std::list<Card*>            CardList;
typedef CardList::iterator          CardListIter;
typedef CardList::const_iterator    CardListConstIter;
*/

} // namespace Domlib