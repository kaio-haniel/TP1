#ifndef CONTROLADORASAPRESENTACAO_HPP_INCLUDED
#define CONTROLADORASAPRESENTACAO_HPP_INCLUDED

#include "interfaces.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// ===================== AUTENTICACAO =====================
/// Controladora da camada de apresentacao para autenticacao.
class CntrApresentacaoAutenticacao : public IAAutenticacao {
private:
    ISAutenticacao* cntrServicoAutenticacao;
public:
    void setCntrServicoAutenticacao(ISAutenticacao*);
    bool autenticar(Email*) override;
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(ISAutenticacao* cntr){
    cntrServicoAutenticacao = cntr;
}

// ===================== SERVIÇO DE GESTAO =====================
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
    void menuConta(const Email&);
    void menuProjetos(const Email&);
    void menuSprints(const Email&);
    void menuHistorias(const Email&);

public:
    void setCntrServicoGestao(ISGestao*);
    void executar(const Email&) override;
};

inline void CntrAGestao::setCntrServicoGestao(ISGestao* cntr){
    cntrServicoGestao = cntr;
}
// ===================== CADASTRO =====================
/// Controladora da camada de apresentacao para cadastro de usuario.
class CntrApresentacaoCadastro : public IACadastro {
private:
    ISCadastro* cntrServicoCadastro;
public:
    void setCntrServicoCadastro(ISCadastro* cntr){ cntrServicoCadastro = cntr; }
    bool cadastrar(Nome*, Email*, Senha*, Papel*) override;
};

#endif // CONTROLADORASAPRESENTACAO_HPP_INCLUDED
