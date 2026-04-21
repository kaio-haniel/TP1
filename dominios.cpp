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
bool Data::setAno(int ano){
    if(ano > 2999 || ano < 2000){
        cout << "Ano invalido";
        return false;
    }
    this->ano = ano;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        this->bissexto = true;
    } else {
        this->bissexto = false;
    }
    return true;
}
bool Data::setMes(int mes){
    if(mes > 12 || mes < 1){
        cout << "Mes invalido";
        return false;
    }
    this->mes = mes;
    return true;

}
bool Data::setDia(int dia){
    if(dia > 31 || dia < 1){
        cout << "Dia invalido";
        return false;
    }
    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 30)){
        cout << "Dia invalido";
        return false;
    }
    if(mes == 2 && !bissexto && dia > 28){
        cout << "Dia invalido";
        return false;
    }
    if(mes == 2 && bissexto && dia > 29){
        cout << "Dia invalido";
        return false;
    }
    this->dia = dia;
    return true;
}
bool Data::setData(string data) {
    int dia, mes, ano;

    if (sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano) != 3) {
        cout << "Formato invalido!" << endl;
        return false;
    }
    if (!this->setAno(ano)) {
        return false;
    }
    if (!this->setMes(mes)){
        return false;
    }
    if (!this->setDia(dia)){
        return false;
    }
    this->data = data;
    return true;
}

//Metodos-Estado:
bool Estado::validar(int escolha){
    if(escolha < 1 || escolha > LIMITE) return false;

    return true;
}
bool Estado::setEstado(int escolha){
    if(!validar(escolha)){
        cout << "Escolha invalida" << endl;
        return false;
    }
    this->escolha = escolha;
    switch(escolha){
        case 1: this->estado = "A FAZER"; break;
        case 2: this->estado = "FAZENDO"; break;
        case 3: this->estado = "FEITO"; break;
    }
    return true;
}

//Metodos-Prioridade:
bool Prioridade::validar(int valor){
    if(valor < 1 || valor > LIMITE) return false;

    return true;
}
bool Prioridade::setPrio(int valor){
    if(!validar(valor)){
        cout << "Escolha invalida" << endl;
        return false;
    }
    this->valor = valor;
    switch(valor){
        case 1: this->prio = "ALTA"; break;
        case 2: this->prio = "MEDIA"; break;
        case 3: this->prio = "BAIXA"; break;
    }
    return true;
}

//Metodos-Papel:
bool Papel::validar(int valor){
    if(valor < 1 || valor > LIMITE) return false;

    return true;
}
bool Papel::setEscolha_papel(int valor){
    if(!validar(valor)){
        cout << "Escolha invalida" << endl;
        return false;
    }
    this->valor = valor;
    switch(valor){
        case 1: this->escolha_papel = "DESENVOLVEDOR"; break;
        case 2: this->escolha_papel = "MESTRE SCRUM"; break;
        case 3: this->escolha_papel = "PROPIETARIO DE PRODUTO"; break;
    }
    return true;
}

//Metodos-Nome:
bool Nome::validar(string nome){
    if(nome.size() > LIMITE) return false;
    if((nome[0] == ' ') || (nome[10]== ' ')){
        cout <<"valor invalido";
        return false;
    }
    return true;
}
bool Nome::setNome(string nome){
    if(!validar(nome)) return false;
    this->nome = nome;

    return true;
}
