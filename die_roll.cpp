#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_DICE_VAL = 1;
const int MAX_DICE_VAL = 6;

int dieRoll(int, int );

int main()
{
    int dice1,
        dice2,
        dieSum;

    unsigned seed = time(0);
    srand(seed);
    
    // Used to simulate two dice being rolled.  
    for(int i = 0; i < 5; i++)
    {
        /*
        dice1 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;
        dice2 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;
        
        dieSum = dice1 + dice2;    
        */
        dieSum = dieRoll(dice1, dice2);
        cout << dieSum << endl;
    }

    return 0; 
}

int dieRoll(int d1, int d2){
    int rollSum = 0;

    d1 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;
    d2 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;

    rollSum = d1 + d2;

    return rollSum;
}