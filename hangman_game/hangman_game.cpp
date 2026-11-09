#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include "myRandomLib.h"

using namespace std;

string GenerateRandomWord() {
    string words[4] = { "Apple", "Table", "Orange", "Pensil" };
    return words[myRandomLib::RandomNumber(0, 3)];
}

void PrintHeader() {
    cout << "-----------------------------------\n";
    cout << "|           HANGMAN GAME          |\n";
    cout << "-----------------------------------\n";

}

void DrawHangman(int remainingLives) {
    switch (remainingLives) {
    case 6:
        cout << "\n  +---+     " << endl;
        cout << "      |     " << endl;
        cout << "      |     " << endl;
        cout << "      |     " << endl;
        cout << "     ===    " << endl;
        break;
    case 5:
        cout << "\n  +---+     " << endl;
        cout << "  O   |     " << endl;
        cout << "      |     " << endl;
        cout << "      |     " << endl;
        cout << "     ===    " << endl;
        break;
    case 4:
        cout << "\n  +---+     " << endl;
        cout << "  O   |     " << endl;
        cout << "  |   |     " << endl;
        cout << "      |     " << endl;
        cout << "     ===    " << endl;
        break;
    case 3:
        cout << "\n  +---+     " << endl;
        cout << "  O   |     " << endl;
        cout << " /|   |     " << endl;
        cout << "      |     " << endl;
        cout << "     ===    " << endl;
        break;
    case 2:
        cout << "\n  +---+     " << endl;
        cout << "  O   |     " << endl;
        cout << " /|\\  |     " << endl;
        cout << "      |     " << endl;
        cout << "     ===    " << endl;
        break;
    case 1:
        cout << "\n  +---+     " << endl;
        cout << "  O   |     " << endl;
        cout << " /|\\  |     " << endl;
        cout << " /    |     " << endl;
        cout << "     ===    " << endl;
        break;
    case 0:
        cout << "\n  +---+     " << endl;
        cout << "  O   |     " << endl;
        cout << " /|\\  |     " << endl;
        cout << " / \\  |     " << endl;
        cout << "     ===    " << endl;
        cout << "GAME OVER!\n" << endl;
        break;
    }
}

void FillVectorWithSpaces(vector<char>& vAnswer, string word) {
    for (char &c : word) {
        vAnswer.push_back('_');
    }
}

void PrintAnswerVector(vector<char>& vAnswer) {
    cout << '[';
    for (int i = 0; i < vAnswer.size(); i++) {
        if (i < vAnswer.size() - 1)
            printf(" %c ,", vAnswer.at(i));
        else 
            printf(" %c ", vAnswer.at(i));

    }
    cout << ']'<<endl;
}

char ReadChar(string Message) {
    cout << Message << endl;
    char c;
    cin >> c;
    return c;
}

bool IsCharInWord(vector<char>& vAnswer, string word, char c) {
    unsigned short replacements = 0;
    for (int i = 0; i < word.length(); i++) {
        if (c == word[i]) {
            vAnswer[i] = c;
            replacements++;
        }
    }
    return (replacements > 0) ? true : false;
}

bool IsCharInVector(vector<char>& vAnswer, char c) {
    for (char& ch : vAnswer) {
        if (ch == c)return true;
    }
    return false;
}

void PlayRound(vector<char>& vAnswer, string word, unsigned short &Attempts) {
    char c = ReadChar("Please enter a character? ");
    if (!IsCharInVector(vAnswer, c) &&  IsCharInWord(vAnswer, word, c)) {
        cout << "Right answer\n";
        system("color 2F");
    }
    else {
        Attempts--;
        DrawHangman(Attempts);
        system("color 4F");
        printf("Wrong answer\nYou have %d attempts more\n", Attempts);
    }
}

void DidUserWinOrLose(vector<char>& vAnswer, unsigned short Attempts) {
    if (Attempts == 0) {
        cout << "You Lost :-(\n";
        DrawHangman(Attempts);
    }
    else {
        PrintAnswerVector(vAnswer);
        cout << "You Won :-)" << endl;
    }
}

void StartGame() {
    string word = GenerateRandomWord();
    vector<char> vAnswer;
    FillVectorWithSpaces(vAnswer, word);
    PrintHeader();
    unsigned short Attempts = 6;
    DrawHangman(Attempts);
    do {
        PrintAnswerVector(vAnswer);
        PlayRound(vAnswer, word, Attempts);
        cout << endl;
    } while (Attempts > 0 && IsCharInVector(vAnswer,'_'));
    DidUserWinOrLose(vAnswer, Attempts);
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}
