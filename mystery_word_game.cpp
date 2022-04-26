#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "liste.hpp"

using namespace std;

//------------------------------------------------
// Take a random number between 0 and 9
int random_Number(){

  int rand_number(0);

  srand(time(0));
  rand_number = rand() % 10;
  return rand_number;
}

//------------------------------------------------
// Take a radom word with the random number selected before
string random_Word(){

  liste<string> ls;
  string rand_word;

  ls = { "mystere", "xylophone", "abeille", "pluton", "magique", "avertissement", "bureau", "couette", "chat" };
  rand_word = ls[random_Number()];
  return rand_word;
}

//------------------------------------------------
// Blend the letter of the mystery word
string letter_Blend(string word){

  string blend;
  int position(0);

  while (word.size() != 0){
    position = rand() % word.size();
    // Add the letter in the blended word
    blend += word[position];
    // Remove the letter from the mystery word to not take it a second time
    word.erase(position, 1);
    }
  return blend;
}

//------------------------------------------------
//Main program
int main(){

  string mystery_word, blended_word, user_word;
  char new_game;
  int game_try;

  do{
  srand(time(0));
  game_try = 3;
  mystery_word = random_Number();
  blended_word = letter_Blend(mystery_word);
  do{
    if ( game_try > 1){
      cout << endl << "Quel est ce mot ? " << blended_word << endl<< "Vous avez "<< game_try<< " chances. ";
    }
    else{
      cout << endl << "Quel est ce mot ? " << blended_word << endl<< "Il ne vous reste plus que "<< game_try<< " chance ! ";
    }
    cin >> user_word;
    if (user_word == mystery_word){
      cout << "Bravo ! " << endl;
    }
    else{
      cout << "Ce n'est pas le mot ! " << endl;
      game_try = game_try - 1;
    }
  }while (( user_word != mystery_word ) and ( game_try > 0 ));
  if ( game_try == 0){
    cout<< "Perdu ! Vous n'avez plus d'essai! Le mot mystère était : "<< mystery_word<< endl;
  }
  cout<< "Voulez vous faire une autre partie ? ( o/n ) "<< endl;
  cin>> new_game;
  }while ( new_game == 'o' );
  return 0;
}
