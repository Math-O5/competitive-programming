/******************************************************************************
739 - Soundex Indexing
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int convert(char up) {
    return ((int)up - 'A');
}

int alpha[27];

void set() {
//-1 = A, E, I, O, U, Y, W and H
alpha[0] = -1; alpha[14] = -1; 
alpha[4] = -1; alpha[convert('O')] = -1;
alpha[8] = -1; alpha[convert('U')] = -1;
alpha[convert('Y')] = -1; alpha[convert('W')];
alpha[convert('H')] = -1;
//1 = B, P, F, V
alpha[1] = 1; alpha[5] = 1;
alpha[convert('P')] = 1; alpha[convert('V')] = 1;
//2 = C, S, K, G, J, Q, X, Z
alpha[2] = 2; alpha[convert('J')] = 2;
alpha[convert('S')] = 2; alpha[convert('Q')] = 2;
alpha[convert('K')] = 2; alpha[convert('X')] = 2;
alpha[6] = 2;alpha[convert('Z')];
//3 = D, T
alpha[3] = 3; alpha[convert('T')] = 3;
//4 = L
alpha[convert('L')] = 4;
//5 = M, N
alpha[convert('M')] = 5; alpha[convert('N')] = 5;
//6 = R
alpha[convert('R')] = 6;
}

void space(string name) {
     for(int i = name.size(); i <= 25; ++i) cout<< ' ';
}
int main()
{
    set();
    string name;
    string encoded; int j;
    int aux;
    cout << "          NAME                     SOUNDEX CODE" << endl;
    while(getline(cin, name)) {
	  getchar();
        encoded.clear();
        j = 1;
        char c = '0'+ alpha[convert(name[0])];
        encoded.push_back(c);
        for(int i = 1; i < name.size(); ++i) {
            if(encoded.size() >= 4) break;
            aux = convert(name[i]);
            if(alpha[convert(name[i-1])] != alpha[convert(name[i])]) {
                switch(alpha[aux]) {
                    case -1:
                    break;
                    case 1:
                        encoded.push_back('1');
                    break;
                    case 2:
                        encoded.push_back('2');
                    break;
                    case 3:
                        encoded.push_back('3'); 
                    break;
                    case 4:
                        encoded.push_back('4'); 
                    break;
                    case 5:
                        encoded.push_back('5');
                    break;
                    case 6:
                        encoded.push_back('6');
                    break;
                    default: break;
                }
            }
            
        }
        
        encoded[0] = name[0];
        for(int i = encoded.size(); i < 4; ++i) {
            encoded.push_back('0');
        }    
        cout <<"          "<<  name;
        space(name);
        cout << encoded << endl;
    }
    cout << "                    END OF FILE" << endl;
    
    
    return 0;
}