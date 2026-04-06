#include "dominios.hpp"
#include <iostream>
#include <cctype>

using namespace std;

//Metodos-Codigo:
bool Codigo::validar(string code){
    if(code.size()!=LIMITE) return false;
    if(!isupper(code[0]) || !isupper(code[1])) return false;
    if(!isdigit(code[2]) || !isdigit(code[3]) || !isdigit(code[4])) return false;
    return true;
}
bool Codigo::setCode(string code){
    if(!validar(code)) return false;
    this->Code = code;
    return true;
}

//Metodos-Senha:
bool Senha::validar(string senha){

    if(senha.size()!=LIMITE) return false;

    int count_AZ=0, count_az=0, count_dig=0;

    for(int i=0; i<LIMITE; i++){

        if(!isalnum(senha[i])) return false;

        if(i<senha.size()-1){
            if((isalpha(senha[i])&&isalpha(senha[i+1]))||
               (isdigit(senha[i])&&isdigit(senha[i+1]))){
                return false;
            }
        }
        if(isupper(senha[i])) count_AZ++;
        else if(islower(senha[i])) count_az++;
        else if(isdigit(senha[i])) count_dig++;
    }
    if(count_AZ == 0 || count_az == 0 || count_dig == 0) return false;

    return true;
}
bool Senha::setSenha(string senha){
    if(!validar(senha)) return false;
    this->senha = senha;
    return true;
}

//Metodos-Tempo:
bool Tempo::validar(int n){
    if(n > min_t && n <= max_t) return true;
    return false;
}
bool Tempo::setDuracao(int tempo){
    if(!validar(tempo)) return false;
    this->duracao = tempo;
    return true;
}

//Metodos-Texto:
bool Texto::validar(string texto){

    int tam = texto.size();

    if(tam>LIMITE) return false;

    if(!isalnum(texto[0]) || !isalnum(texto[tam-1])) return false;

    for(int i = 0; i < tam; i++){

        if(!isalnum(texto[i]) && texto[i] != ',' && texto[i] != '.' && texto[i] != ' ')
            return false;

        if(i<(tam-1)){
            if(((texto[i] == ',' || texto[i] == '.') && (texto[i+1] == ',' || texto[i+1] == '.'))||
               (texto[i] == ' ' && !isalnum(texto[i+1])))
                return false;
        }
    }
    return true;
}
bool Texto::setTexto(string texto){
    if(!validar(texto)) return false;
    this->texto = texto;
    return true;
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
    if(escolha < 1 || escolha > LIMITE){
        return false;
    }
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

bool prioridade::validar(int valor){
    if(valor < 1  valor > LIMITE){
        return false;
    }
    return true;
}
bool prioridade::setPrio(int valor){
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
    if(valor < 1  valor > LIMITE){
        return false;
    }
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
        case 3: this->escolhapapel = "PROPIETARIO DE PRODUTO"; break;
    }
    return true;
}

//Metodos-Nome
bool Nome::validar(string nome){
    if(nome.size() > LIMITE) {return false;}
    if((nome[0] == ' ') || (nome[10]== ' ')) cout <<"valor invalido";

    return true;
}
bool Nome::setNome(string nome){
    if(!validar(nome)) {return false;
    }
    this->nome = nome;
    return true;
}
