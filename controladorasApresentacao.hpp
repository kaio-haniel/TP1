#ifndef CONTROLADORASAPRESENTACAO_HPP_INCLUDED
#define CONTROLADORASAPRESENTACAO_HPP_INCLUDED

#include "Interfaces.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// ===================== AUTENTICACAO =====================

///
/// Módulo que implementa a interface de autenticação da camada de apresentação.
///
/// Herda de IAAutenticacao e interage com a camada de serviço para validar o acesso do usuário.
///

class CntrApresentacaoAutenticacao : public IAAutenticacao {
private:
    ISAutenticacao* cntrServicoAutenticacao;
public:

///
/// Define a ligação (link) com a controladora da camada de serviço de autenticação.
///

    void setCntrServicoAutenticacao(ISAutenticacao*);

///
/// Solicita o serviço de autenticação interagindo com a interface textual do usuário.
///
/// - Retorna true caso a autenticação na camada de serviço tenha sido realizada com sucesso.
/// - Retorna false caso a autenticação na camada de serviço falhe ou os dados sejam inválidos.
///

    bool autenticar(Email*) override;
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(ISAutenticacao* cntr){
    cntrServicoAutenticacao = cntr;
}

// ===================== SERVIÇO DE GESTAO =====================

///
/// Módulo que implementa a interface de gestão da camada de apresentação.
///
/// Herda de IAGestao e provê os menus para que o usuário gerencie Contas, Projetos, Sprints e Histórias.
///

class CntrAGestao : public IAGestao {
private:
    ISGestao* cntrServicoGestao;
    bool lerDadosPessoa(Pessoa&);
    bool lerEmail(Email&);
    void exibirPessoa(const Pessoa&);
    bool lerDadosProjeto(Projeto&);
    bool lerCodigoProjeto(Codigo&);
    void exibirProjeto(const Projeto&);
    bool lerDadosSprint(Plano_de_Sprint&);
    bool lerCodigoSprint(Codigo&);
    void exibirSprint(const Plano_de_Sprint&);
    bool lerDadosHistoria(Historia_de_usuario&);
    bool lerCodigoHistoria(Codigo&);
    void exibirHistoria(const Historia_de_usuario&);
    bool lerEstado(Estado&);
    void menuConta(const Email&);
    void menuProjetos(const Email&);
    void menuSprints(const Email&);
    void menuHistorias(const Email&);

public:

///
/// Define a ligação (link) com a controladora da camada de serviço de gestão.
///

    void setCntrServicoGestao(ISGestao*);

///
/// Apresenta o menu principal de gestão ao usuário autenticado e processa suas escolhas de navegação.
///

    void executar(const Email&) override;
};

inline void CntrAGestao::setCntrServicoGestao(ISGestao* cntr){
    cntrServicoGestao = cntr;
}
// ===================== CADASTRO =====================

///
/// Módulo que implementa a interface de cadastro da camada de apresentação.
///
/// Herda de IACadastro e gerencia o fluxo de entrada de dados para criação de novas contas de usuários.
///

class CntrApresentacaoCadastro : public IACadastro {
private:
    ISCadastro* cntrServicoCadastro;
public:

///
/// Define a ligação (link) com a controladora da camada de serviço de cadastro.
///

    void setCntrServicoCadastro(ISCadastro* cntr){ cntrServicoCadastro = cntr; }

///
/// Solicita os dados de novos usuários no terminal, valida e requisita o registro à camada de serviço.
///
/// - Retorna true caso o cadastramento na camada de serviço tenha sido realizado com sucesso.
/// - Retorna false caso o cadastramento na camada de serviço não tenha sido realizado com sucesso.
///

    bool cadastrar(Nome*, Email*, Senha*, Papel*) override;
};

#endif // CONTROLADORASAPRESENTACAO_HPP_INCLUDED
