#ifndef LOJA_H
#define LOJA_H

#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;


//Interface das Classes criadas com suas propiedades e metodos

//Classe Marca
class Marca{
private:
    string nome;
public:
    //Construtor e Destrutor dos atributos da classe
    Marca(const string& nom);
    ~Marca();
    //Metodos de definir e obter o atributo nome
    string& get_nome();
    void set_nome(const string& nom);

};

//Classe Roupa
class Roupa{
private:
    string tipo;
    vector<Marca*>marcas;
    string tamanho;
    int identificador_unico;
public:
    //Construtor e Destrutor dos atributos da classe
    Roupa(const string& tip, const string& tam, int id);
    virtual ~Roupa();

    //Metodos de definir e obter os atributos
    string& get_tipo();
    void set_tipo(const string& tip);

    string& get_tamanho();
    void set_tamanho(const string& tam);

    int get_id () const;
    void set_id(int id);

    //Metodo para adicionar e remover marcas usando sobrecarga dos operadores de soma e subtração.
    Roupa& operator+(Marca* marca);
    Roupa& operator-(const string& nomeMarca);

    //metodo virtual puro, o que torna a classe Roupa abstrata, para exibir as informações da roupa.
    virtual void info() = 0;
};

//Classe Loja
class Loja{
private:
    vector<Roupa*>roupas;
public:
    //Construtor e Destrutor dos atributos da classe, por não ter atributos para carregar não há parametros ou ações.
    Loja();
    ~Loja();

    //Metodo para adicionar e remover roupas usando sobrecarga dos operadores de soma e subtração.
    Loja& operator+(Roupa* roupa);
    Loja& operator-(int id);

    //Metodo para exibir as roupas da loja
    void exibir_roupas() const;
};

//Classes herdeiras da Classe roupa:

class RoupaAdulta: public Roupa{
private:
    string tipo_tecido;
public:
    //Construtor e Destrutor dos atributos da classe. Lembrando que os atributos da classe base tambem devem ser inicializados
    RoupaAdulta(const string& tip, const string& tam, int id, const string& tec);
    ~RoupaAdulta();

    //Metodos de definir e obter os atributos
    string& get_tipo_tecido();
    void set_tipo_tecido(const string& tec);

    //metodo virtual herdado sera sobrescrito.
    void info() override;
};

class RoupaInfantil: public Roupa{
private:
    string faixa_etaria;
public:
    //Construtor e Destrutor dos atributos da classe. Lembrando que os atributos da classe base tambem devem ser inicializados
    RoupaInfantil(const string& tip, const string& tam, int id, const string& f_etaria);
    ~RoupaInfantil();

    //Metodos de definir e obter os atributos
    string& get_faixa_etaria();
    void set_faixa_etaria(const string& tec);

    //metodo virtual herdado sera sobrescrita.
    void info() override;
};


#endif // LOJA_H
