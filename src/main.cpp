#include <iostream>
#include <fstream>
#include "Candidato.hpp"

using namespace std;



int main() {



Candidato candidato1;




	
	cout << "Testando sistema" << endl;

	ifstream cp("./data/candidatos-presidente.csv");



	if(!cp.is_open()){

		cout << "ERRO: NAO ABRIU" << endl ;


	}

 		cout<<"Nome do candidato: "<< candidato1.getNomeCandidato() << endl;






	
    return 0;
}
