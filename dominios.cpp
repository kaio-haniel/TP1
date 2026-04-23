#include "dominios.hpp"
#include <iostream>
#include <cctype>

using namespace std;

//Metodos-Codigo:
void Codigo::validar(string code){
    if(code.size()!=LIMITE)
        throw invalid_argument(to_string(code.size()) + " eh um tamanho invalido!"
                               + " Eh esperado " + to_string(LIMITE) + " caracteres.");
    if(!isupper(code[0]) || !isupper(code[1]))
        throw invalid_argument("Argumento invalido. Os dois primeiros caracteres devem ter o formato 'XX' (letras maiusculas).");
    if(!isdigit(code[2]) || !isdigit(code[3]) || !isdigit(code[4]))
        throw invalid_argument("Argumento invalido. Eh esperado 3 digitos numericos finais.");
}
void Codigo::setCode(string code){
    validar(code);
    this->Code = code;
}

//Metodos-Senha:
void Senha::validar(string senha){

    if(senha.size()!=LIMITE)
        throw invalid_argument("Senha invalida: " + to_string(senha.size()) + " eh um tamanho invalido!"
                               + " Eh esperado " + to_string(LIMITE) + " caracteres.");;

    int count_AZ=0, count_az=0, count_dig=0;

    for(int i=0; i<LIMITE; i++){

        if(!isalnum(senha[i])) throw invalid_argument("Caracter pode apenas ser letra (A-Z ou a-z) ou digito (0-9).");

        if(i<senha.size()-1){
            if((isalpha(senha[i])&&isalpha(senha[i+1]))||
               (isdigit(senha[i])&&isdigit(senha[i+1]))){
                throw invalid_argument("Letra nao pode ser seguida por letra, digito nao pode ser seguido por digito.");
            }
        }
        if(isupper(senha[i])) count_AZ++;
        else if(islower(senha[i])) count_az++;
        else if(isdigit(senha[i])) count_dig++;
    }
    if(count_AZ == 0 || count_az == 0 || count_dig == 0)
        throw invalid_argument("Devem existir pelo menos uma letra minuscula (a-z), uma letra maiuscula (A-Z) e um digito (0-9).");
}
void Senha::setSenha(string senha){
    validar(senha);
    this->senha = senha;
}

//Metodos-Tempo:
void Tempo::validar(int n){
    if(!(n > min_t && n <= max_t)) throw invalid_argument("Argumento invalido. Insira um digito entre 1 e 365.");
}
void Tempo::setDuracao(int tempo){
    validar(tempo);
    this->duracao = tempo;
}

//Metodos-Texto:
void Texto::validar(string texto){

    int tam = texto.size();

    if(tam>LIMITE) throw invalid_argument("Argumento invalido. O tamanho do texto pode ser de no maximo " + to_string(LIMITE) + " caracteres.");

    if(!isalnum(texto[0]) || !isalnum(texto[tam-1]))
        throw invalid_argument("O primeiro e o ultimo caracteres so podem ser letras (a-z ou A-Z) ou digitos (0-9).");

    for(int i = 0; i < tam; i++){

        if(!isalnum(texto[i]) && texto[i] != ',' && texto[i] != '.' && texto[i] != ' ')
            throw invalid_argument("Argumento invalido. Caracter deve ser letra (a-z ou A-Z), digito (0-9), virgula, ponto ou espaco em branco.");

        if(i<(tam-1)){
            if((texto[i] == ',' || texto[i] == '.') && (texto[i+1] == ',' || texto[i+1] == '.'))
                throw invalid_argument("Argumento Invalido. Ponto ou virgula nao pode ser seguido por virgula ou ponto.");
            else if(texto[i] == ' ' && !isalnum(texto[i+1]))
                throw invalid_argument("Argumento Invalido. Espaco em branco deve ser seguido por letra ou digito.");
        }
    }
}
void Texto::setTexto(string texto){
    validar(texto);
    this->texto = texto;
}

