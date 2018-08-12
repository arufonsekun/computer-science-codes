#include <iostream>
#include <cstring>

using namespace std;

char operating1[156];
char operating2[156];
int rest[156];
char output[156];

void print(){
    bool findNumber = false;
    for (int i = 0; i <= 155; i++){
        if (findNumber == false & output[i] != '0')
            findNumber = true;

        if (findNumber == true)
            cout << output[i];
    }
    cout << endl;
}

void summ(){
    int short sum = 0;
    string buffer;

    int i = 155;
    while (i >= 0){
        sum = (((int)operating1[i] - 48) + ((int)operating2[i] - 48) + rest[i]);
        buffer = to_string(sum);
        //cout << buffer << endl;
        if (buffer.size() == 2){
            rest[i-1] = ((int)buffer.at(0) -48);
            output[i] = buffer.at(1);
        }
        else{
            output[i] = buffer.at(0);
        }
        i--;
    }

}

void alignRight(char input1[156], char input2[156])
{
    int index = 155;
    int e = strlen(input1);

    for(e >= 0 ; e--;)
    {
        operating1[index] = input1[e];
        index--;
    }

    index = 155;
    int i = strlen(input2);
    for (i >= 0; i--;)
    {
        operating2[index] = input2[i];
        index--;
    }

}

int main()
{
    char bigNum1[156];
    char bigNum2[156];

    memset(operating1, '0', 156);
    memset(operating2, '0', 156);
    memset(rest, 0, 156);
    memset(output, '0', 156);

    cin >> bigNum1;
    cin >> bigNum2;

    alignRight(bigNum1, bigNum2);

    summ();
    print();

    //printf("%d\n", ((int)operating1[155] -48) + ((int) operating2[155] -48));

    return 0;
}
