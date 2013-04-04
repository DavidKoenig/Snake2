#pragma once
#ifndef SNAKE_CFIELD_H
#define SNAKE_CFIELD_H

#include "NStructs.h"

class CField
{
public:
	CField(void);
	~CField(void);

    // call-by-reference
    // char getField(Structs::SPosition* position_);

    char getField(Structs::SPosition position_);
    void setField(Structs::SPosition field_, char sign_);

private:


    // keine zahlen, immer konstanten nehmen
    // static const int s_NumberOfCellsX = 16;
    // static const int s_NumberOfCellsY = 16;
    // char field[s_NumberOfCellsX][s_NumberOfCellsY];


    // das geht leider nicht
    // static const float s_PI = 3.14;
    // stattdessen geht da so:
    // static const float s_PI;


    char field[16][16];
};

#endif /* SNAKE_CFIELD_H */