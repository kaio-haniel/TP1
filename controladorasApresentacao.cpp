#include "controladorasApresentacao.hpp"
#include <cstdlib>

// ===================== CADASTRO =====================
bool CntrApresentacaoCadastro::cadastrar(Nome* nome, Email* email, Senha* senha, Papel* papel){
    std::string entradaNome, entradaEmail, entradaSenha;
    int entradaPapel;
    std::cout << "\n=== Cadastro ===\n";
    try {
        std::cout << "Nome: ";
        std::cin  >> entradaNome;
        nome->setNome(entradaNome);
        std::cout << "Email: ";
        std::cin  >> entradaEmail;
        email->setEmail(entradaEmail);
        std::cout << "\nRegras da senha:\n";
        std::cout << " - 6 caracteres\n";
        std::cout << " - Apenas letras (a-z, A-Z) ou digitos (0-9)\n";
        std::cout << " - Letra nao pode ser seguida de letra, nem digito de digito\n";
        std::cout << " - Pelo menos uma minuscula, uma maiuscula e um digito\n";
        std::cout << " - Exemplo valido: a1B2c3\n";
        std::cout << "Senha: ";
        std::cin  >> entradaSenha;
        senha->setSenha(entradaSenha);

        senha->setSenha(entradaSenha);
        std::cout << "Papel (1-Desenvolvedor, 2-Mestre Scrum, 3-Proprietario): ";
        std::cin  >> entradaPapel;
        papel->setEscolha_papel(entradaPapel);
    } catch (std::invalid_argument& exc) {
        std::cout << "Dado invalido: " << exc.what() << "\n";
        return false;
    }
    return cntrServicoCadastro->cadastrar(*nome, *email, *senha, *papel);
}

// ===================== AUTENTICACAO =====================
bool CntrApresentacaoAutenticacao::autenticar(Email* email){
    Senha senha;
    std::string entradaEmail, entradaSenha;
    std::cout << "\n=== Autenticacao ===\n";
    std::cout << "Email: ";
    std::cin  >> entradaEmail;
    std::cout << "Senha: ";
    std::cin  >> entradaSenha;
    try {
        email->setEmail(entradaEmail);
        senha.setSenha(entradaSenha);
    } catch (std::invalid_argument& exc) {
        std::cout << "Dado invalido: " << exc.what() << "\n";
        return false;
    }
    return cntrServicoAutenticacao->autenticar(*email, senha);
}

// ===================== SERVIÇO DE GESTAO =====================
// ASSOCIACOES

// CONTA.
bool CntrAGestao::lerEmail(Email& email){
    std::string entrada;
    std::cout << "Email: ";
    std::cin  >> entrada;
    try {
        email.setEmail(entrada);
    } catch (std::invalid_argument& exc) {
        std::cout << "Email invalido: " << exc.what() << "\n";
        return false;
    }
    return true;
}

bool CntrAGestao::lerDadosPessoa(Pessoa& pessoa){
    Nome  nome;
    Email email;
    Senha senha;
    Papel papel;
    std::string entradaNome, entradaEmail, entradaSenha;
    int entradaPapel;

    try {
        std::cout << "Nome: ";
        std::cin  >> entradaNome;
        nome.setNome(entradaNome);

        std::cout << "Email: ";
        std::cin  >> entradaEmail;
        email.setEmail(entradaEmail);

        std::cout << "Senha: ";
        std::cin  >> entradaSenha;
        senha.setSenha(entradaSenha);

        std::cout << "Papel (1-Desenvolvedor, 2-Mestre Scrum, 3-Proprietario): ";
        std::cin  >> entradaPapel;
        papel.setEscolha_papel(entradaPapel);
    } catch (std::invalid_argument& exc) {
        std::cout << "Dado invalido: " << exc.what() << "\n";
        return false;
    }

    pessoa.setNome(nome);
    pessoa.setEmail(email);
    pessoa.setSenha(senha);
    pessoa.setPapel(papel);
    return true;
}

