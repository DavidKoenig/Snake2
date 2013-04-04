#pragma once
#ifndef SNAKE_COUTPUT_H
#define SNAKE_COUTPUT_H
#include "Field.h"
#include "Player.h"

class COutput
{
public:
	COutput(void);
	~COutput(void);

    void printField(CField* field_);
    void printCollision(CPlayer* playerCollided_, CPlayer* playerHit_);
    void printWin(CPlayer* player_);
    void printRndNmbr(int rndNmbr_);
};

#endif /* SNAKE_COUTPUT_H */
