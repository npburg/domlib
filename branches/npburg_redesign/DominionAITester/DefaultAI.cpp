#include "StdAfx.h"
#include "DefaultAI.h"

DefaultAI::DefaultAI( void )
{
}

DefaultAI::~DefaultAI( void )
{
}

Domlib::ICard* DefaultAI::PlayAction( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::PlayTreasure( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::BuyCard( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnAttack( Domlib::ICard* pAttackCard )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnGainACard( const Domlib::ITreasure* cost )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnGainACardExactly( const Domlib::ITreasure* cost )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICardList DefaultAI::OnReturnToDrawPile( Domlib::ICardList cardList )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICard* DefaultAI::OnTrashCardFromHand( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnBureaucrat( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICardList DefaultAI::OnCellar( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ChancellorOpt DefaultAI::OnChancellor( void )
{
    return Domlib::CHANCELLOR_NO_OP;
}

Domlib::ICardList DefaultAI::OnChapel( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::LibraryOpt DefaultAI::OnLibrary( Domlib::ICard* pCard )
{
    return Domlib::LIBRARY_KEEP_ACTION_CARD;
}

Domlib::ICardList DefaultAI::OnMilitia( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICard* DefaultAI::OnMineTrash( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}


Domlib::ICard* DefaultAI::OnMineGain( const Domlib::ITreasure* cost )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnRemodel( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::SpyOpt DefaultAI::OnSpyOther( Domlib::ICard* pCard )
{
    return Domlib::SPY_DISCARD_CARD;
}

Domlib::SpyOpt DefaultAI::OnSpySelf( Domlib::ICard* pCard )
{
    return Domlib::SPY_DISCARD_CARD;
}

Domlib::ThiefOpt DefaultAI::OnThiefGain( Domlib::ICard* pCard )
{
    return Domlib::THIEF_STEAL_TREASURE_CARD;
}

Domlib::ICard* DefaultAI::OnThiefTrash( Domlib::ICardList cardList )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::BaronOpt DefaultAI::OnBaron( void )
{
    return Domlib::BARON_DISCARD_ESTATE;
}

Domlib::ICard* DefaultAI::OnCourtyard( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnIronworks( const Domlib::ITreasure* cost )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnMasqueradePass( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnMasqueradeTrash( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::MiningVillageOpt DefaultAI::OnMiningVillage( void )
{
    return Domlib::MININGVILLAGE_DO_NOT_TRASH_CARD;
}

Domlib::MinionOpt DefaultAI::OnMinion( void )
{
    return Domlib::MINION_PLUS_2_COINS;
}

Domlib::NoblesOpt DefaultAI::OnNobles( void )
{
    return Domlib::NOBLES_PLUS_3_CARDS;
}

Domlib::PawnOptPair DefaultAI::OnPawn( void )
{
    Domlib::PawnOptPair pawnOptPair;
    
    return pawnOptPair;
}

Domlib::ICardList DefaultAI::OnSecretChamber( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICardList DefaultAI::OnSecretChamberReaction( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::StewardOpt DefaultAI::OnSteward( void )
{
    return Domlib::STEWARD_PLUS_2_COINS;
}

Domlib::ICardList DefaultAI::OnStewardTrash( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICard* DefaultAI::OnSwindler( Domlib::ICard* pCard )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICardList DefaultAI::OnTorturer( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICardList DefaultAI::OnTradingPost( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICard* DefaultAI::OnUpgrade( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnWishingWell( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnAmbassadorReveal( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

int OnAmbassadorPutBack( Domlib::ICard* pCard )
{
    return 0;
}

Domlib::ICard* DefaultAI::OnEmbargo( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ExplorerOpt DefaultAI::OnExplorer( void )
{
    return Domlib::EXPLORER_REVEAL_PROVINCE;
}

Domlib::ICardList DefaultAI::OnGhostShip( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICard* DefaultAI::OnHaven( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnIsland( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ILookoutStruct DefaultAI::OnLookout( Domlib::ICardList cardList )
{
    Domlib::ILookoutStruct lookoutStruct;
    
    return lookoutStruct;
}

Domlib::NativeVillageOpt DefaultAI::OnNativeVillage( void )
{
    return Domlib::NATIVEVILLAGE_SET_ASIDE_CARD;
}

Domlib::ICardList DefaultAI::OnNavigator( Domlib::ICardList cardList )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::PearlDiverOpt DefaultAI::OnPearlDiver( Domlib::ICard* pCard )
{
    return Domlib::PEARLDIVER_BOTTOM_OF_DRAWPILE;
}

Domlib::PirateShipOpt DefaultAI::OnPirateShip( void )
{
    return Domlib::PIRATESHIP_ATTACK;
}

Domlib::ICard* DefaultAI::OnPirateShipTrash( Domlib::ICardList cardList )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnSalvager( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnSmugglers( Domlib::ICardList cardList )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::TreasuryOpt DefaultAI::OnTreasury( void )
{
    return Domlib::TREASURY_PUT_BACK;
}

Domlib::ICardList DefaultAI::OnWarehouse( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::AlchemistOpt DefaultAI::OnAlchemist( void )
{
    return Domlib::ALCHEMIST_PUT_BACK;
}

Domlib::ICard* DefaultAI::OnApprentice( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICardList DefaultAI::OnGolem( Domlib::ICardList cardList )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICard* DefaultAI::OnHerbalist( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ScryingPoolOpt DefaultAI::OnScryingPoolOther( Domlib::ICard* pCard )
{
    return Domlib::SCRYINGPOOL_PUT_BACK_CARD;
}

Domlib::ScryingPoolOpt DefaultAI::OnScryingPoolSelf( Domlib::ICard* pCard )

{
    return Domlib::SCRYINGPOOL_DISCARD_CARD;
}

Domlib::ICard* DefaultAI::OnTransmute( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnUniversity( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}
 
Domlib::LoanOpt DefaultAI::OnLoan( Domlib::ICard* pCard )
{
    return Domlib::LOAN_DISCARD_CARD;
}

Domlib::ICard* DefaultAI::OnBiship( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnContraband( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

int DefaultAI::OnCountingHouse( Domlib::ICardList cardList )
{
    return 0;
}

Domlib::ICard* DefaultAI::OnExpand( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICardList DefaultAI::OnForge( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICardList DefaultAI::OnGoons( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICard* DefaultAI::OnKingsCourt( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::ICard* DefaultAI::OnMint( void )
{
    return Domlib::ICard::GetCard( Domlib::CARDID_NULL );
}

Domlib::MountebankOpt DefaultAI::OnMountebank( void )
{
    return Domlib::MOUNTEBANK_DISCARD_CURSE;
}

Domlib::RoyalSealOpt DefaultAI::OnRoyalSeal( Domlib::ICard* pCard )
{
    return Domlib::ROYALSEAL_DISCARD_CARD;
}

Domlib::ICardList DefaultAI::OnVaultSelf( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}

Domlib::ICardList DefaultAI::OnValueOther( void )
{
    Domlib::ICardList iCardList;
    
    return iCardList;
}