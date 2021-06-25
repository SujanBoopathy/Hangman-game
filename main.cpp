#include<iostream>
#include<unistd.h>
#include<conio.h>
#include<ctime>
#include<string>
#include "hangman.h"
using namespace std;

int Num_Try=3;
void main_menu();

int main(){  
    hangman h;  
    string name , month;
    char letter;
    string months[] =
	{
		"january",
		"february",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"
	};

    srand(time(NULL));
    int n=rand()%12;
    month=months[n];
    
    string hide_month(month.length(),'X');
     
    while(Num_Try!=0){
        main_menu();

        cout<<"\t\t\t\t"<<hide_month<<endl;

        cout<<"\n\n\nGuess a letter  ::  ";cin>>letter;

        if(h.checkHangmanGuess(letter,month,hide_month)==0){
            
            cout<<"Incorrect Letter"<<endl;
            Num_Try--;
            sleep(1);
        }
        else{
            
            cout<<"\nNice , you guess the letter"<<endl;
            sleep(1);
        }

        if(hide_month==month){
            main_menu();
            cout<<"\n\n\t\tCongratulations! you won the game "<<endl;
            cout<<"\t\t\tThe month is : "<<month<<endl;
            break;
        }
    }
    if(Num_Try==0){
        cout<<"\n\n\t\tNoo , you have been hanged"<<endl;
        main_menu();
        cout<<"\n\n\t\t\tThe month is :"<<month<<endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}

void main_menu(){
    system("cls");

    cout<<"=============================================================================="<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"#########################     HANGMAN GAME     ###############################"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"=============================================================================="<<endl;

    cout<<"\n\nYou have only "<<Num_Try<<" tries, guess the month"<<endl;
    cout<<"\n\n@@@@@@@@@@@@@@@@@@@@@@@@@    PLAY   @@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;

}