//Metodos-Data
void Data::setAno(int ano){
    if(ano > 2999 || ano < 2000){
        throw invalid_argument("Ano invalido");
    }
    this->ano = ano;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        this->bissexto = true;
    } else {
        this->bissexto = false;
    }
}
void Data::setMes(int mes){
    if(mes > 12 || mes < 1){
        throw invalid_argument("Mes invalido");
    }
    this->mes = mes;
}
void Data::setDia(int dia){
    if(dia > 31 || dia < 1){
        throw invalid_argument("Dia invalido");
    }
    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 30)){
        throw invalid_argument("Dia invalido");
    }
    if(mes == 2 && !bissexto && dia > 28){
        throw invalid_argument("Dia invalido");
    }
    if(mes == 2 && bissexto && dia > 29){
        throw invalid_argument("Dia invalido");
    }
    this->dia = dia;
}
void Data::setData(string data) {
    int dia, mes, ano;
    if (sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano) != 3) {
        throw invalid_argument("Formato invalido!");
    }
    this->setAno(ano);
    this->setMes(mes);
    this->setDia(dia);

    this->data = data;
}

//Metodos-Estado:
void Estado::validar(int escolha){
    if(escolha < 1 || escolha > LIMITE)
        throw invalid_argument("Escolha invalida");
}
void Estado::setEstado(int escolha){
    validar(escolha);
    this->escolha = escolha;
    switch(escolha){
        case 1: this->estado = "A FAZER"; break;
        case 2: this->estado = "FAZENDO"; break;
        case 3: this->estado = "FEITO"; break;
    }
}

//Metodos-Prioridade:
void Prioridade::validar(int valor){
    if(valor < 1 || valor > LIMITE)
        throw invalid_argument("Escolha invalida");
}

void Prioridade::setPrio(int valor){
    validar(valor);
    this->valor = valor;
    switch(valor){
        case 1: this->prio = "ALTA"; break;
        case 2: this->prio = "MEDIA"; break;
        case 3: this->prio = "BAIXA"; break;
    }
}

//Metodos-Papel:
void Papel::validar(int valor){
    if(valor < 1 || valor > LIMITE)
        throw invalid_argument("Escolha invalida");
}

void Papel::setEscolha_papel(int valor){
    validar(valor);
    this->valor = valor;
    switch(valor){
        case 1: this->escolha_papel = "DESENVOLVEDOR"; break;
        case 2: this->escolha_papel = "MESTRE SCRUM"; break;
        case 3: this->escolha_papel = "PROPIETARIO DE PRODUTO"; break;
    }
}

//Metodos-Nome:
void Nome::validar(string nome){
    if(nome.size() > LIMITE)
        throw invalid_argument("Tamanho invalido");

    if((nome[0] == ' ') || (nome[10] == ' ')){ // Mantida a lógica original do índice 10
        throw invalid_argument("Valor invalido");
    }
}

void Nome::setNome(string nome){
    validar(nome);
    this->nome = nome;
}
//Metodos-Email:
void Email::validar(string e){
size_t arroba = e.find('@');
if (arroba == string::npos || e.find('@', arroba + 1) != string::npos)
    throw invalid_argument("Email invalido: deve conter um unico '@'.");

string local = e.substr(0, arroba);
string dominio = e.substr(arroba + 1);

// ---- PARTE LOCAL ----
if (local.empty() || local.size() > LIMITE_LOCAL)
    throw invalid_argument("Parte local invalida.");

if (local.front() == '.' || local.front() == '-' || local.back() == '.' || local.back() == '-')
    throw invalid_argument("Parte local nao pode iniciar ou terminar com '.' ou '-'.");

for (size_t i = 0; i < local.size(); i++) {
    char c = local[i];

if (!(islower(c) || isdigit(c) || c == '.' || c == '-'))
    throw invalid_argument("Caractere invalido na parte local.");

if (i > 0) {
    if ((c == '.' || c == '-') && (local[i-1] == '.' || local[i-1] == '-'))
            throw invalid_argument("Nao pode haver '.' ou '-' consecutivos.");
    }
}

// ---- PARTE DOMINIO ----
if (dominio.empty() || dominio.size() > LIMITE_DOMINIO)
    throw invalid_argument("Dominio invalido.");

size_t inicio = 0;

while (inicio < dominio.size()) {
    size_t fim = dominio.find('.', inicio);
    if (fim == string::npos) fim = dominio.size();

    string parte = dominio.substr(inicio, fim - inicio);

    if (parte.empty())
        throw invalid_argument("Parte do dominio vazia.");

    if (parte.front() == '-' || parte.back() == '-')
        throw invalid_argument("Parte do dominio nao pode iniciar ou terminar com '-'.");

    for (char c : parte) {
        if (!(islower(c) || isdigit(c) || c == '-'))
            throw invalid_argument("Caractere invalido no dominio.");
    }

    inicio = fim + 1;
}
}

void Email::setEmail(string e) {
validar(e);
this->email = e;
}
