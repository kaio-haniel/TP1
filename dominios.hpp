#ifndef DOMINIOS_HPP
#define DOMINIOS_HPP
#include <string>

//Domínio-Codigo:
class Codigo{
private:
    static const int LIMITE = 5;
    void validar(std::string);
    std::string Code;
public:
    std::string getCode()const;
    void setCode(std::string);
};
//Metodos-Codigo:
inline std::string Codigo::getCode()const{
    return Code;
}

//Domínio-Senha:
class Senha{
private:
    static const int LIMITE = 6;
    std::string senha;
    void validar(std::string);
public:
    std::string getSenha()const;
    void setSenha(std::string);
};
//Metodos-Senha:
inline std::string Senha::getSenha()const{
    return senha;
}

//Domínio-Tempo:
class Tempo{
private:
    static const int max_t = 365, min_t = 0;
    int duracao;
    void validar(int);
public:
    void setDuracao(int);
    int getDuracao()const;
};
//Metodos-Tempo:
inline int Tempo::getDuracao()const{
    return duracao;
}

//Domínio-Texto:
class Texto{
private:
    static const int LIMITE = 40;
    std::string texto;
    void validar(std::string);
public:
    void setTexto(std::string);
    std::string getTexto()const;
};
//Metodos-Texto:
inline std::string Texto::getTexto()const{
    return texto;
}

//Dominio-Data:
class Data{
private:
    int dia, mes, ano;
    std::string data;
    bool bissexto;
    bool validar(std::string);
public:
    bool operator<(const Data& outro) const{
        if(ano != outro.ano) return ano < outro.ano;
        if(mes != outro.mes) return mes < outro.mes;
        return dia < outro.dia;
    }
    bool setDia(int);
    bool setMes(int);
    bool setAno(int);
    bool setData(std::string);
    std::string getData();
};
//Metodos-Data:
inline std::string Data::getData(){
    return data;
}

//Dominio-Estado:
class Estado{
private:
    int escolha;
    std::string estado;
    bool validar(int);
    static const int LIMITE = 3;
public:
    bool setEstado(int);
    std::string getEstado();
};
//Metodos-Estado:
inline std::string Estado::getEstado(){
    return estado;
}

//Dominio-Prioridade:
class Prioridade{
 private:
    std::string prio;
     static const int LIMITE = 3;
     int valor;
     bool validar(int);
 public:
     bool setPrio(int);

    std::string getPrio();

};
//Metodos-Prioridade:
 inline std::string Prioridade::getPrio(){
    return prio;
}

//Dominio-Papel:
class Papel{
 private:
    std::string escolha_papel;
     static const int LIMITE = 3;
     int valor;
     bool validar(int);
 public:
     bool setEscolha_papel(int);

    std::string getEscolha_papel();

};
//Metodos-Papel:
 inline std::string Papel::getEscolha_papel(){
    return escolha_papel;
}
//Dominio-Nome:
class Nome{
private:
    static const int LIMITE = 10;
    std::string nome;
    bool validar(std::string);
public:
    bool setNome(std::string);
    std::string getNome();
};
//Metodos-Nome:
 inline std::string Nome::getNome(){
    return nome;
}
#endif
