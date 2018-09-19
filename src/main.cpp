#include <iostream>
#include <fstream>
#include "Candidato.hpp"
#include <sstream>

using namespace std;



int main() {




Candidato candidato[20];



	
	

	ifstream cp("./data/cand_2018_DF.csv");



	if(!cp.is_open()){

		cout << "ERRO: NAO ABRIU" << endl ;


	}





				getline(cp,candidato[0].regiao,',');
				getline(cp,candidato[0].cargo,',');
				getline(cp,candidato[0].numero,',');
				getline(cp,candidato[0].nome_candidato,',');
				getline(cp,candidato[0].numero_partido,',');
				getline(cp,candidato[0].nome_partido,',');





			

	



	cp.close();

	



	cout << "regiao do candidato: "<< candidato[0].regiao << endl;

	cout << "cargo do candidato: "<< candidato[0].cargo << endl;
	cout << "numero do candidato: "<< candidato[0].numero << endl;
	cout << "nome do candidato: "<< candidato[0].nome_candidato << endl;
	cout << "numero partido do candidato: "<< candidato[0].numero_partido << endl;
	cout << "nome do partido: "<< candidato[0].nome_partido << endl;








	
    return 0;
}
