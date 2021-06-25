using namespace std;
#include<string>

class hangman{
    public:
    int checkHangmanGuess(char guess ,string secret_m , string &guess_m){
        int i,matches=0;
        int len=secret_m.length();
        for(i=0;i<len;i++){
            if(guess_m[i]==guess)
               return 0;
            if(secret_m[i]==guess){
                matches+=1;
                guess_m[i]=guess;
            }               
        }
        
        
        return matches;

    }
};