#ifndef CONTROLADORASPERSISTENCIA_HPP_INCLUDED
#define CONTROLADORASPERSISTENCIA_HPP_INCLUDED

#include "interfaces.hpp"
#include "sqlite3.h"
#include <iostream>
#include <string>

/// Controladora da camada de persistencia. Implementa IBancoDados usando SQLite.
class CntrBancoDados : public IBancoDados {
private:
    sqlite3* db;

    /// Converte a string do papel de volta para o numero (1, 2 ou 3).
    int mapaPapel(const std::string&);

    /// Insere uma pessoa no banco. Retorna false se o email ja existir.
    bool inserir(const std::string&, const std::string&, const std::string&, const std::string&);

public:
    CntrBancoDados();
    ~CntrBancoDados();

    int  DadosAutenticacao(const Email&, const Senha&) override;

    bool DadosCadastro(const Nome&, const Email&, const Senha&, const Papel&) override;

    bool lerConta(Pessoa&)             override;
    bool atualizarConta(const Pessoa&) override;
    bool excluirConta(const Email&)    override;

    bool criarProjeto(const Projeto&, const Email&) override;
    bool lerProjeto(Projeto&)                       override;
    bool atualizarProjeto(const Projeto&)           override;
    bool excluirProjeto(const Codigo&)              override;
    bool listarProjetos(const Email&)               override;

    bool criarSprint(const Plano_de_Sprint&, const Codigo&) override;
    bool lerSprint(Plano_de_Sprint&)                        override;
    bool atualizarSprint(const Plano_de_Sprint&)            override;
    bool excluirSprint(const Codigo&)                       override;
    bool listarSprint(const Codigo&)                        override;

    bool criarHistoria(const Historia_de_usuario&, const Codigo&) override;
    bool lerHistoria(Historia_de_usuario&)                        override;
    bool atualizarHistoria(const Historia_de_usuario&)            override;
    bool excluirHistoria(const Codigo&)                           override;
    bool relacaoHis_Pes(const Email&, const Codigo&, int)         override;
    bool listarHistP(const Codigo&)                               override;
    bool listarHistS(const Codigo&)                               override;
    bool listarHistE(const Email&)                                override;
    bool moverHisProj_Sprint(const Codigo&, const Codigo&)        override;
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
