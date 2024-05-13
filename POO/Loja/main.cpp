#include <iostream>
#include "loja.h"

using namespace std;

int main(){
    Loja GremioMania; //criando a loja
    Marca umbro("Umbro"); //criando a marca da loja, que pode ter mais de uma marca, no nosso caso a loja de um clube só possui um fornecedor

    RoupaAdulta tricolor2024("Camiseta Tricolor 2024", "M", 202201, "Poliester"); //criando uma roupa adulta para a loja
    tricolor2024 + &umbro; //adicionando essa roupa a marca

    RoupaInfantil tricolor2024Inf("Camiseta Tricolor Infantil 2024", "PP", 202202, "02-03 anos"); //criando uma roupa infantil para a loja
    tricolor2024Inf + &umbro; //adicionando essa roupa a marca

    //adicionando as roupas a loja
    GremioMania + &tricolor2024;
    GremioMania + &tricolor2024Inf;

    int opcao;

    cout << "\tBem-vido a Gremio Mania!\n" << endl;
    cout << "1. Exibir Roupas\n" << "2. Adicionar Roupa Infantil\n" << "3. Adcionar Roupa Adulta\n" << "4. Remover Roupa\n" << "0. Fechar Sistema\n";


    cout << "Escolha uma opcao: ";
    cin >> opcao;
    cout << " \n";

    while(opcao != 0){
        switch(opcao){
            case 1:
                GremioMania.exibir_roupas();
                break;
            case 2:{
                string tipo;
                cout << "\tTipo da Roupa: ";
                cin >> tipo;

                string tamanho;
                cout << "\tTamanho: ";
                cin >> tamanho;

                int indic;
                cout << "\tCodigo: ";
                cin >> indic;

                string f_etaria;
                cout << "\tFaixa Etaria: ";
                cin.ignore();
                cin >> f_etaria;

                RoupaInfantil roupainf(tipo, tamanho, indic, f_etaria);
                roupainf + &umbro;
                GremioMania + &roupainf;
                cout << "\nRoupa Infantil Inserida ao estoque.\n";
                break;
            }
            case 3:{
                string tipo;
                cout << "\tTipo da Roupa: ";
                cin >> tipo;

                string tamanho;
                cout << "\tTamanho: ";
                cin >> tamanho;

                int indic;
                cout << "\tCodigo: ";
                cin >> indic;

                string tecido;
                cout << "\tFaixa Etaria: ";
                cin.ignore();
                cin >> tecido;

                RoupaAdulta roupa(tipo, tamanho, indic, tecido);
                roupa + &umbro;
                GremioMania + &roupa;
                cout << "\nRoupa Adulta Inserida ao estoque.\n";
                break;
            }
            case 4:{
                int indic;
                cout << "\tCodigo da Roupa: ";
                cin >> indic;
                GremioMania - indic;
                break;
            }
        }

        cout << "1. Exibir Roupas\n" << "2. Adicionar Roupa Infantil\n" << "3. Adcionar Roupa Adulta\n" << "4. Remover Roupa\n" << "0. Fechar Sistema\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << " \n";
    }

    return 0;
}
