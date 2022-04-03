#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */

using namespace std;

char *random_word();
bool hang_man(char *, int);
void show_status(char *, int[]);
bool isGameFinished(int[], int);
void display_misses(int misses, char *word);

int main()
{
    cout << BLUE << "****************************************************************************" << endl
         << endl;
    cout << YELLOW << "\tHello friends,\n\n\t Welcome to my Hang-Man game!! \n\tThis game is written by Masih Tanoursaz in C++ language. " << endl;
    cout << BLUE
         << endl
         << "****************************************************************************" << endl
         << RESET
         << endl;
    char *choosen_word = random_word();
    int guess = strlen(choosen_word) + 6;
    if (hang_man(choosen_word, guess))
    {
        cout << endl
             << GREEN
             << "\aYou Won! " << RESET << endl;
        system("pause");
    }
    else
        cout << " \aIt seems you can't guess our word!";
    return 0;
}

char *random_word() // Choose a random word
{
    srand(time(NULL));
    const int count_of_word = 5;
    static char name[count_of_word][50] = {
        "Animal",
        "Friend",
        "Pencil",
        "Happy",
        "Wikihow",
    };
    int random_index = rand() % count_of_word;
    return name[random_index];
}

void show_status(char *word, int founded_indexes[])
{
    for (int i = 0; i < strlen(word); i++)
        if (founded_indexes[i] == 1)
            cout << word[i];
        else
            cout << " - ";
}

bool isGameFinished(int founded_indexes[], int Size)
{
    for (int i = 0; i < Size; i++)
        if (founded_indexes[i] == 0)
            return false;
    return true;
}

bool hang_man(char *word, int guess)
{
    char tmp;
    char tries[guess];
    int t = 0;
    for (int m = 0; m < guess; m++) // Create an empty array
    {
        tries[m] = (char)0;
    }
    int founded_indexes[strlen(word)] = {0}, right_guess;
    for (int i = 0; i < guess; i++)
    {
        right_guess = 0;
        if (isGameFinished(founded_indexes, strlen(word)))
        {
            cout << RED << endl
                 << "The word was : " << YELLOW << word << RESET << endl;
            return true;
        }

        if (i)
        {
            cout << RED << endl
                 << "You've tried this chars before :" << RESET << endl;
            for (int m = 0; m < guess; m++)
            {
                cout << YELLOW << tries[m] << RESET << "\t"; // Index tried charcters in an array
            }
            cout << endl
                 << endl;
        }
        show_status(word, founded_indexes);
        cout << endl
             << "#" << i + 1 << ", guess :";
        cin >> tmp;
        for (int j = 0; j < strlen(word); j++) // Check the charcters of tmp with the word
        {
            if (word[j] == tmp || word[j] == (tmp - 32))
            {
                founded_indexes[j] = 1;
                right_guess++;
            }
        }

        system("cls");
        if (right_guess != 0)
        {
            cout << endl
                 << YELLOW << "====>>>>  " << GREEN
                 << right_guess << "  " << BLUE << tmp << GREEN << "   found in word! " << RESET << endl;
        }
        else
        {
            tries[t] = tmp;
            t++;
            system("cls");
            display_misses(t, word);
            cout << endl
                 << " No match found!" << endl;
        }
    }
    return false;
}

void display_misses(int misses, char *word)
{
    switch (misses)
    {
    case 0:
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
        break;
    case 1:
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
        break;
    case 2:
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "  |   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
        break;
    case 3:
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
        break;
    case 4:
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
        break;
    case 5:
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << " /    | \n";
        cout << "      | \n";
        cout << " ========= \n";
        break;
    case 6:
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << " / \\  | \n";
        cout << "      | \n";
        cout << " ========= \n";
        cout << endl;
        cout << RED << "\aIt seems you can't guess our word!" << RESET << endl;
        cout << RED << endl
             << "The word was : " << YELLOW << word << RESET << endl;
        system("pause");
        exit(0);
        break;
    default:
        break;
    }
}
