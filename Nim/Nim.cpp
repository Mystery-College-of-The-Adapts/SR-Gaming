// Thomas Alexander Steinholz
// South River High School
// C++ w/ Gaming : 1A

#include "Nim.h"

Nim::Nim()
{ Initialize(); }

Nim::~Nim()
{ Shutdown(); }

void Nim::Initialize()
{
    srand(time(NULL));
    HumanFirst = (bool) (rand() % 2);
    Pile = rand() % 91 + 10;

    switch(rand() % 2)
    {
        default:
        case 0:
            Difficulty = SMART;
            break;
        case 1:
            Difficulty = EASY;
            break;
    }

#if OVERRIDE_SMART
    Difficulty = SMART;
#endif
#if OVERRIDE_EASY
    Difficulty = EASY;
#endif
#if OVERRIDE_PLAYER_FIRST
    HumanFirst = true;
#endif
}

void Nim::Execute()
{
#if DEBUG
    std::cout << "DEBUG: Difficulty = " << Difficulty << std::endl;
    std::cout << "DEBUG: Human First = " << HumanFirst << std::endl;
#endif
    bool playing = true;
    while (playing)
    {
        playing = HumanFirst ? HumanTurn() : AiTurn();
        if (playing) playing = HumanFirst ? AiTurn() : HumanTurn();
    }
    Shutdown();
}

void Nim::Shutdown()
{

}

bool Nim::AiTurn()
{
    std::cout << "AI's Turn!" << std::endl;
    int half = Pile != 1 ? Pile/2 : Pile/2 + 1;
    switch (Difficulty)
    {
        default:
        case SMART:
            if (Pile == 100)
            {
                if (Pile-65 <= half) Pile -= 65;
                else Pile -= rand() % half + 1;
            }
            else if (Pile >= 64)
            {
                if (Pile-33 <= half) Pile -= 33;
                else Pile -= rand() % half + 1;
            }
            else if (Pile >= 32)
            {
                if (Pile-17 <= half) Pile -= 17;
                else Pile -= rand() % half + 1;
            }
            else if (Pile >= 16)
            {
                if (Pile-9  <= half) Pile -= 9;
                else Pile -= rand() % half + 1;
            }
            else if (Pile >= 8)
            {
                if (Pile-5  <= half) Pile -= 5;
                else Pile -= rand() % half + 1;
            }
            else Pile -= rand() % half + 1;



            if (Pile == 100)     { if (Pile-65 <= half) Pile = 63; else Pile -= rand() % half + 1; }
            else if (Pile >= 64) { if (Pile-33 <= half) Pile = 31; else Pile -= rand() % half + 1; }
            else if (Pile >= 32) { if (Pile-17 <= half) Pile = 15; else Pile -= rand() % half + 1; }
            else if (Pile >= 16) { if (Pile-9  <= half) Pile = 7;  else Pile -= rand() % half + 1; }
            else if (Pile >= 8)  { if (Pile-5  <= half) Pile = 3;  else Pile -= rand() % half + 1; }
            else Pile -= rand() % half + 1;
            if(Pile < 1)
            {
                std::cout << "-------------" << std::endl;
                std::cout << "You just WON!" << std::endl;
                std::cout << "-------------" << std::endl;
                return false;
            }
            break;
        case EASY:
            Pile -= rand() % half + 1;
            if(Pile < 1)
            {
                std::cout << "-------------" << std::endl;
                std::cout << "You just WON!" << std::endl;
                std::cout << "-------------" << std::endl;
                return false;
            }
            break;
    }
    std::cout << "Done AI's Turn!" << std::endl;
    return true;
}

bool Nim::HumanTurn()
{
    int turn;
    std::cout << "Your Turn!" << std::endl << "The Pile is " << Pile << ", pick a number between 1 & " << Pile/2
    << "?" << std::endl;
    std::cout << "[1," << Pile/2 << "]:";
    std::cin >> turn;
    if ((turn < 1) || ((turn > (Pile / 2)) && turn != 1))
    {
        std::cout << std::endl << "--------------------------------" << std::endl;
        std::cout << "This Move is Invalid! Try again!" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        return HumanTurn();
    }
    Pile -= turn;
    if(Pile < 1)
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "You just LOST! AI WINS!" << std::endl;
        std::cout << "-----------------------" << std::endl;
        return false;
    }
    else return true;

}