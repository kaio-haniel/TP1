#ifndef CONTROLADORASPERSISTENCIA_HPP_INCLUDED
#define CONTROLADORASPERSISTENCIA_HPP_INCLUDED

#include "Interfaces.hpp"
#include "sqlite3.h"
#include <iostream>
#include <string>

///
/// Módulo que implementa a interface do banco de dados da camada de persistência.
///
/// Herda de IBancoDados e gerencia a comunicação direta com o banco de dados relacional SQLite,
/// sendo responsável pela execução de comandos SQL e controle de persistência.
///

class CntrBancoDados : public IBancoDados {
private:
    sqlite3* db;

    // Converte a string do papel de volta para o numero (1, 2 ou 3).
    int mapaPapel(const std::string&);

    // Insere uma pessoa no banco. Retorna false se o email ja existir.
    bool inserir(const std::string&, const std::string&, const std::string&, const std::string&);

public:

///
/// Método construtor padrão.
///
/// Inicializa a conexão com o arquivo do banco de dados SQLite.
///

    CntrBancoDados();

///
/// Método destrutor da classe.
///
/// Garante o fechamento seguro da conexão ativa com o banco de dados SQLite.
///

    ~CntrBancoDados();

///
/// Verifica se os dados informados correspondem aos registros armazenados no banco de dados.
///
/// - Retorna 1 caso as credenciais existam e estejam corretas.
/// - Retorna 0 caso as credenciais não existam.
/// - Retorna (-1) caso a senha esteja incorreta para o e-mail informado.
///

    int  DadosAutenticacao(const Email&, const Senha&) override;

///
/// Realiza a inserção dos dados do novo usuário na tabela (pessoa).
///
/// - Retorna true caso o e-mail não exista no banco de dados e o registro seja realizado com sucesso.
/// - Retorna false caso o e-mail já exista no banco de dados ou o registro não seja realizado com sucesso.
///

    bool DadosCadastro(const Nome&, const Email&, const Senha&, const Papel&) override;

///
/// Mostra os dados de uma conta com base no email (Primary Key) e preenche o objeto de retorno.
///

    bool lerConta(Pessoa&)             override;

///
/// Atualiza a coluna do usuário na tabela (pessoa) a partir do seu email (Primary Key).
///

    bool atualizarConta(const Pessoa&) override;

///
/// Remove a conta do usuário do banco de dados.
///

    bool excluirConta(const Email&)    override;

///
/// Insere um novo projeto no banco de dados, estabelecendo associação com um mestre scrum a partir de uma Foreign Key.
///

    bool criarProjeto(const Projeto&, const Email&) override;

///
/// Consulta a tabela projetos e preenche o objeto com as informações encontradas a partir do seu codigo (Primary Key).
///

    bool lerProjeto(Projeto&)                       override;

///
/// Atualiza os atributos de um projeto no banco de dados a partir do seu codigo (Primary Key).
///

    bool atualizarProjeto(const Projeto&)           override;

///
/// Remove o projeto do banco de dados a partir do seu codigo (Primary Key).
///

    bool excluirProjeto(const Codigo&)              override;

///
/// Mostra todos os projetos associados a uma pessoa por meio do seu email (Foreign Key).
///

    bool listarProjetos(const Email&)               override;

///
/// Insere um novo plano de sprint no banco de dados, estabelecendo associação com um projeto a partir de uma Foreign Key.
///

    bool criarSprint(const Plano_de_Sprint&, const Codigo&) override;

///
/// Consulta a tabela planos_sprint e preenche o objeto com os dados encontrados a partir de seu codigo (Primary Key).
///

    bool lerSprint(Plano_de_Sprint&)                        override;

///
/// Atualiza os atributos de um plano de sprint no banco de dados a partir do seu codigo (Primary Key).
///

    bool atualizarSprint(const Plano_de_Sprint&)            override;

///
/// Remove o plano de sprint do banco de dados a partir do seu codigo (Primary Key).
///

    bool excluirSprint(const Codigo&)                       override;

///
/// Mostra todos os planos de sprint associados a um projeto por meio do seu codigo (Foreign Key).
///

    bool listarSprint(const Codigo&)                        override;

///
/// Insere uma nova história de usuário no banco de dados, estabelecendo associação com um projeto a partir de uma Foreign Key.
///

    bool criarHistoria(const Historia_de_usuario&, const Codigo&) override;

///
/// Consulta a tabela historia e preenche o objeto com os dados encontrados a partir de seu codigo (Primary Key).
///

    bool lerHistoria(Historia_de_usuario&)                        override;

///
/// Atualiza os atributos de uma historia de usuario no banco de dados a partir do seu codigo (Primary Key).
///

    bool atualizarHistoria(const Historia_de_usuario&)            override;

///
/// Remove a historia de usuario do banco de dados a partir do seu codigo (Primary Key).
///

    bool excluirHistoria(const Codigo&)                           override;

///
/// Estabelece ou remove associação entre historia de usuario e pessoa.
/// Se o parametro de numero inteiro for igual a 1, é estabelecido associacao entre a historia de usuario e a pessoa a partir de um email (Foreign Key),
/// se for igual a 0, é removido associacao entre a historia de usuario e a pessoa, transformando o valor da Foreign Key em uma string vazia.
///

    bool relacaoHis_Pes(const Email&, const Codigo&, int)         override;

///
/// Mostra todas as historias de usuario associadas a um projeto por meio do seu codigo (Foreign Key).
///

    bool listarHistP(const Codigo&)                               override;

///
/// Mostra todas as historias de usuario associadas a um plano de sprint por meio do seu codigo (Foreign Key).
///

    bool listarHistS(const Codigo&)                               override;

///
/// Mostra todas as historias de usuario associadas a uma pessoa por meio de seu email (Foreign Key).
///

    bool listarHistE(const Email&)                                override;

///
/// Modifica as Foreign Keys da história de usuário para move-la de projeto para plano de sprint.
///

    bool moverHisProj_Sprint(const Codigo&, const Codigo&)        override;

///
/// Altera o valor do estado de uma história de usuário no banco de dados a partir de seu codigo (Primary Key).
///

    bool atualizarEstado(const Estado&, const Codigo&)            override;
};


inline CntrBancoDados::~CntrBancoDados(){
    if(db) sqlite3_close(db);
}

inline bool CntrBancoDados::DadosCadastro(const Nome& nome, const Email& email,
                                          const Senha& senha, const Papel& papel){
    return inserir(nome.getNome(), email.getEmail(), senha.getSenha(), papel.getEscolha_papel());
}

#endif // CONTROLADORASPERSISTENCIA_HPP_INCLUDED
