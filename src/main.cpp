#include <iostream>
#include <fstream>
#include <string>
#include "Candidato.hpp"
#include <sstream>


using namespace std;

Candidato candidato[1238];

///////////////----------INICIO DAS FUNÇÕES---------///////////////////////


//____Função para votar em deputado federal:____//

void VotarDeputadoFed(){

//Lendo codigo do candidato:


	cout<<"Deputado Federal :"<<endl;
	string codigo_cand_depfed;

	int i;

	do{
		cin >> codigo_cand_depfed;

		if(codigo_cand_depfed.size()!=4){

			cout << "Insira 4 digitos !"<<endl;
		}

	}while(codigo_cand_depfed.size()!=4);


	for(i=0;i<=1237;i++){

		if(candidato[i].numero == codigo_cand_depfed){

			cout<< candidato[i].nome_candidato << endl;
		}
	}

}



/////////////////--------FIM DAS FUNÇÕES E COMEÇO DA MAIN--------/////////////////////


int main() {



	int i;

	// ABERTURA DO ARQUIVO DOS CANDIDATOS(APENAS DF):
	

	ifstream cp("./data/cand_2018_DF.csv");


	// ERRO CASO A ABERTURA FALHE :

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

	


// Funções para votação:

	VotarDeputadoFed();





	
    return 0;
}
