#ifndef CONTROLADORASSERVICO_HPP_INCLUDED
#define CONTROLADORASSERVICO_HPP_INCLUDED

#include "Interfaces.hpp"

// ===================== AUTENTICACAO =====================

///
/// Módulo que implementa a interface de autenticação da camada de serviço.
///
/// Herda de ISAutenticacao e atua como intermediário entre a camada de apresentação e a camada de persistência.
///

class CntrServicoAutenticacao : public ISAutenticacao {
private:
    IBancoDados* cntrBancoDados;
public:

///
/// Define a ligação (link) com a controladora da camada de persistência.
///

    void setCntrBancoDados(IBancoDados*);

///
/// Realiza o serviço de autenticação do usuário delegando ao banco de dados.
///
/// - Retorna true caso as informações existam e sejam iguais aos dados no banco de dados.
/// - Retorna false caso as informações não existam ou sejam diferentes dos dados no banco de dados.
///

    bool autenticar(const Email&, const Senha&) override;
};

inline void CntrServicoAutenticacao::setCntrBancoDados(IBancoDados* cntr){
    cntrBancoDados = cntr;
}

inline bool CntrServicoAutenticacao::autenticar(const Email& email, const Senha& senha){
    return (cntrBancoDados->DadosAutenticacao(email, senha) == 1);
}

// ===================== SERVIÇO DE GESTAO =====================

///
/// Módulo que implementa a interface de gestão da camada de serviço.
///
/// Herda de ISGestao e encapsula as regras de negócio para manipulação de Contas, Projetos, Sprints e Histórias.
///

class CntrServicoGestao : public ISGestao {
private:
    IBancoDados* cntrBancoDados;
public:

///
/// Define a ligação (link) com a controladora da camada de persistência.
///

    void setCntrBancoDados(IBancoDados*);

///
/// Solicita a leitura dos dados da conta do usuário à camada de persistência.
///

    bool lerConta(Pessoa& p)             override { return cntrBancoDados->lerConta(p);}

///
/// Solicita a atualização dos dados da conta do usuário à camada de persistência.
///

    bool atualizarConta(const Pessoa& p) override { return cntrBancoDados->atualizarConta(p); }

///
/// Solicita a exclusão da conta do usuário à camada de persistência.
///

    bool excluirConta(const Email& e)    override { return cntrBancoDados->excluirConta(e); }

///
/// Solicita a criação de um projeto associado ao email de um mestre scrum à camada de persistência.
///

    bool criarProjeto(const Projeto& p, const Email& e)    override { return cntrBancoDados->criarProjeto(p, e); }

///
/// Solicita a leitura das informações de um projeto à camada de persistência.
///

    bool lerProjeto(Projeto& p)                            override { return cntrBancoDados->lerProjeto(p); }

///
/// Solicita a atualização dos dados de um projeto à camada de persistência.
///

    bool atualizarProjeto(const Projeto& p)                override { return cntrBancoDados->atualizarProjeto(p); }

///
/// Solicita a exclusão de um projeto por meio de seu código (Primary Key).
///

    bool excluirProjeto(const Codigo& c)                   override { return cntrBancoDados->excluirProjeto(c); }

///
/// Solicita à camada de persistência a listagem de projetos associados a uma pessoa.
///

    bool listarProjetos(const Email& e)                    override { return cntrBancoDados->listarProjetos(e); }

///
/// Solicita a criação de um plano de sprint associado ao codigo (Primary Key) de um projeto à camada de persistência.
///

    bool criarSprint(const Plano_de_Sprint& s, const Codigo& c)    override { return cntrBancoDados->criarSprint(s, c); }

///
/// Solicita a leitura das informações de um plano de sprint à camada de persistência.
///

    bool lerSprint(Plano_de_Sprint& s)                             override { return cntrBancoDados->lerSprint(s); }

///
/// Solicita a atualização dos dados de um plano de sprint à camada de persistência.
///

