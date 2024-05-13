#include <iostream>
#include <string.h>


#include <cstdlib>
#include <ctime>

#define MAX_NOME 80
#define MAX_CARC 12
#define NUM_ISBN 18
#define NUM 15

using namespace std;

// Implementacao das Classes
class funcionario
{
// Atributos
private:
    int matricula;
    char nome[MAX_NOME];
// Metodos
public:
    //metodo construtor:
    funcionario(int mat, const char* nom): matricula(mat){
        strcpy(nome, nom);
    }
    //metodo destrutor:
    ~funcionario(){
        cout << "Registro de Funcionario Apagado." << endl;
    }
    // metodos de controle de valores dos atributos usando getters(obtem valor do atributo) e setters(atribui valor ao atributo):
    int get_matricula() {
        return matricula;
    }
    void set_matricula(int mat) {
        matricula = mat;
    }


    char* get_nome() {
        return nome;
    }
    void set_nome(char* nom) {
        strcpy(nome, nom);
    }


    //metodo para visualizar informacoes do funcionario:
    void info_funcionario() {
        cout << "Funcionario: " << nome << "\tMatricula: " << matricula << endl;
    }
};


class cliente
{
private:
    long long int  matricula;
    char nome[MAX_NOME];
    char cpf[NUM];
    char telefone[NUM];
    char email[MAX_NOME];
public:
    //metodo construtor:
    cliente(long long int mat, const char* nom, const char* ident, const char* fone, const char* mail): matricula(mat){
        strcpy(nome, nom);
        strcpy(cpf, ident);
        strcpy(telefone, fone);
        strcpy(email, mail);
    }
    //metodo destrutor:
    ~cliente(){
        cout << "Registro de Clinte Apagado." << endl;
    }

    // metodos de controle de valores dos atributos usando getters(obtem valor do atributo) e setters(atribui valor ao atributo):
    long long int get_matricula() {
        return matricula;
    }
    void set_matricula(long long int mat) {
        matricula = mat;
    }


    const char* get_nome() {
        return nome;
    }
    void set_nome(char* nom) {
        strcpy(nome, nom);
    }


    const char* get_cpf() {
        return cpf;
    }
    void set_cpf(char* ident) {
        strcpy(cpf, ident);
    }


    const char* get_telefone() {
        return telefone;
    }
    void set_telefone(char* fone) {
        strcpy(telefone, fone);
    }


    const char* get_email() {
        return email;
    }
    void set_email(char* mail) {
        strcpy(email, mail);
    }


    //metodo para visualizar informacoes do cliente:
    void info_cliente() {
        cout << "\nCliente" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Identificador de Usuario: " << matricula << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Email: " << email << endl;
    }

};


class livro
{
private:
    char isbn[NUM_ISBN];
    float valor;
public:
    //metodo construtor:
    livro(const char* id, float val): valor(val){
        strcpy(isbn, id);
    }
    //metodo destrutor:
    ~livro(){
        cout << "Registro de Livro Apagado." << endl;
    }

    // metodos de controle de valores dos atributos usando getters(obtem valor do atributo) e setters(atribui valor ao atributo):
    const char* get_isbn() {
        return isbn;
    }
    void set_isbn(char* id) {
        strcpy(isbn, id);
    }


    float get_valor() {
        return valor;
    }
    void set_valor(float val) {
        valor = val;
    }


    //metodo para visualizar informacoes do livro:
    void info_livro() {
        cout << "\nLivro" << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Valor da Locacao: R$ " << valor << endl;
    }
};


class locacao
{
private:
    int id;
    char data_devolucao[MAX_CARC];
    livro* livr;
    cliente* client;
public:
    //metodo construtor:
    locacao(int id_, const char* data_dev, livro* l, cliente* c): id(id_){
        strcpy(data_devolucao, data_dev);
        livr = l;
        client = c;
    }
    //metodo destrutor:
    ~locacao(){ //metodo destrutor
        cout << "Registro de Locacao Apagado." << endl;
        delete livr;
        delete client;
    }


