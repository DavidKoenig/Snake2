#include "Output.h"
#include "Field.h"
#include "NStructs.h"
#include <iostream>
using namespace std;

// using std::cout;
// using std::endl;

COutput::COutput(void)
{
}


COutput::~COutput(void)
{
}

void COutput::printField(CField* field_)
{

    // using std::cout;

    Structs::SPosition position;
    for(int index = 0; index < 16; ++index)
    {
        std::cout << std::endl;
        for(int index2 = 0; index2 < 16; ++index2)
        {
            position.posX = index2;
            position.posY = index;
            std::cout << " " <<field_->getField(position);
        }
    }
}

void COutput::printRndNmbr(int rndNmbr_)
{
	cout << "\nRundennummer: " << rndNmbr_;
}

void COutput::printWin(CPlayer* player_)
{
	cout << "\n------------------------------------------\n" << player_->getName() << " hat gewonnen";
}

void COutput::printCollision(CPlayer* playerCollided_, CPlayer* playerHit_)
{
	cout << "\n////////////////////////////////////////\n" << playerCollided_->getName() << " hat " << playerHit_->getName() << " gerammt";
}