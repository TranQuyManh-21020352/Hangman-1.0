#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
bool contains(string secretWord, char guess)
{
    for(int i = 0; i < secretWord.size(); i++)
    {
        if(secretWord[i] == guess)
        {
            return true;
        }
    }
    return false;
}
string update(string guessedWord, char guess, string secretWord)
{
    for(int i = 0; i < secretWord.size(); i++)
    {
        if(secretWord[i] == guess)
        {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}

string yourguessedword(string yourGuessedWord,char guess)
{
yourGuessedWord.insert(yourGuessedWord.end(), guess);
return yourGuessedWord;
}

char readAGuess()
{
    cout<<"your guess: ";
    char guess;
    cin>>guess;
    cout<<endl<<endl;
    return guess;
}

int Numberchecked(string yourGuessedWord, char guess)
{
    int Count = 0;
    for(int i =0; i < yourGuessedWord.size(); i++)
    {
        if(yourGuessedWord[i] == guess)
        {
            Count++;
        }
    }
    return Count;
}

char checkedGuess(string yourGuessedWord, char guess)
{
    int Count = Numberchecked(yourGuessedWord,guess);
    if(Count == 0)
    {
        return guess;
    }
    else{
            int Counts = Count;
            char guessAgain;
    do{
       if(Counts != 0)
      {
        cout<<"Please guess again! The word you selected has been duplicated"<<endl;
        cout<<"your guess: ";
        cin>>guessAgain;
        Counts = Numberchecked(yourGuessedWord, guessAgain);
       }
    }
     while(Counts != 0);
     guess = guessAgain;
     return guess;
          }
}

const string Word_List[] = {"dog", "cat", "play","comeback","guess","hello","cammera","smartphone","telephone","love","chess"};
const int Word_Count = sizeof(Word_List)/sizeof(string);
string chooseWord()
{
    int randomIndex = rand() % Word_Count;
    return Word_List[randomIndex];
}
const string FIXGURE[] ={" _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |             |     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|\\    |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|\\    |\n"
                            "|   |            /      |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|\\    |\n"
                            "|   |            / \\    |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n"};
void renderGame(string guessedWord, int badGuessCount,string yourGuessedWord)
{
    cout<<FIXGURE[badGuessCount]<<endl<<endl;
    cout<<"your guessed: "<<guessedWord<<endl;
    cout<<"your guessedWord: "<<yourGuessedWord<<endl;
    cout<<"Number of guess wrong: "<<badGuessCount<<endl;
}
int main()
{
    srand(time(0));
    string yourAnswer;
     while(yourAnswer != "no")
        {
            int Count = 1;
            string yourGuessedWord = "";
            const int Max_Bad_Guess = 7;
            string secretWord,guessedWord = "";
            secretWord = chooseWord();
            char guess;
     for(int i = 0; i < secretWord.size(); i++)
     {
         guessedWord = guessedWord + "-";
     }
     int badGuessCount = 0;
     do{
             renderGame(guessedWord,badGuessCount,yourGuessedWord);
             guess = readAGuess();
             if(Count == 1){
             yourGuessedWord = yourguessedword(yourGuessedWord, guess);
             }
             if(Count > 1){
                 guess = checkedGuess(yourGuessedWord,guess);
                 yourGuessedWord = yourguessedword(yourGuessedWord, guess);
             }
        if(contains(secretWord,guess) == true)
        {
           guessedWord = update(guessedWord,guess,secretWord);
        }
        else{
            badGuessCount ++;
        }
        if(secretWord == guessedWord)
     {
         renderGame(guessedWord,badGuessCount,yourGuessedWord);
         cout<<endl<<"You win! Congratulation."<<endl;
         cout<<"The secret word is: "<<secretWord<<endl;
         cout<<endl;
         cout<<"Do you want to continue playing? : "<<endl;
         cout<<"your Answer: ";
         cin>>yourAnswer;
         if(yourAnswer == "yes")
         {
             cout<<"please continue!"<<endl;
             badGuessCount = 0;
             cout<<endl;
             break;
         }
         else
         {
             cout<<"Thank you! The next people."<<endl;
         }
     }
      if(badGuessCount == Max_Bad_Guess && secretWord != guessedWord)
     {
         renderGame(guessedWord,badGuessCount,yourGuessedWord);
         cout<<endl<<"You lose! The corect word is: "<<secretWord<<endl;
         cout<<endl;
         cout<<"Do you want to continue playing? : "<<endl;
         cout<<"your Answer: ";
         cin>>yourAnswer;
         if(yourAnswer == "yes")
         {
             cout<<"please continue!"<<endl;
             badGuessCount = 0;
             cout<<endl;
             break;
         }
         else
         {
             cout<<"Thank you! The next people."<<endl;
         }
     }
     Count++;
     }
     while(badGuessCount < Max_Bad_Guess && secretWord != guessedWord);
     }
}
