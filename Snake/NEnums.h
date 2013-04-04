#ifndef SNAKE_ENUMS_H
#define SNAKE_ENUMS_H

namespace Enums {
    enum EDirection {NORTH, EAST, SOUTH, WEST};
}

struct SDirection
{
    enum Enum 
    {
        NORTH, 
        EAST, 
        SOUTH, 
        WEST,
        NumberOfMembers,
        Undefined = -1,
    };
};


// Beispiel:
// void Method(SDirection::Enum direction_)
// {
    // if (direction_ == SDirection::NORTH)
    // {
    //    ...
    // }
// }

#endif /* SNAKE_ENUMS_H */