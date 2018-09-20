#include <iostream>
#include <fstream>
#include "Candidato.hpp"
#include "Urna.hpp"
#include <sstream>

using namespace std;



int main() {



Urna Urna;

Candidato candidato[1238];



	int i;

	// ABERTURA DO ARQUIVO DOS CANDIDATOS(APENAS DF)
	

	ifstream cp("./data/cand_2018_DF.csv");


	// ERRO CASO A ABERTURA FALHE 

	if(!cp.is_open()){

		cout << "ERRO: NAO ABRIU" << endl ;


	}


//Leitura dos dados do arquivo por meio da função getline(),Feito com dois for's para evitar erro de segmentação.


	for(i=0;i<=600;i++){

				getline(cp,candidato[i].regiao,',');
				getline(cp,candidato[i].cargo,',');
				getline(cp,candidato[i].numero,',');
				getline(cp,candidato[i].nome_candidato,',');
				getline(cp,candidato[i].numero_partido,',');
				getline(cp,candidato[i].nome_partido,',');





		}	

	for(i=601;i<=1236;i++){

				getline(cp,candidato[i].regiao,',');
				getline(cp,candidato[i].cargo,',');
				getline(cp,candidato[i].numero,',');
				getline(cp,candidato[i].nome_candidato,',');
				getline(cp,candidato[i].numero_partido,',');
				getline(cp,candidato[i].nome_partido,',');





		}

	

//Fechando arquivos dos candidatos do DF...

	cp.close();

	


Urna.VotoDeputado();


		








	
    return 0;
}
