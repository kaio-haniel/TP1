#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED


#include "Entidades.hpp"
#include <stdexcept>


///
/// Interface de autenticação da camada de apresentação.
///
/// Recebe os dados inseridos pelo usuário e solicita à camada de serviço que os valide.
///

class IAAutenticacao{
public:

///
/// Solicita o serviço de autenticação ao usuário.
///
///
///
/// - Retorna true caso a solicitação à camada de serviço tenha sido realizada com sucesso.
/// - Retorna false caso a solicitação à camada de serviço não tenha sido realizada com sucesso.
///

    virtual bool autenticar(Email*) = 0;

///
/// Método destrutor virtual da interface.
///

    virtual ~IAAutenticacao(){}
};


///
/// Interface de cadastro da camada de apresentação.
///
/// Recebe os dados inseridos pelo usuário e solicita à camada de serviço que o registre.
///

class IACadastro{
public:

///
/// Solicita o serviço de cadastro ao usuário.
///
///
///
///
///
///
/// @return
///
/// - Retorna true caso a solicitação à camada de serviço tenha sido realizada com sucesso.
/// - Retorna false caso a solicitação à camada de serviço não tenha sido realizada com sucesso.
///

    virtual bool cadastrar(Nome*, Email*, Senha*, Papel*) = 0;

///
/// Método destrutor virtual da interface.
///

    virtual ~IACadastro(){}
};


///
/// Interface de gestao da camada de apresentação.
///
/// Recebe as ações feitas pelo usuário e solicita à camada de serviço que as processe.
///

class IAGestao{
public:

///
/// Solicita o serviço de execução ao usuário.
///
///
///

    virtual void executar(const Email&) = 0;

///
/// Método destrutor virtual da interface.
///

    virtual ~IAGestao(){}
};



///
/// Interface de autenticação da camada de serviço.
///
/// Valida os dados recebidos do usuário e concede acesso ao restante do sistema.
///

class ISAutenticacao{
public:

///
/// Realiza o serviço de autenticação do usuário.
///
///
///
///
/// @return
///
/// - Retorna true caso os dados estejam corretos.
/// - Retorna false caso os dados estejam incorretos ou não existam no banco de dados.
///

    virtual bool autenticar(const Email&, const Senha&) = 0;

///
/// Método destrutor virtual da interface.
///

    virtual ~ISAutenticacao(){}
};


///
/// Interface de cadastro da camada de serviço.
///
/// Observa se o usuário ja existe no banco de dados e, caso contrário, armazena seus dados.
///

class ISCadastro{
public:

///
/// Realiza o serviço de cadastramento do usuário.
///
///
///
///
///
///
/// @return
///
/// - Retorna true caso os dados forem registrados corretamente no banco de dados.
/// - Retorna false caso os dados ja existirem no banco de dados.
///

    virtual bool cadastrar(const Nome&, const Email&, const Senha&, const Papel&) = 0;

///
/// Método destrutor virtual da interface.
///

    virtual ~ISCadastro(){}
};


///
/// Interface de gestao da camada de serviço.
///
/// Executa e processa as ações do usuário.
///

class ISGestao{
public:

///
/// Executa a ação de criar do usuário.
///
///
///
/// @return
///
/// - Retorna true caso (Projeto, Plano de Sprint ou Historia de Usuário) possa e tenha sido criado com sucesso, dependendo do papel (role) do usuário.
/// - Retorna false caso (Projeto, Plano de Sprint ou Historia de Usuário) ja existir ou o papel (role) do usuário não tiver a permissão de criar.
///

    virtual bool criarProjeto(const Projeto&, const Email&) = 0;
    virtual bool criarSprint(const Plano_de_Sprint&, const Codigo&) = 0;
    virtual bool criarHistoria(const Historia_de_usuario&, const Codigo&) = 0;


///
/// Executa a ação de ler do usuário.
///
///
///
/// @return
///
/// - Retorna true caso (Projeto, Plano de Sprint ou Historia de Usuário) exista e possa ser lido dependendo do papel (role) do usuário.
/// - Retorna false caso (Projeto, Plano de Sprint ou Historia de Usuário) não existir ou o papel (role) do usuário não tiver a permissão de ler.
///

