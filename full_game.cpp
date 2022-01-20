#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_DICE_VAL = 1;
const int MAX_DICE_VAL = 6;

bool crapsGame();
int dieRoll(int, int);

int main()
{
    int chips = 100,
        wager;

    char selection;
    bool playCraps;

    cout << "Let's Play Craps!!!" << endl;
    do{
        cout << "Chips: " << chips << endl;
        cout << "Select y to play or n quit: ";
        cin >> selection;
    
        selection  = toupper(selection);

        // Utilize C#'s features to fully validate the inputs.      
        while(selection != 'Y' && selection != 'N'){
            cout << "Invalid choice, please re-enter your selection: ";
            cin >> selection;
            selection = toupper(selection);
        }

        if(selection == 'Y'){
            cout << "Place a wager: ";
            cin >> wager;
        
            // Utilize C#'s features to fully validate the inputs.
            while(wager <= 0 || wager > chips){
                cout << "Please enter a correct wager amount: ";
                cin >> wager;
            }

            chips -= wager;
            playCraps = crapsGame();
            
            if(playCraps == true){
                cout << "You win!!!" << endl;
                chips += (wager * 2);
            }
            else
                cout << "Sorry, you have lost the game." << endl;
        }


        if(chips <= 0){
            cout << "You ran out of chips and are no longer eligible to keep playing..." << endl;
            selection = 'N';
        }


    }while(selection == 'Y');
    

    return 0;
}

bool crapsGame()
{
    bool gameCondition = false,
         winOrLose = false;

    int dice1,
        dice2,
        dieSum,
        rollCtr = 0,
        playerPoint;

    unsigned seed = time(0);
    srand(seed);
    
    while(!gameCondition){
        dieSum = dieRoll(dice1, dice2);
        rollCtr++;

        if(rollCtr == 1){
            if(dieSum == 7 || dieSum == 11){
                cout << "You rolled a(n) "<< dieSum 
                     << ", not bad for your first roll." << endl;
                
                gameCondition = true;
                winOrLose = true;
            }
            else if(dieSum == 2 || dieSum == 3 || dieSum == 12){
                cout << "You rolled a "<< dieSum << ".  ";
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
                cout << "You rolled a "<< dieSum << ".  ";
                gameCondition = true;
            }
            else if(dieSum == playerPoint){
                cout << "You rolled a(n) "<< dieSum << "." << endl;
                cout << "You scored your point after " << rollCtr << " rolls of the die." << endl;
                
                gameCondition = true;
                winOrLose = true;
            }
            else
                cout << "You rolled a(n) "<< dieSum << ", the game continues..." << endl;
        }
    }     

    return winOrLose;
}

// Make this a private function in C#.  
int dieRoll(int d1, int d2){
    int rollSum = 0;

    d1 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;
    d2 = (rand() % (MAX_DICE_VAL - MIN_DICE_VAL + 1)) + MIN_DICE_VAL;

    rollSum = d1 + d2;

    return rollSum;
}

     
