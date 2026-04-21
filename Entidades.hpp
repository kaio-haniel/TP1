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
    void setCodigo(Codigo);
    void setObjetivo(Texto);
    void setCapacidade(Tempo);
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
inline void Plano_de_Sprint::setCodigo(Codigo codigo){
    this->codigo = codigo;
}
inline void Plano_de_Sprint::setObjetivo(Texto texto){
    this->objetivo = texto;
}
inline void Plano_de_Sprint::setCapacidade(Tempo tempo){
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
    void setCodigo(Codigo);
    void setTitulo(Texto);
    void setPapel(Texto);
    void setAcao(Texto);
    void setValor(Texto);
    void setEstimativa(Tempo);
    void setPrioridade(Prioridade);
    void setEstado(Estado);
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
inline void Historia_de_usuario::setCodigo(Codigo codigo){
    this->codigo = codigo;
}
inline void Historia_de_usuario::setTitulo(Texto titulo){
    this->titulo = titulo;
}
inline void Historia_de_usuario::setPapel(Texto papel){
    this->papel = papel;
}
inline void Historia_de_usuario::setAcao(Texto acao){
    this->acao = acao;
}
inline void Historia_de_usuario::setValor(Texto valor){
    this->valor = valor;
}
inline void Historia_de_usuario::setEstimativa(Tempo tempo){
    this->estimativa = tempo;
}
inline void Historia_de_usuario::setPrioridade(Prioridade prio){
    this->prioridade = prio;
}
inline void Historia_de_usuario::setEstado(Estado estado){
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
    void setCodigo(Codigo);
    void setNome(Nome);
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
void Projeto::setData(Data inicio, Data termino){
    validarData(inicio, termino);
    this->inicio = inicio;
    this->termino = termino;
}
inline void Projeto::setCodigo(Codigo codigo){
    this->codigo = codigo;
}
inline void Projeto::setNome(Nome nome){
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
public:
    void setNome(Nome);
    void setSenha(Senha);
    void setPapel(Papel);
    Nome getNome() const;
    Senha getSenha() const;
    Papel getPapel() const;
};
//Metodos Pessoa:
inline void Pessoa::setNome(Nome nome){
    this->nome = nome;
}
inline void Pessoa::setSenha(Senha senha){
    this->senha = senha;
}
inline void Pessoa::setPapel(Papel papel){
    this->papel = papel;
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
