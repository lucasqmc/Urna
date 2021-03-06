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
        void Leitura2();
        void LimpaBuffer();
        
        void UrnaConfig();
        void PegaNomeEleitor();
        void MenuPosVoto();
        void VotarDeputadoFed();
        void VotarDeputadoDist();
        void VotarSen();
        void VotarSen2();
        void VotarGov();
        void VotarPres();
        

        void GerarRelatorio();
        void IndentificaGanhador();
        int RetornaNumeroEleitores();
        int Cancela();


     
};

#endif
