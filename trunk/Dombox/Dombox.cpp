#include <tchar.h>
#include <vector>
#include <Domlib.h>
#include <iostream>

typedef Domlib::AI::IDomCard    DomCard;

class PureMoney
    :
    public Domlib::AI::IPlayer
{
public:

    // General Notifications
    virtual void GainCard( const DomCard* pCard ) const
    {

    }

    // BuyPhase Callbacks
    virtual bool ContinueBuying( int buysRemaining )
    {
        return true;
    }

    virtual Domlib::CARDID BuyCard( int buyingPower )
    {
        Domlib::CARDID id = Domlib::CARDID_UNKNOWN;

        DomCard* pCopper    = Engine()->GetCopper();
        DomCard* pSilver    = Engine()->GetSilver();
        DomCard* pGold      = Engine()->GetGold();
        DomCard* pProvince  = Engine()->GetProvince();

        const int copperCost    = pCopper->Cost();
        const int silverCost    = pSilver->Cost();
        const int goldCost      = pGold->Cost();
        const int provinceCost  = pProvince->Cost();

        if( copperCost <= buyingPower && buyingPower < silverCost )
        {
            id = pCopper->CardId();
        }
        else if( silverCost <= buyingPower && buyingPower < goldCost )
        {
            id = pSilver->CardId();
        }
        else if( goldCost <= buyingPower && buyingPower < provinceCost )
        {
            id = pGold->CardId();
        }
        else
        {
            id = pProvince->CardId();
        }

        return id;
    }
};

int _tmain( int argc, _TCHAR* argv[] )
{
    Domlib::Game basicGame( Domlib::Deck::CARDSET_BASE );

    basicGame.RegisterPlayer( new PureMoney() );
    basicGame.RegisterPlayer( new PureMoney() );
    basicGame.RegisterPlayer( new PureMoney() );

    basicGame.Play();

	return 0;
}

