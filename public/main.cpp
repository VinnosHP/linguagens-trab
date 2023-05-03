#include <iostream>
using namespace std;

int indiceSimbolo(char simbolo){
    if(simbolo == 'a')
        return 0;
    else{
        if(simbolo == 'b')
            return 1;
        else{
            if(simbolo == 'c')
                return 2;
            else{
                if(simbolo == 'd')
                    return 3;
                else{
                    if(simbolo == 'e')
                        return 4;
                    else
                        return 5;
                }
            }
        }
    }
}

int main() {
    char simbolo;
    int estado;
    int tabelaT[11][6] ={
         // A| B| C| D| E|Er
    /* 1*/{10,10, 6, 9,10,10},
    /* 2*/{10,10,10, 9,10,10},
    /* 3*/{ 3,10, 0, 7,10,10},
    /* 4*/{10, 4,10,10,10,10},
    /* 5*/{ 5,10,10,10,10,10},
    /* 6*/{10, 2,10,10,10,10},
    /* 7*/{10,10, 0, 7,10,10},
    /* 8*/{10,10,10,10, 1,10},
    /* 9*/{10,10,10, 7,10,10},
    /*10*/{10,10,10,10, 8,10},
    /*11*/{10,10,10,10,10,10}};
                 // 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11
    bool ef[11] = { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    estado = 2;
    cout << "Simbolo: ";  cin >> simbolo;
    while(simbolo != '$'){
        cout << "Estado: " << estado << endl;
        cout << "Antes do indice: "<< simbolo << endl;
        int indice = indiceSimbolo(simbolo);
        cout << "Depois, indice: " << indice << endl;
        estado = tabelaT[estado][indice];
        cout << "Estado: " << estado << endl;
        cout << "Simbolo: ";    cin >> simbolo;
    }
    if(ef[estado] == 1)
        cout << "Sentenca reconhecida!"<<endl;
    else
        cout << "Sentenca nao reconhecida!" << endl;
    return 0;
}
