#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

//declaring a function 
void relevantinfo();
enum option {GREETING = 1, WEATHER = 2, GAME = 3, EXIT = 4};

int main(){

   //relevant info
   relevantinfo();

    time_t rawtime;
    string time_str;

    //get current time
    rawtime = time(&rawtime);
    time_str = ctime(&rawtime);

    //parse string to get the hour only
    string hourstr = time_str.substr(11, 2);
    int hour = stoi(hourstr);

    //generate random weather and temp
    srand(time(NULL));
    int randtemp = rand() %96 + 10;
    int randweather = rand() %2;
    string weather;

    int randno;
    int guess;
    int i;

    string name;
    int choice;

    //get user name
    cout << "\nPlease enter your full name: ";
    getline(cin, name);

   while(true){
    
            //display menu and get user's choice
            cout <<"\n+********************MENU***********************+\n";
            cout <<"| Personal Conciege App: Choose a Service \t|\n";
            cout <<"|  1.Display Personal Greeting \t\t\t|\n";
            cout <<"|  2.Display Today's Weather Forecast \t\t|\n";
            cout <<"|  3.Play a Guessing Game \t\t\t|\n";
            cout <<"|  4.Exit \t\t\t\t\t|\n";
            cout <<"+***********************************************+\n";

            cout << "-----> ";
                cin >> choice;

            switch (choice){
                case GREETING:

                    //display date, time and personal greeting based on time
                    cout << time_str;

                    if (hour >= 0 && hour <= 12){
                    cout << "Good morning, " << name << ". I hope you are having a nice day!\n";
                    }else if (hour >= 12 && hour <18){
                    cout << "Good afternoon, " << name << ". I hope you are having a nice day!\n";
                    }else {
                    cout << "Good evening, " << name << ". I hope you are having a nice day!\n";
                    } 

                    break;
                case WEATHER:

                    //assigning the randomnumber(0 for sunny, 1 for rainy).
                    weather = (randweather == 0) ? "sunny" : "rainy";

                    //display weather
                    cout << "Today's Forecast high of "<< randtemp << " and "<< weather <<".";

                    break;
                case GAME:

                    //generate random number from 1-10
                    randno = rand() %10 + 1;

                    //give the user 3 attempts to guess
                    cout << "You have 3 chances to guess my number from 1 to 10! \n";
                    for(i=0 ; i<3; i++){
                        cout << "Guess #" << i+1<< ": ";
                        cin >> guess;

                        if (guess == randno){
                           cout << "Congratulations! You guessed the number in " << i+1 << " attempt(s)!\n"; 
                           break;
                        }else{
                            cout <<"("<< guess <<") is a wrong guess ;(\n";
                            //provide hints
                            if (i < 2){
                                if (guess < randno) {
                                    cout << "Hint: guess a higher number.\n"; 
                                }else {
                                    cout << "Hint: guess a lower number.\n";
                                }
                            }else {
                                cout << "\n You are out of guesses ;( The number was: "<< randno << "\n";
                            }
                        }

                    }

                    break;
                case EXIT:
                    cout << "Thank you for using the Personal Concierge App.";
                    return 0;
                default:
                    cout << "\n     !! Invalid Input("<< choice <<") Enter option 1-4 !!";
                    
            }
    
   }

    return 0;
}

//the function's output
void relevantinfo(){
   cout <<"+-----------------------------------------------+\n";
   cout <<"| \tComputer Science and Engineering \t|\n";
   cout <<"| \t CSCE 1030 - Computer Science I \t|\n";
   cout <<"| \t\t group number 4\t\t        |\n";
   cout <<"+-----------------------------------------------+\n";
}