#include "food.h"

Food::Food():mType(UNKNOWN), mName(),mPercentIncrease(0),mPredator(0){}

Food::Food(AnimalType type, const QString& name, int percentIncrease)
    :mType(type), mName(name),mPercentIncrease(percentIncrease),mPredator(0){}

Food::Food(AnimalType type, const QString& name, int percentIncrease, bool predator)
    :mType(type), mName(name),mPercentIncrease(percentIncrease),mPredator(predator){}

AnimalType Food::getFoodAnimalType()const { return mType; }

QString Food::getFoodName()const { return mName; }

int Food::getFoodPercentIncrease()const { return mPercentIncrease; }

bool Food::getPredatorFood()const { return mPredator; }

Food::~Food(){}
