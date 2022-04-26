#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "liste.hpp"

using namespace std;

//------------------------------------------------
// Take a random number between 0 and 9
int random_Number()
{
    int rand_number(0);

    srand(time(0));
    rand_number = rand() % 10;
    return rand_number;
}

//------------------------------------------------
// Take a random word in the list with the random number
string random_Word()
{

    liste<string> ls;
    string rand_word;

    ls = {"mystere", "xylophone", "abeille", "pluton", "magique", "avertissement", "bureau", "couette", "chat"};
    rand_word = ls[random_Number()];
    return rand_word;
}

//------------------------------------------------
// Mix the letter of the mystery word selected before
string letter_Mix(string word)
{
    // Variables locales
    string mix;
    int position(0);

    while (word.size() != 0)
    {
        position = rand() % word.size();
        // Add the letter in the mixed word
        mix += word[position];
        // Take out the letter added before of the word
        word.erase(position, 1);
    }
    return mix;
}

//------------------------------------------------
// Main program
int main()
{

    string mystery_word, mixed_word, user_word;
    char new_game;
    int try_amout;

    do
    {
        srand(time(0));
        try_amout = 3;
        mystery_word = random_Word();
        mixed_word = mixrLettres(mystery_word);
        do
        {
            if (try_amout > 1)
            {
                cout << endl
                     << "Quel est ce mot ? " << mixed_word << endl
                     << "Vous avez " << try_amout << " chances. ";
            }
            else
            {
                cout << endl
                     << "Quel est ce mot ? " << mixed_word << endl
                     << "Il ne vous reste plus que " << try_amout << " chance ! ";
            }
            cin >> user_word;
            if (user_word == mystery_word)
            {
                cout << "Bravo ! " << endl;
            }
            else
            {
                cout << "Ce n'est pas le mot ! " << endl;
                try_amout = try_amout - 1;
            }
        } while ((user_word != mystery_word) and (try_amout > 0));
        if (try_amout == 0)
        {
            cout << "Perdu ! Vous n'avez plus d'essai. Le mot mystère était : " << mystery_word << endl;
        }
        cout << "Voulez vous faire une autre partie ? ( o/n ) " << endl;
        cin >> new_game;
    } while (new_game == 'o');
    return 0;
}
