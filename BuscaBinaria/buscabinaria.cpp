#include <iostream>
#include <stdlib.h>

using namespace std;

int main (){
    int inicio = 1, fim = 1000000000;

    while(true){
        int meio = (inicio + fim)/2;
        cout << "Q " << meio << endl;
        char resp;
        cin >> resp;

        if(resp == '<'){
            fim = meio - 1;
        }
        if(resp == '>'){
            inicio= meio + 1;
        }
        if(resp == '='){
            return 0;
        }
    }
}
