#include <iostream>
#include <string>

using namespace std;

char ReadCharacter()
{
    char Letter;
    cout << "Please, Enter a character:\n";
    cin >> Letter;
    return Letter;
}

char InvertedCharacterCase(char Letter)
{
    return islower(Letter) ? toupper(Letter) : tolower(Letter);
}

int main()
{
    
    cout << "The inverted Character:\n" << InvertedCharacterCase(ReadCharacter()) << endl;

    system("pause>0");
}
