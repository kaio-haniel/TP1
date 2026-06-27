#ifndef CONTROLADORASSERVICO_HPP_INCLUDED
#define CONTROLADORASSERVICO_HPP_INCLUDED

#include "interfaces.hpp"

// ===================== AUTENTICACAO =====================
/// Controladora de servico para autenticacao. Delega ao banco de dados.
class CntrServicoAutenticacao : public ISAutenticacao {
private:
    IBancoDados* cntrBancoDados;
public:
    void setCntrBancoDados(IBancoDados*);
    bool autenticar(const Email&, const Senha&) override;
};

inline void CntrServicoAutenticacao::setCntrBancoDados(IBancoDados* cntr){
    cntrBancoDados = cntr;
}

inline bool CntrServicoAutenticacao::autenticar(const Email& email, const Senha& senha){
    return (cntrBancoDados->DadosAutenticacao(email, senha) == 1);
}

// ===================== SERVIÇO DE GESTAO =====================
/// Controladora de servico para gestao. Delega ao banco de dados.
class CntrServicoGestao : public ISGestao {
private:
    IBancoDados* cntrBancoDados;
public:
    void setCntrBancoDados(IBancoDados*);

    bool lerConta(Pessoa& p)             override { return cntrBancoDados->lerConta(p);}
    bool atualizarConta(const Pessoa& p) override { return cntrBancoDados->atualizarConta(p); }
    bool excluirConta(const Email& e)    override { return cntrBancoDados->excluirConta(e); }

    bool criarProjeto(const Projeto& p, const Email& e)    override { return cntrBancoDados->criarProjeto(p, e); }
    bool lerProjeto(Projeto& p)                            override { return cntrBancoDados->lerProjeto(p); }
    bool atualizarProjeto(const Projeto& p)                override { return cntrBancoDados->atualizarProjeto(p); }
    bool excluirProjeto(const Codigo& c)                   override { return cntrBancoDados->excluirProjeto(c); }
    bool listarProjetos(const Email& e)                    override { return cntrBancoDados->listarProjetos(e); }

    bool criarSprint(const Plano_de_Sprint& s, const Codigo& c)    override { return cntrBancoDados->criarSprint(s, c); }
    bool lerSprint(Plano_de_Sprint& s)                             override { return cntrBancoDados->lerSprint(s); }
    bool atualizarSprint(const Plano_de_Sprint& s)                 override { return cntrBancoDados->atualizarSprint(s); }
    bool excluirSprint(const Codigo& c)                            override { return cntrBancoDados->excluirSprint(c); }
    bool listarSprint(const Codigo& c)                             override { return cntrBancoDados->listarSprint(c); }

    bool criarHistoria(const Historia_de_usuario& h, const Codigo& c)    override { return cntrBancoDados->criarHistoria(h, c); }
    bool lerHistoria(Historia_de_usuario& h)                             override { return cntrBancoDados->lerHistoria(h); }
    bool atualizarHistoria(const Historia_de_usuario& h)                 override { return cntrBancoDados->atualizarHistoria(h); }
    bool excluirHistoria(const Codigo& c)                                override { return cntrBancoDados->excluirHistoria(c); }
    bool relacaoHis_Pes(const Email& e, const Codigo& c, int num)        override { return cntrBancoDados->relacaoHis_Pes(e, c, num); }
    bool listarHist(const Codigo& c, int num) override {
        switch(num){
            case 1: return cntrBancoDados->listarHistP(c);
            case 2: return cntrBancoDados->listarHistS(c);
        }
        return false;
    }
    bool listarHist(const Email& e)                                      override { return cntrBancoDados->listarHistE(e); }
    bool moverHisProj_Sprint(const Codigo& s, const Codigo& h)           override { return cntrBancoDados->moverHisProj_Sprint(s, h); }
    bool atualizarEstado(const Estado& e, const Codigo& c)               override { return cntrBancoDados->atualizarEstado(e, c); }
};

inline void CntrServicoGestao::setCntrBancoDados(IBancoDados* cntr){
    cntrBancoDados = cntr;
}

// ===================== CADASTRO =====================
/// Controladora de servico para cadastro. Delega ao banco de dados.
class CntrServicoCadastro : public ISCadastro {
private:
    IBancoDados* cntrBancoDados;
public:
    void setCntrBancoDados(IBancoDados* cntr){ cntrBancoDados = cntr; }
    bool cadastrar(const Nome& n, const Email& e, const Senha& s, const Papel& p) override {
        return cntrBancoDados->DadosCadastro(n, e, s, p);
    }
};

#endif // CONTROLADORASSERVICO_HPP_INCLUDED
