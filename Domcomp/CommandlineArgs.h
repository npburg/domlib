#pragma once

typedef std::vector<std::wstring> CommandlineArgumentList;

class CommandlineSettings
{
public:
    CommandlineSettings( void )
    {
        SelectedCardSets.Base       = false;
        SelectedCardSets.Intrigue   = false;
        SelectedCardSets.Seaside    = false;
        SelectedCardSets.Alchemy    = false;
        SelectedCardSets.Prosperity = false;
        SelectedCardSets.All        = false;

        PrintHelp  = false;
    }

    ~CommandlineSettings( void )
    {
    }

    bool ParseCommandlineArguments(
        int argc,
        _TCHAR* argv[] );

    static void Help( std::wostream& out );

    struct
    {
        bool    All;
        bool    Base;
        bool    Intrigue;
        bool    Seaside;
        bool    Alchemy;
        bool    Prosperity;
    } SelectedCardSets;

    bool    PrintHelp;

private:
    bool Validate( void );
};
