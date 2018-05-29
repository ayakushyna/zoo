#ifndef SHARED_DEFS_H
#define SHARED_DEFS_H


enum pages {
    INTRO_PAGE ,
    BIRD_PAGE,
    MAMMAL_PAGE,
    SNAKE_PAGE,
    BIRDINFO_PAGE,
    MAMMALINFO_PAGE,
    SNAKEINFO_PAGE,
    FINAL_PAGE
};

enum Animaltype { BIRD = 1, MAMMAL, SNAKE };

enum messages { NOANIMAL = -1, UNFED, FED };

//enum Foodtype {SEEDS,MILLET,GRASS,MEAT,MILK,INSECTS,MOUSE};

#endif // SHARED_DEFS_H