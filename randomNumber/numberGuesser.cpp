#include <iostream>
#include "C:\Users\puurr\Documents\codee\500daysofcode\cpp\projects\randomNumber/randomGeneratorHeader.h"

using namespace std;

int main()
{
    int choice;
    
    cout << "Number Guesser" << endl;
    cout << " 1) Play" << "\n" << " 2) Exit" << "\n" << "Enter your Choice: ";
    cin >> choice;
    
    if(choice == 1)
    {
        uint32_t max, min, guess;
        int chance = 5;
        
        cout << " Choose Range " << endl;
        cout << " Min Value: " ;
        cin >> min;
        
        cout << " Max Value: " ;
        cin >> max;
        
        if(max <= min){
            cout << "Enter a Valid Range.";
        } 
        
        int num = generateRandomNumber(min, max);
        
        cout << "  Enter your guess: ";
        cin >> guess;
        
        if(num == guess)
        {
            cout << "You won";
            exit(0);
        } 
        else 
        {
            while ( chance > 0)
            {
                cout << " (Wrong) Enter your guess: ";
                cin >> guess;
                if(num == guess)
                {
                    cout << "You won";
                    exit(0);
                } 
                chance--;
            }
        }
        cout << "You Lost; The right number was: " << num << endl;            
    }
    else if (choice == 2) 
    {
        exit(0);
    }
    else 
    {     
        cout << "Enter a valid Option!" << endl;
    }
    return 0;
}