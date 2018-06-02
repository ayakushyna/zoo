#ifndef SHARED_DEFS_H
#define SHARED_DEFS_H


enum Pages {
    INTRO_PAGE ,
    BIRD_PAGE,
    MAMMAL_PAGE,
    SNAKE_PAGE,
    BIRDINFO_PAGE,
    MAMMALINFO_PAGE,
    SNAKEINFO_PAGE,
    FINAL_PAGE
};

enum AnimalType { UNKNOWN, BIRD, MAMMAL, SNAKE };

enum Messages { NOANIMAL = -1, UNFED, FED };

#endif // SHARED_DEFS_H
