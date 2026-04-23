#include <iostream>
#include "dominios.hpp"

using namespace std;

//Entidade Plano_de_Sprint:
class Plano_de_Sprint{
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;
public:
    Codigo getCodigo()const;
    Texto getObjetivo()const;
    Tempo getCapacidade()const;
    void setCodigo(const Codigo&);
    void setObjetivo(const Texto&);
    void setCapacidade(const Tempo&);
};
//Metodos Plano_de_Sprint:
inline Codigo Plano_de_Sprint::getCodigo()const{
    return codigo;
}
inline Texto Plano_de_Sprint::getObjetivo()const{
    return objetivo;
}
inline Tempo Plano_de_Sprint::getCapacidade()const{
    return capacidade;
}
inline void Plano_de_Sprint::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}
inline void Plano_de_Sprint::setObjetivo(const Texto& texto){
    this->objetivo = texto;
}
inline void Plano_de_Sprint::setCapacidade(const Tempo& tempo){
    this->capacidade = tempo;
}

//Entidade Historia_de_usuario:
class Historia_de_usuario{
private:
    Codigo codigo;
    Texto titulo;
    Texto papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;
public:
    Codigo getCodigo()const;
    Texto getTitulo()const;
    Texto getPapel()const;
    Texto getAcao()const;
    Texto getValor()const;
    Tempo getEstimativa()const;
    Prioridade getPrioridade()const;
    Estado getEstado()const;
    void setCodigo(const Codigo&);
    void setTitulo(const Texto&);
    void setPapel(const Texto&);
    void setAcao(const Texto&);
    void setValor(const Texto&);
    void setEstimativa(const Tempo&);
    void setPrioridade(const Prioridade&);
    void setEstado(const Estado&);
};
//Metodos Historia_de_usuario:
inline Codigo Historia_de_usuario::getCodigo()const{
    return codigo;
}
inline Texto Historia_de_usuario::getTitulo()const{
    return titulo;
}
inline Texto Historia_de_usuario::getPapel()const{
    return papel;
}
inline Texto Historia_de_usuario::getAcao()const{
    return acao;
}
inline Texto Historia_de_usuario::getValor()const{
    return valor;
}
inline Tempo Historia_de_usuario::getEstimativa()const{
    return estimativa;
}
inline Prioridade Historia_de_usuario::getPrioridade()const{
    return prioridade;
}
inline Estado Historia_de_usuario::getEstado()const{
    return estado;
}
inline void Historia_de_usuario::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}
inline void Historia_de_usuario::setTitulo(const Texto& titulo){
    this->titulo = titulo;
}
inline void Historia_de_usuario::setPapel(const Texto& papel){
    this->papel = papel;
}
inline void Historia_de_usuario::setAcao(const Texto& acao){
    this->acao = acao;
}
inline void Historia_de_usuario::setValor(const Texto& valor){
    this->valor = valor;
}
inline void Historia_de_usuario::setEstimativa(const Tempo& tempo){
    this->estimativa = tempo;
}
inline void Historia_de_usuario::setPrioridade(const Prioridade& prio){
    this->prioridade = prio;
}
inline void Historia_de_usuario::setEstado(const Estado& estado){
    this->estado = estado;
}

//Entidade Projeto:
class Projeto{
private:
    Codigo codigo;
    Nome nome;
    Data inicio, termino;
    void validarData(const Data&, const Data&);
public:
    void setCodigo(const Codigo&);
    void setNome(const Nome&);
    void setData(Data, Data);
    Codigo getCodigo() const;
    Nome getNome() const;
    Data getInicio() const;
    Data getTermino() const;
};
//Metodos Projeto:
void Projeto::validarData(const Data& inicio, const Data& termino){
    if(termino<inicio)
        throw invalid_argument("Data invalida: o termino nao pode ser antes do inicio.");
}
void Projeto::setData(const Data& inicio, const Data& termino){
    validarData(inicio, termino);
    this->inicio = inicio;
    this->termino = termino;
}
inline void Projeto::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}
inline void Projeto::setNome(const Nome& nome){
    this->nome = nome;
}
inline Codigo Projeto::getCodigo() const{
    return codigo;
}
inline Nome Projeto::getNome() const{
    return nome;
}
inline Data Projeto::getInicio() const{
    return inicio;
}
inline Data Projeto::getTermino() const{
    return termino;
}

//Entidade Pessoa:
class Pessoa{
private:
    Nome nome;
    Senha senha;
    Papel papel;
    Email email;
public:
    void setNome(const Nome&);
    void setSenha(const Senha&);
    void setPapel(const Papel&);
    void setEmail(const Email&);
    Nome getNome() const;
    Senha getSenha() const;
    Papel getPapel() const;
    Email getEmail() const;
};
//Metodos Pessoa:
inline void Pessoa::setNome(const Nome& nome){
    this->nome = nome;
}
inline void Pessoa::setSenha(const Senha& senha){
    this->senha = senha;
}
inline void Pessoa::setPapel(const Papel& papel){
    this->papel = papel;
}
inline void Pessoa::setEmail(const Email& email){
    this->email = email;
}
inline Nome Pessoa::getNome() const{
    return nome;
}
inline Senha Pessoa::getSenha() const{
    return senha;
}
inline Papel Pessoa::getPapel() const{
    return papel;
}
inline Email Pessoa::getEmail() const{
    return email;
}
