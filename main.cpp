#include "controladorasApresentacao.hpp"
#include "controladorasServico.hpp"
#include "controladorasPersistencia.hpp"
#include <iostream>
using namespace std;

int main(){
// ============= Modulo de Apresentacao principal =============

    // camada de persistencia (banco unico)
    CntrBancoDados bancoDados;

    // camada de servico
    CntrServicoAutenticacao servicoAutenticacao;
    CntrServicoCadastro     servicoCadastro;
    CntrServicoGestao       servicoGestao;

    // camada de apresentacao
    CntrApresentacaoAutenticacao apresentacaoAutenticacao;
    CntrApresentacaoCadastro     apresentacaoCadastro;
    CntrAGestao                  apresentacaoGestao;

    // ligacoes servico -> banco
    servicoAutenticacao.setCntrBancoDados(&bancoDados);
    servicoCadastro.setCntrBancoDados(&bancoDados);
    servicoGestao.setCntrBancoDados(&bancoDados);

    // ligacoes apresentacao -> servico
    apresentacaoAutenticacao.setCntrServicoAutenticacao(&servicoAutenticacao);
    apresentacaoCadastro.setCntrServicoCadastro(&servicoCadastro);
    apresentacaoGestao.setCntrServicoGestao(&servicoGestao);

    // MENU INICIAL: Login ou Cadastro
    int inicial;
    bool autenticado = false;
    Email email;

    do {
        cout << "\n========= BEM-VINDO =========\n";
        cout << "1 - Login\n";
        cout << "2 - Cadastrar\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> inicial;

        if(inicial == 1){
            if(apresentacaoAutenticacao.autenticar(&email)){
                cout << "\nAutenticado com sucesso!\n";
                autenticado = true;
            } else {
                cout << "\nFalha na autenticacao.\n";
            }
        }
        else if(inicial == 2){
            Nome n; Email e; Senha s; Papel p;
            if(apresentacaoCadastro.cadastrar(&n, &e, &s, &p))
                cout << "\nCadastro realizado com sucesso! Agora faca login.\n";
            else
                cout << "\nNao foi possivel cadastrar (email ja existe ou dado invalido).\n";
        }
    } while(inicial != 0 && !autenticado);

    // se autenticou, abre o menu principal
    if(autenticado){
        apresentacaoGestao.executar(email);
    }

    return 0;
}
