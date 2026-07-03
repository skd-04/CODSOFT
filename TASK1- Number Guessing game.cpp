//GUESSING GAME
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int guess;
    int attempts=0; 

    srand(time(0));          // Seed the random number generator

    int randomNumber = rand() % 100 + 1;

    cout<<"-------NUMBER GUESSING GAME---------\n";
    cout<<" Guess the number (B/W : 1-100): ";
    cin>>guess;


while(guess!= randomNumber)
{
        // Input validation
        if (guess < 1 || guess > 100)
        {
            cout << "Invalid input! Please enter a number between 1 and 100.\n";
        }
        else
        {
             attempts++;

            if(guess > (randomNumber + 6))
                cout<<"TOO HIGH! Try a smaller number ."<<endl;

            else if(guess <(randomNumber-6))
                cout<<"TOO LOW! Try a larger number ."<<endl;

             else 
                cout<<"PRETTY CLOSE ,TRY AGAIN."<<endl;

        }
    cout<<"GUESS AGAIN : ";
    cin>>guess;
   }
    attempts++;

  cout<<" CONGRATULATIONS! CORRECT GUESSS.";
  cout << "The correct number was: " << randomNumber << endl;
  cout << "Total Attempts: " << attempts << endl;
    

    return 0;
}