    virtual bool lerProjeto(Projeto&) = 0;
    virtual bool lerSprint(Plano_de_Sprint&) = 0;
    virtual bool lerHistoria(Historia_de_usuario&) = 0;

///
/// Executa a ação de atualizar do usuário.
///
///
///
/// @return
///
/// - Retorna true caso (Projeto, Plano de Sprint ou Historia de Usuário) exista e possa ser atualizado dependendo do papel (role) do usuário.
/// - Retorna false caso (Projeto, Plano de Sprint ou Historia de Usuário) não existir ou caso o papel (role) do usuário não tiver a permissão de atualizar.
///


    virtual bool atualizarProjeto(const Projeto&) = 0;
    virtual bool atualizarSprint(const Plano_de_Sprint&) = 0;
    virtual bool atualizarHistoria(const Historia_de_usuario&) = 0;

///
/// Executa a ação de excluir do usuário.
///
///
///
/// @return
///
/// - Retorna true caso (Projeto, Plano de Sprint ou Historia de Usuário) exista e possa ser excluido  dependendo do papel (role) do usuário.
/// - Retorna false caso (Projeto, Plano de Sprint ou Historia de Usuário) não existir ou caso o papel (role) do usuário não tiver a permissão de excluir.
///

    //virtual bool excluir(const Email&) = 0;
    virtual bool excluirProjeto(const Codigo&) = 0;
    virtual bool excluirSprint(const Codigo&) = 0;
    virtual bool excluirHistoria(const Codigo&) = 0;

///
/// Executa a ação de ler os dados do usuário.
///
///
///
/// @return
///
/// - Retorna true caso os dados existam e forem lidos com sucesso.
/// - Retorna false caso os nao existam ou nao forem lidos com sucesso.
///

    virtual bool lerConta(Pessoa&) = 0;

///
/// Executa a ação de atualizar os dados do perfil do usuário.
///
///
///
/// @return
///
/// - Retorna true caso os dados existam e forem atualizados com sucesso.
/// - Retorna false caso os dados nao existam ou nao forem atualizados com sucesso.
///

    virtual bool atualizarConta(const Pessoa&) = 0;

///
/// Executa a ação de excluir a conta do usuário.
///
///
///
/// @return
///
/// - Retorna true caso a conta exista e for excluida.
/// - Retorna false caso a conta nao exista ou nao for possível exclui-la.
///

    virtual bool excluirConta(const Email&) = 0;

///
/// Associações.
///
///
///
/// @return
///
/// - Retorna true caso...
/// - Retorna false caso...
///

    virtual bool relacaoHis_Pes(const Email&, const Codigo&, int) = 0;
    virtual bool listarHist(const Codigo&, int) = 0;
    virtual bool listarHist(const Email&) = 0;
    virtual bool moverHisProj_Sprint(const Codigo&, const Codigo&) = 0;
    virtual bool atualizarEstado(const Estado&, const Codigo&) = 0;
    virtual bool listarSprint(const Codigo&) = 0;
    virtual bool listarProjetos(const Email&) = 0;

///
/// Método destrutor virtual da interface.
///

    virtual ~ISGestao(){}
};


///
/// Interface de banco de dados da camada de persistência.
///
/// Responsável por armazenar, retornar, atualizar e excluir dados no banco de dados.
///

class IBancoDados{
public:

///
/// Verifica se os dados são iguais ou se não existem no banco de dados.
///
///
///
/// @return
///
/// - Retorna 1 caso os dados existam e sejam iguais aos que o usuário inseriu.
/// - Retorna 0 caso os dados não existam.
/// - Retorna (-1) caso os dados sejam diferentes dos que o usuário inseriu.
///