    bool atualizarSprint(const Plano_de_Sprint& s)                 override { return cntrBancoDados->atualizarSprint(s); }

///
/// Solicita a exclusão de um plano de sprint por meio de seu código (Primary Key).
///

    bool excluirSprint(const Codigo& c)                            override { return cntrBancoDados->excluirSprint(c); }

///
/// Solicita à camada de persistência a listagem de planos de sprint associados a um projeto.
///

    bool listarSprint(const Codigo& c)                             override { return cntrBancoDados->listarSprint(c); }

///
/// Solicita a criação de uma história de usuário associada ao codigo (Primary Key) de um projeto à camada de persistência.
///

    bool criarHistoria(const Historia_de_usuario& h, const Codigo& c)    override { return cntrBancoDados->criarHistoria(h, c); }

///
/// Solicita a leitura das informações de uma história de usuário à camada de persistência.
///

    bool lerHistoria(Historia_de_usuario& h)                             override { return cntrBancoDados->lerHistoria(h); }

///
/// Solicita a atualização dos dados de uma história de usuário à camada de persistência.
///

    bool atualizarHistoria(const Historia_de_usuario& h)                 override { return cntrBancoDados->atualizarHistoria(h); }

///
/// Solicita a exclusão de uma história de usuário por meio de seu código (Primary Key).
///

    bool excluirHistoria(const Codigo& c)                                override { return cntrBancoDados->excluirHistoria(c); }

///
/// Estabelece ou remove associação entre uma história de usuário e uma pessoa.
///

    bool relacaoHis_Pes(const Email& e, const Codigo& c, int num)        override { return cntrBancoDados->relacaoHis_Pes(e, c, num); }

///
/// Solicita a listagem de histórias de usuário associadas a projeto ou plano de sprint.
///
/// Se o parametro <u>num</u> for igual a 1, é solicitado à camada de persistência a listagem das historias de usuario associadas a um projeto,
/// se for igual a 2, é solicitado à camada de persistência a listagem das historias de usuario associadas a um plano de sprint.
///

    bool listarHist(const Codigo& c, int num) override {
        switch(num){
            case 1: return cntrBancoDados->listarHistP(c);
            case 2: return cntrBancoDados->listarHistS(c);
        }
        return false;
    }

///
/// Solicita à camada de persistência a listagem de histórias de usuário associadas a uma pessoa.
///

    bool listarHist(const Email& e)                                      override { return cntrBancoDados->listarHistE(e); }

///
/// Solicita à camada de persistência que mova a historia de usuario de projeto para plano de sprint.
///

    bool moverHisProj_Sprint(const Codigo& s, const Codigo& h)           override { return cntrBancoDados->moverHisProj_Sprint(s, h); }

///
/// Solicita à camada de persistência a alteração do estado de uma história de usuário.
///

    bool atualizarEstado(const Estado& e, const Codigo& c)               override { return cntrBancoDados->atualizarEstado(e, c); }
};

inline void CntrServicoGestao::setCntrBancoDados(IBancoDados* cntr){
    cntrBancoDados = cntr;
}

// ===================== CADASTRO =====================

///
/// Módulo que implementa a interface de cadastro da camada de serviço.
///
/// Herda de ISCadastro e atua validando e solicitando a persistência de novos perfis de usuários.
///

class CntrServicoCadastro : public ISCadastro {
private:
    IBancoDados* cntrBancoDados;
public:

///
/// Define a ligação (link) com a controladora da camada de persistência.
///

    void setCntrBancoDados(IBancoDados* cntr){ cntrBancoDados = cntr; }

///
/// Solicita o cadastramento do novo usuário no banco de dados.
///
/// - Retorna true caso os dados não existissem e tenham sido salvos de forma correta.
/// - Retorna false caso o identificador de e-mail já esteja registrado no sistema.
///

    bool cadastrar(const Nome& n, const Email& e, const Senha& s, const Papel& p) override {
        return cntrBancoDados->DadosCadastro(n, e, s, p);
    }
};

#endif // CONTROLADORASSERVICO_HPP_INCLUDED
