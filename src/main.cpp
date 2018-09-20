#include <iostream>
#include <fstream>
#include <string>
#include "Candidato.hpp"
#include <sstream>


using namespace std;

Candidato candidato[1238];

int main() {



	int i;

	// ABERTURA DO ARQUIVO DOS CANDIDATOS(APENAS DF)
	

	ifstream cp("./data/cand_2018_DF.csv");


	// ERRO CASO A ABERTURA FALHE 

	if(!cp.is_open()){

		cout << "ERRO: NAO ABRIU" << endl ;


	}


//Leitura dos dados do arquivo por meio da função getline(),Feito com dois for's para evitar erro de seguimentação.


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

	
//Lendo codigo do candidato:


	cout<<"Deputado Federal :"<<endl;
	string codigo_cand;

	cin >> codigo_cand;

		
	for(i=0;i<=1236;i++){

		if(codigo_cand == candidato[i].numero){

			if(candidato[i].cargo == "DEPUTADO FEDERAL") {

				cout<<"Nome do candidato: "<< candidato[i].nome_candidato << endl;


			}
			else{

				cout<<"Inexistente"<<endl;

			}



		}

	}






	
    return 0;
}