    virtual int DadosAutenticacao(const Email&, const Senha&) = 0;

///
/// Verifica se os dados já existem e, caso contrário, os armazena no banco de dados.
///
///
///
/// @return
///
/// - Retorna true caso os dados não existissem e tenham sido armazenados no banco de dados.
/// - Retorna false caso os dados já existirem no banco de dados.
///

    virtual bool DadosCadastro(const Nome&, const Email&, const Senha&, const Papel&) = 0;

///
/// Realiza a ação de criar processada pela camada de serviço.
///
///
///
/// @return
///
/// - Retorna true caso tenha sido possível armazenar no banco de dados (Projeto, Plano de Sprint ou Historia de Usuário).
/// - Retorna false caso (Projeto, Plano de Sprint ou Historia de Usuário) ja exista no banco de dados.
///

    virtual bool criarProjeto(const Projeto&, const Email&) = 0;
    virtual bool criarSprint(const Plano_de_Sprint&, const Codigo&) = 0;
    virtual bool criarHistoria(const Historia_de_usuario&, const Codigo&) = 0;

///
/// Realiza a ação de ler processada pela camada de serviço.
///
///
///
/// @return
///
/// - Retorna true caso exista no banco de dados e tenha sido possível mostrar as informações do(a) (Conta, Projeto, Plano de Sprint ou Historia de Usuário).
/// - Retorna false caso não exista o(a) (Conta, Projeto, Plano de Sprint ou Historia de Usuário) no banco de dados.
///

    virtual bool lerConta(Pessoa&) = 0;
    virtual bool lerProjeto(Projeto&) = 0;
    virtual bool lerSprint(Plano_de_Sprint&) = 0;
    virtual bool lerHistoria(Historia_de_usuario&) = 0;

///
/// Realiza a ação de atualizar processada pela camada de serviço.
///
///
///
/// @return
///
/// - Retorna true caso exista no banco de dados e tenha sido possível atualizar os dados do(a) (Conta, Projeto, Plano de Sprint ou Historia de Usuário).
/// - Retorna false caso não exista o(a) (Conta, Projeto, Plano de Sprint ou Historia de Usuário) no banco de dados.
///

    virtual bool atualizarConta(const Pessoa&) = 0;
    virtual bool atualizarProjeto(const Projeto&) = 0;
    virtual bool atualizarSprint(const Plano_de_Sprint&) = 0;
    virtual bool atualizarHistoria(const Historia_de_usuario&) = 0;

///
/// Realiza a ação de excluir processada pela camada de serviço.
///
///
///
/// @return
///
/// - Retorna true caso exista no banco de dados e tenha sido possível excluir o(a) (Projeto, Plano de Sprint ou Historia de Usuário).
/// - Retorna false caso não exista o(a) (Conta, Projeto, Plano de Sprint ou Historia de Usuário) no banco de dados.
///

    virtual bool excluirConta(const Email&) = 0;
    virtual bool excluirProjeto(const Codigo&) = 0;
    virtual bool excluirSprint(const Codigo&) = 0;
    virtual bool excluirHistoria(const Codigo&) = 0;

///
/// Associações.
///
///
///
/// @return
///
/// - Retorna true caso...
/// - Retorna false caso...
///

    virtual bool relacaoHis_Pes(const Email&, const Codigo&, int) = 0;
    virtual bool listarHistP(const Codigo&) = 0;
    virtual bool listarHistS(const Codigo&) = 0;
    virtual bool listarHistE(const Email&) = 0;
    virtual bool moverHisProj_Sprint(const Codigo&, const Codigo&) = 0;
    virtual bool atualizarEstado(const Estado&, const Codigo&) = 0;
    virtual bool listarSprint(const Codigo&) = 0;
    virtual bool listarProjetos(const Email&) = 0;

///
/// Método destrutor virtual da interface.
///

    virtual ~IBancoDados(){}
};

#endif // INTERFACES_HPP_INCLUDED
