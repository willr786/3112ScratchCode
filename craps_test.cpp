#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_DICE_VAL = 1;
const int MAX_DICE_VAL = 6;

int dieRoll(int, int );

/* This will be made into a boolean returning function 
   that will return true if the player won the game or
   false if they lose.  
*/
int main()
{
    int dice1,
        dice2,
        dieSum,
        rollCtr = 0,
        playerPoint;

    bool gameCondition = false;

    unsigned seed = time(0);
    srand(seed);
    
    cout << "Let's play Craps!!!" << endl;
    while(!gameCondition){
        dieSum = dieRoll(dice1, dice2);
        rollCtr++;

        if(rollCtr == 1){
            if(dieSum == 7 || dieSum == 11){
                cout << "You rolled a(n) "<< dieSum << ", you win!!!" << endl;
                cout << "Not bad for your first roll." << endl;
                gameCondition = true;
            }
            else if(dieSum == 2 || dieSum == 3 || dieSum == 12){
                cout << "You rolled a "<< dieSum << ". Sorry, you lost." << endl;
                gameCondition = true;
            }
            else if (dieSum == 4 || dieSum == 5 || dieSum == 6 
                     || dieSum == 8 || dieSum == 9 || dieSum == 10){
                         playerPoint = dieSum;
                         cout << "You rolled a(n) " << playerPoint 
                              << ".  This is your winning point." << endl;
                     }   
            else
                cout << "The game continues..." << endl;
        }
        else{
            if(dieSum == 7){
                cout << "You rolled a "<< dieSum << ".  Sorry, you lost." << endl;
                gameCondition = true;
            }
            else if(dieSum == playerPoint){
                cout << "You rolled a(n) "<< dieSum << ", you win!!!" << endl;
                cout << "And it only took " << rollCtr << " rolls of the die." << endl;
                gameCondition = true;
            }
            else
                cout << "You rolled a(n) "<< dieSum << ", the game continues..." << endl;
        }
    }
    cout << "Game Over" << endl;

    return 0; 
}

int dieRoll(int d1, int d2){
    int rollSum = 0;

    d1 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;
    d2 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;

    rollSum = d1 + d2;

    return rollSum;
}