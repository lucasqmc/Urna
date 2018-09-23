#ifndef LOGICAURNA_HPP
#define LOGICAURNA_HPP
#include <iostream>
#include <string>

using namespace std;

class LogicaUrna {
        
    public:



        LogicaUrna();
        ~LogicaUrna();

        void Leitura1();
        void LimpaBuffer();
        void UrnaConfig();
        void PegaNomeEleitor();
        void MenuPosVoto();
        void VotarDeputadoFed();
        void VotarDeputadoDist();
        void GerarRelatorio();
        void VotarSen();
        void IndentificaGanhador();
        int RetornaNumeroEleitores();


     
};

#endif
