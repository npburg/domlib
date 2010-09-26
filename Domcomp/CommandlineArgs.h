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

        PrintHelp  = false;

        GameCount = 0;
        RerunCountPerGame = 1;
    }

    ~CommandlineSettings( void )
    {
    }

    bool ParseCommandlineArguments(
        int argc,
        _TCHAR* argv[] );

    static void Help( std::wostream& out );

    // Argument Values
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
    int     GameCount;
    int     RerunCountPerGame;

    std::vector<std::wstring>   DllList;

private:
    bool Validate( void );
};
