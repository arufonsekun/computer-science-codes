#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

void bin2Dec(string binary){
    unsigned int output = 0;

    output = ( ((int)binary[0] - 48) * 2 + ((int)binary[1] -48) );
    if (binary.size() > 2){
        for (unsigned int i = 2; i < binary.size(); i++){
            output = output * 2 + ((int)binary[i] - 48);
            //cout << binary[i] << endl;
        }
    }
    cout << output << endl;

}

void dec2Bin(unsigned int decimal)
{
    vector<int> output;
    unsigned int short rest;
    unsigned int quocient = decimal;

    while (quocient >= 1)
    {
        rest = quocient % 2;
        output.push_back(rest);
        quocient = quocient / 2;
    }

    unsigned int i = output.size();
    for (i >= 0; i--;)
    {
        cout << output.at(i);
    }
    cout << endl;

}

int main(){
    unsigned short int operation;
    string binary;
    unsigned int decimal;

    printf("Digite 0 para converter de bin para dec ou 1 caso contrario: ");
    cin >> operation;

    if (operation == 0){
        cin >> binary;
        if (binary.size() == 1)
            cout << binary;
        else
            bin2Dec(binary);
    }
    else{
        cin >> decimal;
        dec2Bin(decimal);
    }
    return 0;
}
