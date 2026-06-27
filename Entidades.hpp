#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include <iostream>
#include "dominios.hpp"

using namespace std;

///
/// Entidade que representa um Plano de Sprint.
///
/// Um Plano de Sprint agrega as informa&ccedil;&otilde;es necess&aacute;rias para o planejamento
/// do desenvolvimento de um projeto, contendo um c&oacute;digo identificador, um objetivo
/// e a capacidade de tempo estimada.
///

//Entidade Plano_de_Sprint:
class Plano_de_Sprint{
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;
public:

///
/// Retorna c&oacute;digo do plano de sprint.
///
/// @return Objeto C&oacute;digo.
///

    Codigo getCodigo()const;

///
/// Retorna objetivo do plano de sprint.
///
/// @return Objeto Texto.
///

    Texto getObjetivo()const;

///
/// Retorna capacidade de tempo do plano de sprint.
///
/// @return Objeto Tempo.
///

    Tempo getCapacidade()const;

///
/// Armazena uma instância de C&oacute;digo.
///
/// @param codigo Objeto C&oacute;digo.
///

    void setCodigo(const Codigo&);

///
/// Armazena uma instância de Texto.
///
/// @param texto Objeto Texto
///

    void setObjetivo(const Texto&);

///
/// Armazena uma instância de Tempo.
///
/// @param tempo Objeto Tempo
///

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


///
/// Entidade que representa uma Hist&oacute;ria de Usu&aacute;rio.
///
/// Uma Hist&oacute;ria de Usu&aacute;rio &eacute; uma descri&ccedil;&atilde;o de uma funcionalidade do sistema sob a
/// perspectiva do usu&aacute;rio, contendo um c&oacute;digo identificador, um titulo, papel (como...), a&ccedil;&atilde;o (eu quero...),
/// valor (para...), estimativa, prioridade e estado.
///

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

///
/// Retorna c&oacute;digo da Historia de usuario.
///
/// @return Objeto C&oacute;digo.
///

    Codigo getCodigo()const;

///
/// Retorna titulo da Historia de usuario.
///
/// @return Objeto Texto.
///

    Texto getTitulo()const;

///
/// Retorna papel da Historia de usuario.
///
/// @return Objeto Texto.
///

    Texto getPapel()const;

///
/// Retorna ação da Historia de usuario.
///
/// @return Objeto Texto.
///

    Texto getAcao()const;

///
/// Retorna valor da Historia de usuario.
///
/// @return Objeto Texto.
///

    Texto getValor()const;

///
/// Retorna estimativa da Historia de usuario.
///
/// @return Objeto Tempo.
///

    Tempo getEstimativa()const;

///
/// Retorna prioridade da Historia de usuario.
///
/// @return Objeto Prioridade.
///

    Prioridade getPrioridade()const;

///
/// Retorna estado da Historia de usuario.
///
/// @return Objeto Estado.
///

    Estado getEstado()const;

///
/// Armazena uma instância de Codigo.
///
/// @param codigo Objeto Codigo
///

    void setCodigo(const Codigo&);

///
/// Armazena uma instância de Texto.
///
/// @param titulo Objeto Texto
///

    void setTitulo(const Texto&);

///
/// Armazena uma instância de Texto.
///
/// @param papel Objeto Texto
///

    void setPapel(const Texto&);

///
/// Armazena uma instância de Texto.
///
/// @param acao Objeto Texto
///

    void setAcao(const Texto&);

///
/// Armazena uma instância de Texto.
///
/// @param valor Objeto Texto
///

    void setValor(const Texto&);

///
/// Armazena uma instância de Tempo.
///
/// @param tempo Objeto Tempo
///

    void setEstimativa(const Tempo&);

///
/// Armazena uma instância de Prioridade.
///
/// @param prio Objeto Prioridade
///

    void setPrioridade(const Prioridade&);

///
/// Armazena uma instância de Estado.
///
/// @param estado Objeto Estado
///

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


///
/// Entidade que representa um Projeto.
///
/// Um Projeto agrega as informa&ccedil;&otilde;es essenciais para a identifica&ccedil;&atilde;o
/// e o gerenciamento de um ciclo de trabalho, contendo um c&oacute;digo identificador,
/// um nome e tempo de duração pr&eacute; definido por datas de in&iacute;cio e t&eacute;rmino.
///

//Entidade Projeto:
class Projeto{
private:
    Codigo codigo;
    Nome nome;
    Data inicio, termino;
    void validarData(const Data&, const Data&);
public:

///
/// Armazena uma instância de Codigo.
///
/// @param codigo Objeto Codigo
///

    void setCodigo(const Codigo&);

///
/// Armazena uma instância de Nome.
///
/// @param nome Objeto Nome
///

    void setNome(const Nome&);

///
/// Armazena duas instâncias de Data.
///
/// @param inicio Objeto Data
/// @param termino Objeto Data
///

    void setData(const Data&, const Data&);

///
/// Retorna código identificador do Projeto.
///
/// @return Objeto Codigo.
///

    Codigo getCodigo() const;

///
/// Retorna nome do Projeto.
///
/// @return Objeto Nome.
///

    Nome getNome() const;

///
/// Retorna data de início do Projeto.
///
/// @return Objeto Data.
///

    Data getInicio() const;

///
/// Retorna data de término do Projeto.
///
/// @return Objeto Data.
///

    Data getTermino() const;
};
//Metodos Projeto:
inline void Projeto::validarData(const Data& inicio, const Data& termino){
    if(termino<inicio)
        throw invalid_argument("Data invalida: o termino nao pode ser antes do inicio.");
}
inline void Projeto::setData(const Data& inicio, const Data& termino){
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


///
/// Entidade que representa uma Pessoa.
///
/// Uma pessoa dentro do sistema representa um usuário, contendo nome, senha e papel (role),
/// o seu papel irá definir qual será sua função dentro do projeto e quais são suas permissões.
///

//Entidade Pessoa:
class Pessoa{
private:
    Nome nome;
    Senha senha;
    Papel papel;
    Email email;
public:

///
/// Armazena uma instância de Nome.
///
/// @param nome Objeto Nome
///

    void setNome(const Nome&);

///
/// Armazena uma instância de Senha.
///
/// @param senha Objeto Senha
///

    void setSenha(const Senha&);

///
/// Armazena uma instância de Papel.
///
/// @param papel Objeto Papel
///

    void setPapel(const Papel&);

///
/// Armazena uma instância de Email.
///
/// @param email Objeto Email
///

    void setEmail(const Email&);

///
/// Retorna nome da Pessoa.
///
/// @return Objeto Nome.
///

    Nome getNome() const;

///
/// Retorna senha da Pessoa.
///
/// @return Objeto Senha.
///

    Senha getSenha() const;

///
/// Retorna papel da Pessoa.
///
/// @return Objeto Papel.
///

    Papel getPapel() const;

///
/// Retorna email da Pessoa.
///
/// @return Objeto Email.
///

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

#endif // ENTIDADES_HPP_INCLUDED
