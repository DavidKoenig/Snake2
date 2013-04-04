#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <stddef.h>

CPlayer::CPlayer(char* name_, char sign_, int posX_, int posY_)
    : name(name_)
    , sign(sign_)
    , crntDir(Enums::NORTH)
{
    this->position.posX = posX_;
    this->position.posY = posY_;
}

CPlayer::~CPlayer(void)
{
}

bool CPlayer::move(int chNewDir_, CField* field_)
{
    if(chNewDir_ <= 25 || !checkDir(this->crntDir))
        this->crntDir = getNewDir(field_);

    if(this->crntDir == Enums::NORTH)
        if(checkDir(this->crntDir))
            ++this->position.posY;
    if(this->crntDir == Enums::EAST)
        if(checkDir(this->crntDir))
            ++this->position.posX;
    if(this->crntDir == Enums::SOUTH)
        if(checkDir(this->crntDir))
            --this->position.posY;
    if(this->crntDir == Enums::WEST)
        if(checkDir(this->crntDir))
            --this->position.posX;
    
    if(checkColl(field_)) 
        return false;

    this->setSign(field_);
    return true;
}

bool CPlayer::checkDir(int crntDir_) 
{
	bool checkDirection = true; 

    if(crntDir_ == Enums::NORTH){
        if(this->position.posY >= 15) checkDirection = false;
	}
    if(crntDir_ == Enums::EAST){
        if(this->position.posX >= 15) checkDirection = false;
	}
    if(crntDir_ == Enums::SOUTH){
        if(this->position.posY <= 0) checkDirection = false;
	}
    if(crntDir_ == Enums::WEST){
        if(this->position.posX <= 0) checkDirection = false;
	}
    return checkDirection;
}

Enums::EDirection CPlayer::getNewDir(CField* field_)
{
	int newDir = 0;
	int tempCrntDir = 0;

	if(this->crntDir == Enums::NORTH) tempCrntDir = 0;
	if(this->crntDir == Enums::EAST) tempCrntDir = 1;
	if(this->crntDir == Enums::SOUTH) tempCrntDir = 2;
	if(this->crntDir == Enums::WEST) tempCrntDir = 3;

	std::cout << "\n----------currentDirection: --------------" << tempCrntDir;

	do{
		newDir = rand() % 4;

	}while((newDir == tempCrntDir) && (!checkDir(newDir))); 

	if(newDir == 0) return Enums::NORTH;
	else if(newDir == 1) return Enums::EAST;
	else if(newDir == 2) return Enums::SOUTH;
	else if(newDir == 3) return Enums::WEST;

    /*int newDir = 0;

    do 
    {
        newDir = rand() % Enums::WEST;

    } while((newDir == this->crntDir) && (!checkDir(newDir)));

   
	if(newDir == Enums::NORTH) 
        return Enums::NORTH;
    else if(newDir == Enums::EAST)
        return Enums::EAST;
    else if(newDir == Enums::SOUTH)
        return Enums::SOUTH;
    else if(newDir == Enums::WEST)
        return Enums::WEST;
    else 
        getNewDir(field_);
    return Enums::NORTH;
	*/
   
}

bool CPlayer::checkColl(CField* field_)
{
    if(field_->getField(this->position) != '.'){
        if(field_->getField(this->position) != this->sign) return true;
	}
    return false;
}

void CPlayer::setSign(CField* field_)
{
    field_->setField(this->position, this->sign);
}

Structs::SPosition CPlayer::getPos()
{
    return this->position;
}

char* CPlayer::getName()
{
    return this->name;
}

char CPlayer::getSign()
{
    return this->sign;
}