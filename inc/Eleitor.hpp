#ifndef ELEITOR_HPP
#define ELEITOR_HPP
#include <iostream>
#include <string>

using namespace std;

class Eleitor {
        
    public:
        Eleitor();
        ~Eleitor();
        string get_nomeEleitor();
        int get_numeroEleitores();
        void set_nomeEleitor(string nome);

        string nome_eleitor;
        string VotoDepFed;
        string VotoDepDist;
        string VotoSen;
        string Voto1sup;
        string Voto2sup;
        string VotoGov;
        string VotoViceGov;
        string VotoPres;

        int numero_de_eleitores;  
        int contaeleitor;   
};

#endif
