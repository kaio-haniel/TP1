#include <iostream>
#include "dominios.hpp"

using namespace std;

//Entidade_Plano_de_Sprint:
class Plano_de_Sprint{
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;
public:
    Codigo getCod()const;
    Texto getObj()const;
    Tempo getCap()const;
    void setCod(Codigo);
    void setObj(Texto);
    void setCap(Tempo);
};
//Metodos_Plano_de_Sprint:
inline Codigo Plano_de_Sprint::getCod()const{
    return codigo;
}
inline Texto Plano_de_Sprint::getObj()const{
    return objetivo;
}
inline Tempo Plano_de_Sprint::getCap()const{
    return capacidade;
}
inline void Plano_de_Sprint::setCod(Codigo code){
    this->codigo = code;
}
inline void Plano_de_Sprint::setObj(Texto texto){
    this->objetivo = texto;
}
inline void Plano_de_Sprint::setCap(Tempo tempo){
    this->capacidade = tempo;
}
