#include "Card.h"
#include <iostream>

FCard::FCard()
{
    EType = ECardType::None;
    Shape = "";
    Number = 0;
}

FCard::~FCard()
{

}

ECardType FCard::GetType()
{
    return EType;
}

void FCard::SetType(ECardType NewType)
{
    EType = NewType;
}

std::string FCard::GetShape()
{
    return Shape;
}

void FCard::SetShape(std::string NewShape)
{
    Shape = NewShape;
}

int FCard::GetNumber()
{
    return Number;
}

void FCard::SetNumber(int NewNumber)
{
    Number = NewNumber;
}

void FCard::ShowCard()
{
    if (Number == 1)
    {
        std::cout << "A ";
    }
    else if (Number == 11)
    {
        std::cout << "J ";
    }
    else if (Number == 12)
    {
        std::cout << "Q ";
    }
    else if (Number == 13)
    {
        std::cout << "K ";
    }
    else
    {
        std::cout << Number << ' ';
    }
}
