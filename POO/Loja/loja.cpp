#include "loja.h"
//Implementação das Classes e metodos

//Classe Marca

//metodos construtor e destrutor
Marca::Marca(const string& nom): nome(nom){}
Marca::~Marca(){}

//metodos de definir e obter o atributo nome
string& Marca::get_nome(){
    return nome;
}
void Marca::set_nome(const string& nom){
    nome = nom;
}

//Classe Roupa

//Construtor e Destrutor dos atributos da classe
Roupa::Roupa(const string& tip, const string& tam, int id): tipo(tip), identificador_unico(id), tamanho(tam){}
Roupa::~Roupa(){}

//Metodos de definir e obter os atributos
string& Roupa::get_tipo(){
    return tipo;
}
void Roupa::set_tipo(const string& tip){
    tipo = tip;
}

string& Roupa::get_tamanho(){
    return tamanho;
}
void Roupa::set_tamanho(const string& tam){
    tamanho = tam;
}

int Roupa::get_id() const {
    return identificador_unico;
}
void Roupa::set_id(int id){
    identificador_unico = id;
}

//Metodo para adicionar e remover marcas usando sobrecarga dos operadores de soma e subtração.
Roupa& Roupa::operator+(Marca* marca) {
    marcas.push_back(marca);
    return *this;
}
Roupa& Roupa::operator-(const string& nomeMarca) {
    for(auto it = marcas.begin(); it != marcas.end(); ++it) {
        if ((*it)->get_nome() == nomeMarca) {
            marcas.erase(it);
            break;
        }
    }
    return *this;
}

//Classe Loja

//Construtor e Destrutor dos atributos da classe, por não ter atributos para carregar não há parametros ou ações.
Loja::Loja(){}
Loja::~Loja(){}

//Metodo para adicionar e remover roupas usando sobrecarga dos operadores de soma e subtração.
Loja& Loja::operator+(Roupa* roupa) {
    roupas.push_back(roupa);
    return *this;
}

Loja& Loja::operator-(int id) {
    auto it = roupas.begin();
    while (it != roupas.end()) {
        if ((*it)->get_id() == id) {
            delete *it;
            std::cout << "\tRoupa removida\n" << std::endl;
            it = roupas.erase(it);
        } else {
            ++it;
        }
    }
    return *this;
}

//Metodo para exibir as roupas da loja
void Loja::exibir_roupas()const {
    for (Roupa* roupa : roupas) {
        roupa->info();
        std::cout << std::endl;
    }
}

//Classes herdeiras da Classe roupa:

//Roupa Adulta
//Construtor e Destrutor dos atributos da classe. Lembrando que os atributos da classe base tambem devem ser inicializados
RoupaAdulta::RoupaAdulta(const string& tip, const string& tam, int id, const string& tec): Roupa(tip, tam, id), tipo_tecido(tec){}
RoupaAdulta::~RoupaAdulta(){}

//Metodos de definir e obter os atributos
string& RoupaAdulta::get_tipo_tecido(){
    return tipo_tecido;
}
void RoupaAdulta::set_tipo_tecido(const string& tec){
    tipo_tecido = tec;
}

//metodo virtual herdado sera sobrescrito.
void RoupaAdulta::info(){
    std::cout << "Marca-Umbro " << "Tipo: " << get_tipo() << " | " << "Tamanho: " << get_tamanho() << " | " << "Codigo: " << get_id() << " | " << "Faixa Etaria: " << get_tipo_tecido() << std::endl;
}

//Roupa Infantil

//Construtor e Destrutor dos atributos da classe. Lembrando que os atributos da classe base tambem devem ser inicializados
RoupaInfantil::RoupaInfantil(const string& tip, const string& tam, int id, const string& f_etaria): Roupa(tip, tam, id), faixa_etaria(f_etaria){}
RoupaInfantil::~RoupaInfantil(){}

//Metodos de definir e obter os atributos
string& RoupaInfantil::get_faixa_etaria(){
    return faixa_etaria;
}
void RoupaInfantil::set_faixa_etaria(const string& f_etaria){
    faixa_etaria = f_etaria;
}
//metodo virtual herdado sobrescrita.
void RoupaInfantil::info(){
    std::cout << "Marca-Umbro " << "Tipo: " << get_tipo() << " | " << "Tamanho: " << get_tamanho() << " | " << "Codigo: " << get_id() << " | " << "Faixa Etaria: " << get_faixa_etaria() << std::endl;
}

