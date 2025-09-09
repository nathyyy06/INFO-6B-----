#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main(){
    std::map<char, int> alphabet = {
        {'A', 1},{'B', 2},{'C', 3},{'D', 4},{'E', 5},{'F', 6},{'G', 7},
        {'H', 8},{'I', 9},{'J',10},{'K',11},{'L',12},{'M',13},{'N',14},
        {'O',15},{'P',16},{'Q',17},{'R',18},{'S',19},{'T',20},{'U',21},
        {'V',22},{'W',23},{'X',24},{'Y',25},{'Z',26}
    };

    int testCase; 
    if(!(cin >> testCase)) return 0;
    cin.ignore();

    for(int tc = 0; tc < testCase; ++tc){
        string inputLetters;
        getline(cin, inputLetters);

        int skips; 
        cin >> skips;
        cin.ignore();

        vector<char> letters;
        istringstream separated(inputLetters);
        char ch;
        while(separated >> ch) letters.push_back(ch);

        map<int, char> pairingLettersToNumbers;
        for (const auto &p : alphabet) pairingLettersToNumbers[p.second] = p.first;

        for (char letter : letters) {
            int num = alphabet[letter];    
            int orig = num - skips;            
            while (orig <= 0) orig += 26;
            while (orig > 26) orig -= 26;
            cout << pairingLettersToNumbers[orig];
        }
        cout << '\n';
    }

    return 0;
}