    // metodos de controle de valores dos atributos usando getters(obtem valor do atributo) e setters(atribui valor ao atributo):
    int get_id() {
        return id;
    }
    void set_id(int id_) {
        id = id_;
    }


    const char* get_data_devolucao() {
        return data_devolucao;
    }
    void set_data_devolucao(char* data_dev) {
        strcpy(data_devolucao, data_dev);
    }


    livro* get_livro(){
        return livr ;
    }
    void set_livro(livro* l){
        livr = l;
    }


    cliente* get_cliente(){
        return client;
    }
    void set_cliente(cliente* c){
        client = c;
    }


    //metodo para visualizar informacoes da locacao:
    void info_locacao() {
        cout << "\n------------LOCACAO REALIZADA COM SUCESSO---------------------\n";
        cout << "\nIdentificador Unico de Locacao: " << id << endl;
        cout << "Data da Devolucao: " << data_devolucao << endl;
        client->info_cliente();
        livr->info_livro();
        cout << "\nATENCAO: Atraso na devolucao gera multa de R$ 2,0 por dia.\n";
        cout << "--------------------------------------------------------------" << endl;
    }
};


//Interface do usuario

int main(){

    //inicio
    cout << "\n\t\tBEM-VINDO!\n" << endl;
    cout << "\nPara iniciar sessao valide os dados de funcionario" << endl;

    //Atributos da Classe Funcionario:
    int matr;
    char nm[MAX_NOME];

    cout << "Matricula: ";

    cin >> matr;
    cout << "Nome: ";
    cin.ignore();
    cin.getline(nm, MAX_NOME);

    //criacao do objeto funcionario com os valores dos atributos definidos pelo usuario
    funcionario* func1 = new funcionario(matr, nm);

    cout << "\nDados validados, sessao iniciada. ";
    //visualizacao dos dados do funcionario
    func1->info_funcionario();


    //Objeto Livro:
    livro* livr1 = new livro("978-85-943-1895-4", 15.60);
    livro* livr2 = new livro("978-85-9454-102-5", 20.00);
    livro* livr3 = new livro("978-85-66636-83-3", 22.50);
    //Variaveis criadas para fins de controle da alocacao de livros
    bool livro1_disponivel = true;
    bool livro2_disponivel = true;
    bool livro3_disponivel = true;


    int opcao = 0, i=0; //duas variaveis que vao controlar o fluxo, 'opcao' para encerrar a sessao e 'i' para encerrar a locacao dos livros.
    while( opcao != 3 || i > 3){

        cout << "\n\nDigite:\n1. Para Locar Livros\n2. Matricular Cliente\n3. Encerrar Sessao\n";
        cin >> opcao;

        //Alem do controle do menu, esse if atua para controlar apenas 3 locacoes de livros apos as tres locacoes o usuario so pode cadastrar cliente ou encerrar a sessao
        if (opcao == 1 && i < 3){
            cout << "Area de Locacao. Atencao ao preenchimento dos campos.\n";
            cout << "Livros disponiveis:\n" << endl;

            //Para facilitar o preenchimento do isbn vai ser impresso as informacoes do livro na tela usando as variaveis de disponibilidade dos livros
            if(livro1_disponivel != true){
                    livr2->info_livro();
                    livr3->info_livro();
            }else if(livro2_disponivel != true){
                    livr1->info_livro();
                    livr3->info_livro();
            }else if(livro3_disponivel != true){
                    livr1->info_livro();
                    livr2->info_livro();
            }else{
                    livr1->info_livro();
                    livr2->info_livro();
                    livr3->info_livro();
            }

            //Objeto Cliente:
            long long int matCli;
            char nmCli[MAX_NOME], foneCli[NUM], cpfCli[NUM], mailCli[MAX_NOME];

            //Definicoes dos atributos do cliente registrado pelo usuario
            cout << "\nDigite a matricula do cliente:";
            cin >> matCli;
            cin.ignore();

            cout << "Digite o nome do cliente: ";
            cin.getline(nmCli, MAX_NOME);

            cout << "Digite o CPF do cliente(xxx.xxx.xxx-xx): ";
            cin.getline(cpfCli, NUM);

            cout << "Digite o telefone do cliente(xx xxxxxxxx): ";
            cin.getline(foneCli, NUM);

            cout << "Digite o email do cliente(...@gmail.com): ";
            cin.getline(mailCli, MAX_NOME);

            //Criacao do objeto Cliente com os valores dos atributos definidos pelo usuario
            cliente* cli1 = new cliente(matCli, nmCli, cpfCli, foneCli, mailCli);



            //declaracao das variaveis que guardaram os dados dos atributos do objeto locacao
            srand(time(0));
            int idLoc = rand()%900000 + 100000; //idLoc funciona como numeros de nota fiscal, por isso o sistema gera os numeros aleatoriamente
            char dataDev[MAX_CARC];


            cout << "Digite a data da devolucao(xx/xx/xxxx): ";
            cin.getline(dataDev, MAX_CARC);

            //Como os livros ja foram criados aqui faremos o controle dos livros locados. Guardaremos o ISBN do livro desejado em uma variavel do tipo string, para facilitar a comparacao
            string is;
            cout << "\nDigite o ISBN do Livron: ";
            cin >> is;

            // Verifica se o ISBN corresponde a um dos livros e, se sim, atribui o livro à locação
            livro* livro_locado = nullptr; //ponterio usado para verificar o isbn dos livros
            if (is == livr1->get_isbn() && livro1_disponivel) {
                livro_locado = livr1;
            } else if (is == livr2->get_isbn() && livro2_disponivel) {
                livro_locado = livr2;
            } else if (is == livr3->get_isbn() && livro3_disponivel) {
                livro_locado = livr3;
            }

            if (livro_locado != nullptr) {
                // Cria a locação com o livro escolhido
                locacao* loc1 = new locacao(idLoc, dataDev, livro_locado, cli1);
                i++; //variavel de contagem para controle de locacao
                cout << "\nLocação realizada com sucesso.\n";
                //Informacoes da locacao, funciona como uma nota fiscal para o usuario.
                loc1->info_locacao();

                // Define o livro como indisponível para locação
                if (livro_locado == livr1) {
                    livro1_disponivel = false;
                } else if (livro_locado == livr2) {
                    livro2_disponivel = false;
                } else if (livro_locado == livr3) {
                    livro3_disponivel = false;
                }

            }else{
                cout << "\nLivro Indisponivel.\n";
            }

        }
        //Opcao para cadastro de novo Cliente
        else if (opcao == 2){
            cout << "\nArea de Matricula de Cliente. Atencao ao preenchimento dos campos.\n";


            // Obtém o ano atual
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int year = 1900 + ltm->tm_year;
            // Gera os 7 dígitos aleatórios
            int rest = rand() % 10000000 + 1;

            //Objeto Cliente:
            long long int matCli = year * 10000000LL + rest; //a matricula é gerada pelo sistema contemplado 11 numeros em que 4 eh o ano vigente e 7 sao aleatorios
            char nmCli[MAX_NOME], foneCli[NUM], cpfCli[NUM], mailCli[MAX_NOME];

            cin.ignore();
            cout << "Digite o nome do cliente: ";
            cin.getline(nmCli, MAX_NOME);

            cout << "Digite o CPF do cliente(xxx.xxx.xxx-xx): ";
            cin.getline(cpfCli, NUM);

            cout << "Digite o telefone do cliente(xx xxxxxxxx): ";
            cin.getline(foneCli, NUM);

            cout << "Digite o email do cliente(...@gmail.com): ";
            cin.getline(mailCli, MAX_NOME);

            //Criacao do objeto Cliente com os valores dos atributos definidos pelo usuario
            cliente* cli = new cliente(matCli, nmCli, cpfCli, foneCli, mailCli);

            cout << "\nCleinte Registado com sucesso!\n";

            cli->info_cliente();

        }

    } //fim do while

    //Mensagem de encerramento da sessao.
    cout << nm << " sessao encerrada.\n";

    return 0;
}