void CntrAGestao::exibirPessoa(const Pessoa& pessoa){
    std::cout << "\n--- Dados da Pessoa ---\n";
    std::cout << "Nome : " << pessoa.getNome().getNome()           << "\n";
    std::cout << "Email: " << pessoa.getEmail().getEmail()         << "\n";
    std::cout << "Papel: " << pessoa.getPapel().getEscolha_papel() << "\n";
    std::cout << "-----------------------\n";
}

void CntrAGestao::menuConta(const Email& email){
    int opcao;
    std::cout << "\nBem-vindo(a), " << email.getEmail() << "!\n";

    do {
        std::cout << "\n===== Gestao de Conta =====\n";
        std::cout << "1 - Ler\n";
        std::cout << "2 - Atualizar\n";
        std::cout << "3 - Excluir\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin  >> opcao;
        std::cout << "\n";

        switch(opcao){
            case 1: {
                Pessoa pessoa;
                pessoa.setEmail(email);
                if(cntrServicoGestao->lerConta(pessoa))
                    exibirPessoa(pessoa);
                else
                    std::cout << "Pessoa nao encontrada.\n";
                break;
            }
            case 2: {
                std::cout << "Informe os dados atualizados da conta:\n";
                Pessoa pessoa;
                if(lerDadosPessoa(pessoa)){
                    if(cntrServicoGestao->atualizarConta(pessoa))
                        std::cout << "Pessoa atualizada com sucesso!\n";
                    else
                        std::cout << "Nao foi possivel atualizar (nao existe).\n";
                }
                break;
            }
            case 3: {
                int escolha;
                do{
                    std::cout << "Tem certeza que quer excluir a conta?\n";
                    std::cout << "1 - Sim\n";
                    std::cout << "0 - Nao\n";
                    std::cout << "Escolha: ";
                    std::cin  >> escolha;
                    if(escolha == 1){
                        if(cntrServicoGestao->excluirConta(email)){
                            std::cout << "Conta excluida com sucesso! O programa sera encerrado.\n";
                            std::cout << "Encerrando...\n";
                            std::exit(0);
                        }
                        else{
                            std::cout << "Nao foi possivel excluir (nao existe).\n";
                        }
                        break;
                    }
                    else if(escolha == 0) std::cout << "Voltando...\n";
                    else std::cout << "Opcao invalida";
                } while(escolha != 0);
                break;
            }
            case 0:
                std::cout << "Voltando...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while(opcao != 0);
}

// PROJETO.
bool CntrAGestao::lerDadosProjeto(Projeto& projeto){
    Codigo codigo;
    Nome nome;
    Data inicio, termino;
    std::string entradaCodigo, entradaNome, entradaInicio, entradaTermino;
    try {
        std::cout << "Codigo (5 caracteres, ex: AB123): ";
        std::cin  >> entradaCodigo;
        codigo.setCode(entradaCodigo);
        std::cout << "Nome: ";
        std::cin  >> entradaNome;
        nome.setNome(entradaNome);
        std::cout << "Data de inicio (DD/MM/AAAA): ";
        std::cin  >> entradaInicio;
        inicio.setData(entradaInicio);
        std::cout << "Data de termino (DD/MM/AAAA): ";
        std::cin  >> entradaTermino;
        termino.setData(entradaTermino);
        projeto.setCodigo(codigo);
        projeto.setNome(nome);
        projeto.setData(inicio, termino);
    } catch (std::invalid_argument& exc) {
        std::cout << "Dado invalido: " << exc.what() << "\n";
        return false;
    }
    return true;
}

bool CntrAGestao::lerCodigoProjeto(Codigo& codigo){
    std::string entrada;
    std::cout << "Codigo do projeto: ";
    std::cin  >> entrada;
    try {
        codigo.setCode(entrada);
    } catch (std::invalid_argument& exc) {
        std::cout << "Codigo invalido: " << exc.what() << "\n";
        return false;
    }
    return true;
}

void CntrAGestao::exibirProjeto(const Projeto& p){
    std::cout << "\n--- Dados do Projeto ---\n";
    std::cout << "Codigo : " << p.getCodigo().getCode() << "\n";
    std::cout << "Nome   : " << p.getNome().getNome()   << "\n";
    std::cout << "Inicio : " << p.getInicio().getData() << "\n";
    std::cout << "Termino: " << p.getTermino().getData()<< "\n";
    std::cout << "------------------------\n";
}

void CntrAGestao::menuProjetos(const Email& e){
    int opcao;
    do {
        std::cout << "\n====================== Gestao de Projeto ======================\n";
        std::cout << "1 - Criar\n2 - Ler\n3 - Atualizar\n4 - Excluir\n";
        std::cout << "\n========================= Associacoes =========================\n";
        std::cout << "5 - Listar PROJETOS associados a PESSOA\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha: ";
        std::cin  >> opcao;
        std::cout << "\n";
        Pessoa conta;
        conta.setEmail(e);
        std::string papel;
        if(cntrServicoGestao->lerConta(conta)) papel = conta.getPapel().getEscolha_papel();
        switch(opcao){
            case 1: {
                if(papel != "PROPIETARIO DE PRODUTO"){
                    std::cout << "Voce nao tem a permissao necessaria para criar um projeto.\n";
                    break;
                }
                Projeto p;
                Pessoa scrum;
                Email iEmail, oEmail;
                bool resultadoProj = lerDadosProjeto(p);
                std::cout << "O projeto, ao ser criado, deve ser associado a um Mestre Scrum, pelo email dele.\n";
                bool resultadoScrum = lerEmail(iEmail);
                scrum.setEmail(iEmail);
                cntrServicoGestao->lerConta(scrum);
                if(scrum.getPapel().getEscolha_papel() != "MESTRE SCRUM"){
                    std::cout << "O email informado deve pertencer a um mestre scrum.\n";
                    break;
                }
                if(resultadoProj && resultadoScrum){
                    if(cntrServicoGestao->criarProjeto(p, iEmail)) std::cout << "Projeto criado com sucesso!\n";
                    else std::cout << "Nao foi possivel criar (codigo ja existe).\n";
                }
                break;
            }
            case 2: {
                Codigo c;
                if(lerCodigoProjeto(c)){
                    Projeto p; p.setCodigo(c);
                    if(cntrServicoGestao->lerProjeto(p)) exibirProjeto(p);
                    else std::cout << "Projeto nao encontrado.\n";
                }
                break;
            }
            case 3: {
                if(papel != "PROPIETARIO DE PRODUTO"){
                    std::cout << "Voce nao tem a permissao necessaria para atualizar um projeto.\n";
                    break;
                }
                std::cout << "Informe os dados atualizados (mesmo codigo):\n";
                Projeto p;
                if(lerDadosProjeto(p)){
                    if(cntrServicoGestao->atualizarProjeto(p)) std::cout << "Projeto atualizado com sucesso!\n";
                    else std::cout << "Nao foi possivel atualizar (nao existe).\n";
                }
                break;
            }
            case 4: {
                if(papel != "PROPIETARIO DE PRODUTO"){
                    std::cout << "Voce nao tem a permissao necessaria para excluir um projeto.\n";
                    break;
                }
                Codigo c;
                if(lerCodigoProjeto(c)){
                    if(cntrServicoGestao->excluirProjeto(c)) std::cout << "Projeto excluido com sucesso!\n";
                    else std::cout << "Nao foi possivel excluir (nao existe).\n";
                }
                break;
            }
            case 5: {
                Email e;
                if(lerEmail(e)){
                    if(cntrServicoGestao->listarProjetos(e)) std::cout << "\nEsses sao os projetos associados a pessoa.\n";
                    else std::cout << "\nNao foi possivel listar os projetos associados a pessoa.\n";
                }
                break;
            }
            case 0: std::cout << "Voltando...\n"; break;
            default: std::cout << "Opcao invalida.\n";
        }
    } while(opcao != 0);
}

// PLANO DE SPRINT
bool CntrAGestao::lerDadosSprint(Plano_de_Sprint& sprint){
        Codigo codigo; Texto objetivo; Tempo capacidade;
        std::string entradaCodigo, entradaObjetivo;
        int entradaCapacidade;
        try {
            std::cout << "Codigo (5 caracteres, ex: SP123): ";
            std::cin  >> entradaCodigo;
            codigo.setCode(entradaCodigo);
            std::cin.ignore();
            std::cout << "Objetivo (texto): ";
            std::getline(std::cin, entradaObjetivo);
            objetivo.setTexto(entradaObjetivo);
            std::cout << "Capacidade (dias, 1 a 365): ";
            std::cin  >> entradaCapacidade;
            capacidade.setDuracao(entradaCapacidade);

            sprint.setCodigo(codigo);
            sprint.setObjetivo(objetivo);
            sprint.setCapacidade(capacidade);
        } catch (std::invalid_argument& exc) {
            std::cout << "Dado invalido: " << exc.what() << "\n";
            return false;
        }
        return true;
    }

bool CntrAGestao::lerCodigoSprint(Codigo& codigo){
    std::string entrada;
    std::cout << "Codigo do plano de sprint: ";
    std::cin  >> entrada;
    try {
        codigo.setCode(entrada);
    } catch (std::invalid_argument& exc) {
        std::cout << "Codigo invalido: " << exc.what() << "\n";
        return false;
    }
    return true;
}

void CntrAGestao::exibirSprint(const Plano_de_Sprint& s){
    std::cout << "\n--- Dados do Plano de Sprint ---\n";
    std::cout << "Codigo    : " << s.getCodigo().getCode()        << "\n";
    std::cout << "Objetivo  : " << s.getObjetivo().getTexto()     << "\n";
    std::cout << "Capacidade: " << s.getCapacidade().getDuracao() << " dias\n";
    std::cout << "--------------------------------\n";
}

void CntrAGestao::menuSprints(const Email& e){
    int opcao;
    do {
        std::cout << "\n================== Gestao de Plano de Sprint ==================\n";
        std::cout << "1 - Criar\n2 - Ler\n3 - Atualizar\n4 - Excluir\n";
        std::cout << "\n========================= Associacoes =========================\n";
        std::cout << "5 - Listar PLANOS DE SPRINT associados a PROJETO\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha: ";
        std::cin  >> opcao;
        std::cout << "\n";
        Pessoa conta;
        conta.setEmail(e);
        std::string papel;
        if(cntrServicoGestao->lerConta(conta)) papel = conta.getPapel().getEscolha_papel();

        switch(opcao){
            case 1: {
                if(papel != "MESTRE SCRUM"){
                    std::cout << "Voce nao tem a permissao necessaria para criar um plano de sprint.\n";
                    break;
                }
                Projeto p;
                Plano_de_Sprint s;
                Codigo c;
                bool resultadoSprint = lerDadosSprint(s);
                std::cout << "O plano de sprint, ao ser criado, deve ser associado a um projeto, pelo seu codigo.\n";
                bool resultadoCodigo = lerCodigoProjeto(c);
                p.setCodigo(c);
                bool existencia = cntrServicoGestao->lerProjeto(p);
                if(!existencia){
                    std::cout << "O plano de sprint deve ser associado a um projeto existente.\n";
                    break;
                }
                if(resultadoSprint && resultadoCodigo){
                    if(cntrServicoGestao->criarSprint(s, c)) std::cout << "Plano de Sprint criado com sucesso!\n";
                    else std::cout << "Nao foi possivel criar (codigo ja existe).\n";
                }
                break;
            }
            case 2: {
                Codigo c;
                if(lerCodigoSprint(c)){
                    Plano_de_Sprint s; s.setCodigo(c);
                    if(cntrServicoGestao->lerSprint(s)) exibirSprint(s);
                    else std::cout << "Plano de Sprint nao encontrado.\n";
                }
                break;
            }
            case 3: {
                if(papel != "MESTRE SCRUM"){
                    std::cout << "Voce nao tem a permissao necessaria para atualizar um plano de sprint.\n";
                    break;
                }
                std::cout << "Informe os dados atualizados (mesmo codigo):\n";
                Plano_de_Sprint s;
                if(lerDadosSprint(s)){
                    if(cntrServicoGestao->atualizarSprint(s)) std::cout << "Plano de Sprint atualizado com sucesso!\n";
                    else std::cout << "Nao foi possivel atualizar (nao existe).\n";
                }
                break;
            }
            case 4: {
                if(papel != "MESTRE SCRUM"){
                    std::cout << "Voce nao tem a permissao necessaria para excluir um plano de sprint.\n";
                    break;
                }
                Codigo c;
                if(lerCodigoSprint(c)){
                    if(cntrServicoGestao->excluirSprint(c)) std::cout << "Plano de Sprint excluido com sucesso!\n";
                    else std::cout << "Nao foi possivel excluir (nao existe).\n";
                }
                break;
            }
            case 5: {
                Codigo c;
                if(lerCodigoProjeto(c)){
                    if(cntrServicoGestao->listarSprint(c)) std::cout << "\nEsses sao os planos de sprint associados ao projeto.\n";
                    else std::cout << "\nNao foi possivel listar os planos de sprint associados ao projeto.\n";
                }
                break;
            }
            case 0: std::cout << "Voltando...\n"; break;
            default: std::cout << "Opcao invalida.\n";
        }
    } while(opcao != 0);
}

// HISTORIA DE USUARIO.
bool CntrAGestao::lerDadosHistoria(Historia_de_usuario& h){
        Codigo codigo; Texto titulo, papel, acao, valor; Tempo estimativa;
        Prioridade prioridade; Estado estado;
        std::string eCodigo, eTitulo, ePapel, eAcao, eValor;
        int eEstimativa, ePrioridade;
        try {
            std::cout << "Codigo (5 caracteres, ex: HU123): ";
            std::cin  >> eCodigo;  codigo.setCode(eCodigo);
            std::cin.ignore();
            std::cout << "Titulo: ";        std::getline(std::cin, eTitulo);  titulo.setTexto(eTitulo);
            std::cout << "Papel (como...): ";std::getline(std::cin, ePapel);  papel.setTexto(ePapel);
            std::cout << "Acao (eu quero...): "; std::getline(std::cin, eAcao); acao.setTexto(eAcao);
            std::cout << "Valor (para...): ";std::getline(std::cin, eValor);  valor.setTexto(eValor);
            std::cout << "Estimativa (dias, 1 a 365): "; std::cin >> eEstimativa; estimativa.setDuracao(eEstimativa);
            std::cout << "Prioridade (1-ALTA, 2-MEDIA, 3-BAIXA): "; std::cin >> ePrioridade; prioridade.setPrio(ePrioridade);
            estado.setEstado(1);

            h.setCodigo(codigo); h.setTitulo(titulo); h.setPapel(papel); h.setAcao(acao);
            h.setValor(valor); h.setEstimativa(estimativa); h.setPrioridade(prioridade); h.setEstado(estado);
        } catch (std::invalid_argument& exc) {
            std::cout << "Dado invalido: " << exc.what() << "\n";
            return false;
        }
        return true;
    }

bool CntrAGestao::lerCodigoHistoria(Codigo& codigo){
    std::string entrada;
    std::cout << "Codigo da historia: ";
    std::cin  >> entrada;
    try { codigo.setCode(entrada); }
    catch (std::invalid_argument& exc) { std::cout << "Codigo invalido: " << exc.what() << "\n"; return false; }
    return true;
}

void CntrAGestao::exibirHistoria(const Historia_de_usuario& h){
    std::cout << "\n--- Dados da Historia de Usuario ---\n";
    std::cout << "Codigo    : " << h.getCodigo().getCode()        << "\n";
    std::cout << "Titulo    : " << h.getTitulo().getTexto()       << "\n";
    std::cout << "Papel     : " << h.getPapel().getTexto()        << "\n";
    std::cout << "Acao      : " << h.getAcao().getTexto()         << "\n";
    std::cout << "Valor     : " << h.getValor().getTexto()        << "\n";
    std::cout << "Estimativa: " << h.getEstimativa().getDuracao() << " dias\n";
    std::cout << "Prioridade: " << h.getPrioridade().getPrio()    << "\n";
    std::cout << "Estado    : " << h.getEstado().getEstado()      << "\n";
    std::cout << "------------------------------------\n";
}

void CntrAGestao::menuHistorias(const Email& e){
    int opcao;
    do {
        std::cout << "\n================ Gestao de Historia de Usuario ================\n";
        std::cout << " 1 - Criar\n 2 - Ler\n 3 - Atualizar\n 4 - Excluir\n";
        std::cout << "\n========================= Associacoes =========================\n";
        std::cout << " 5 - Estabelecer associacao entre HISTORIA DE USUARIO e PESSOA\n";
        std::cout << " 6 - Remover associacao entre HISTORIA DE USUARIO e PESSOA\n";
        std::cout << " 7 - Listar HISTORIAS DE USUARIO associadas a PROJETO\n";
        std::cout << " 8 - Listar HISTORIAS DE USUARIO associadas a PLANO DE SPRINT\n";
        std::cout << " 9 - Listar HISTORIAS DE USUARIO associadas a PESSOA\n";
        std::cout << "10 - Mover HISTORIA DE USUARIO de PROJETO para PLANO DE SPRINT\n";
        std::cout << " 0 - Voltar\n";
        std::cout << "Escolha: ";
        std::cin  >> opcao;
        std::cout << "\n";
        Pessoa conta;
        conta.setEmail(e);
        std::string papel;
        if(cntrServicoGestao->lerConta(conta)) papel = conta.getPapel().getEscolha_papel();
        switch(opcao){
            case 1: {
                if(papel != "PROPIETARIO DE PRODUTO"){
                    std::cout << "Voce nao tem a permissao necessaria para criar uma historia de usuario.\n";
                    break;
                }
                Projeto p;
                Historia_de_usuario h;
                Codigo c;
                bool resultadoHist = lerDadosHistoria(h);
                std::cout << "Historia de usuario, ao ser criada, deve ser associada a um projeto, pelo seu codigo.\n";
                bool resultadoCodigo = lerCodigoProjeto(c);
                p.setCodigo(c);
                bool existencia = cntrServicoGestao->lerProjeto(p);
                if(!existencia){
                    std::cout << "A historia de usuario deve ser associada a um projeto existente.\n";
                    break;
                }
                if(resultadoHist && resultadoCodigo){
                    if(cntrServicoGestao->criarHistoria(h, c)) std::cout << "Historia criada com sucesso!\n";
                    else std::cout << "Nao foi possivel criar (codigo ja existe).\n";
                }
                break;
            }
            case 2: {
                Codigo c;
                if(lerCodigoHistoria(c)){
                    Historia_de_usuario h; h.setCodigo(c);
                    if(cntrServicoGestao->lerHistoria(h)) exibirHistoria(h);
                    else std::cout << "Historia nao encontrada.\n";
                }
                break;
            }
            case 3: {
                if(papel != "PROPIETARIO DE PRODUTO"){
                    std::cout << "Voce nao tem a permissao necessaria para atualizar uma historia de usuario.\n";
                    break;
                }
                std::cout << "Informe os dados atualizados (mesmo codigo):\n";
                Historia_de_usuario h;
                if(lerDadosHistoria(h)){
                    if(cntrServicoGestao->atualizarHistoria(h)) std::cout << "Historia atualizada com sucesso!\n";
                    else std::cout << "Nao foi possivel atualizar (nao existe).\n";
                }
                break;
            }
            case 4: {
                if(papel != "PROPIETARIO DE PRODUTO"){
                    std::cout << "Voce nao tem a permissao necessaria para excluir uma historia de usuario.\n";
                    break;
                }
                Codigo c;
                if(lerCodigoHistoria(c)){
                    if(cntrServicoGestao->excluirHistoria(c)) std::cout << "Historia excluida com sucesso!\n";
                    else std::cout << "Nao foi possivel excluir (nao existe).\n";
                }
                break;
            }
            case 5: {
                if(papel != "MESTRE SCRUM"){
                    std::cout << "Voce nao tem a permissao necessaria para estabelecer associacao entre historia de usuario e pessoa.\n";
                    break;
                }
                Codigo c;
                Email e;
                if(lerEmail(e) && lerCodigoHistoria(c)){
                    if(cntrServicoGestao->relacaoHis_Pes(e, c, 1)) std::cout << "Associacao realizada com sucesso!\n";
                    else std::cout << "Nao foi possivel realizar a associacao.\n";
                }
                break;
            }
            case 6: {
                if(papel != "MESTRE SCRUM"){
                    std::cout << "Voce nao tem a permissao necessaria para remover associacao entre historia de usuario e pessoa.\n";
                    break;
                }
                Codigo c;
                Email e;
                if(lerEmail(e) && lerCodigoHistoria(c)){
                    if(cntrServicoGestao->relacaoHis_Pes(e, c, 0)) std::cout << "Remocao da associacao realizada com sucesso!\n";
                    else std::cout << "Nao foi possivel realizar a remocao da associacao.\n";
                }
                break;
            }
            case 7: {
                Codigo p;
                if(lerCodigoProjeto(p)){
                    if(cntrServicoGestao->listarHist(p, 1)) std::cout << "\nEssas sao as historias de usuario associadas ao projeto.\n";
                    else std::cout << "Nao foi possivel listar as historias de usuario associadas ao projeto.\n";
                }
                break;
            }
            case 8: {
                Codigo s;
                if(lerCodigoSprint(s)){
                    if(cntrServicoGestao->listarHist(s, 2)) std::cout << "\nEssas sao as historias de usuario associadas ao plano de sprint.\n";
                    else std::cout << "Nao foi possivel listar as historias de usuario associadas ao plano de sprint.\n";
                }
                break;
            }
            case 9: {
                Email e;
                if(lerEmail(e)){
                    if(cntrServicoGestao->listarHist(e)) std::cout << "\nEssas sao as historias de usuario associadas a pessoa.\n";
                    else std::cout << "Nao foi possivel listar as historias de usuario associadas a pessoa.\n";
                }
                break;
            }
            case 10: {
                if(papel != "MESTRE SCRUM"){
                    std::cout << "Voce nao tem a permissao necessaria para mover historia de usuario de projeto para plano de sprint.\n";
                    break;
                }
                Codigo s, h;
                if(lerCodigoSprint(s) && lerCodigoHistoria(h)){
                    if(cntrServicoGestao->moverHisProj_Sprint(s, h))
                        std::cout << "A historia de usuario foi movida de projeto para plano de sprint com sucesso!\n";
                    else std::cout << "Nao foi possivel mover a historia de usuario de projeto para plano de sprint.\n";
                }
            }
            case 0: std::cout << "Voltando...\n"; break;
            default: std::cout << "Opcao invalida.\n";
        }
    } while(opcao != 0);
}

void CntrAGestao::executar(const Email& email){
    int opcao;
    do {
        cout << "\n========= MENU PRINCIPAL =========\n";
        cout << "1 - Dados da Conta\n";
        cout << "2 - Gerir Projetos\n";
        cout << "3 - Gerir Planos de Sprint\n";
        cout << "4 - Gerir Historias de Usuario\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        switch(opcao){
            case 1:
                menuConta(email);
                break;
            case 2:
                menuProjetos(email);
                break;
            case 3:
                menuSprints(email);
                break;
            case 4:
                menuHistorias(email);
                break;
            case 0: std::cout << "Fechando...\n"; break;
            default: std::cout << "Opcao invalida.\n";
        }
    } while(opcao != 0);
}
