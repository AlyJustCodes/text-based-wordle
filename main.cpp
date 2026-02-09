#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <strings.h>


int main()
{
    std::string arrWords[4] = {"hello", "world", "check","extra"};


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 3);
    std::string currWord = arrWords[distr(gen)];

    std::map<char,int> lettersDict;
    bool gameWon = false;
    // const std::string currWord = arrWords[0];
    std::string currUserWord = "-----";

    std::cout << "Welcome to Wordle:\n" << \
    "Capital means letter is in correct location.\n" <<\
    "Lowercase exists in the word but is in the wrong location.\n" << \
    "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << \
    "Guess a word" << std::endl;




    while (!gameWon)
    {
        lettersDict.clear();
        for (char c : currWord)
        {
            lettersDict[c]++;
        }
        std::cout << currUserWord << std::endl;
        std::string newWord;
        while (newWord.length() != 5)
        {
            std::cin >> newWord;
        }
        for (int i = 0; i < currWord.length(); i++)
        {
            newWord[i] = std::tolower(newWord[i]);
        }
        currUserWord = "-----";

        std::map<int,bool> correctLetters;
        for (int i = 0; i <= currWord.length(); i++)
        {
            if (newWord[i] == currWord[i])
            {
                currUserWord[i] = std::toupper(newWord[i]);
                lettersDict[newWord[i]] -= 1;
                correctLetters[i] = true;
            }
        }
        for (int i = 0; i < currWord.length(); i++)
        {
            if (currWord.find(newWord[i]) != std::string::npos && lettersDict[newWord[i]] > 0 && !correctLetters[i])
            {
                currUserWord[i] = std::tolower(newWord[i]);
                lettersDict[newWord[i]] -= 1;
            }
        }

        if (strcasecmp(currUserWord.c_str(), currWord.c_str()) == 0)
        {
            gameWon = true;
            std::cout << currUserWord << std::endl;
        }
    }

    std::cout << "GGS! The word was: " << currWord << std::endl;

    return 0;
}