#include <iostream>
#include <fstream>
#include <string>
#include "Candidato.hpp"
#include "Eleitor.hpp"
#include <sstream>
#include <stdlib.h>


using namespace std;


///--- _*** ----  ///        Criação dos obejetos principais :           /// --- _*** ---- ///

Candidato candidato[1238];
Eleitor eleitor[1000];



///////////////----------INICIO DAS FUNÇÕES---------///////////////////////


//_____Função de leitura dos dados dos candidatos do DF:

void Leitura1(){

	system("clear");

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


}


//_____Função para limpar buffer:

void LimpaBuffer(){



		fflush(stdin);
		fflush(stdin);
		fflush(stdin);
		fflush(stdin);
		cin.clear();
		setbuf(stdin, NULL);


		//**


}




//_____Função para configurar urna:

void UrnaConfig(){

	cout << "Digite o numero de eleitores que irão votar nessa urna:" << endl;

	cin >> eleitor[0].numero_de_eleitores;




}


//_____Função para ler nome do eleitor:

void PegaNomeEleitor(){


	

	cout << "Nome do eleitor:"<<endl;


	cin.ignore();

	getline(cin,eleitor[eleitor[0].contaeleitor].nome_eleitor);


	eleitor[0].contaeleitor++; // Essa variavel da classe eleitor é usada somente para contar em qual indice referente ao vetor dos  candidatos eu estou.

}

//_____Função menu toda vez que o voto é realizado:

void MenuPosVoto(){
	char cmd;

				cout<<"Digite:  1-Confirmar  2-Cancelar passo  3-Votar em branco 4-Cancelar Votação"<<endl;



				LimpaBuffer();

				cmd = getchar();

				switch (cmd) {

					//BOTÃO CONFIRMA:

					case '1':

						candidato[0].numero_de_votos++;

						cout << "Voto Confirmado !" << endl; //candidato[0].indCandidato_em_analise<<endl;

					case '2': break;

					case '3': break;

					case '4': break;


					default: break;
				}



}



//____Função para votar em Deputado Federal:

void VotarDeputadoFed(){

//Lendo codigo do candidato:

int aux = 0 ;


	string codigo_cand_depfed;
	int i;


	do{
		cout<<"Vote para Deputado Federal :"<<endl;


		do{

			LimpaBuffer();
	


			cin >> codigo_cand_depfed;

			if(codigo_cand_depfed.size()!=4){

				cout << "Insira 4 digitos !"<<endl;
			}

		}while(codigo_cand_depfed.size()!=4);


		for(i=0;i<=1237;i++){

			if(candidato[i].numero == codigo_cand_depfed){

				aux = 1;

					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;

					//Passando indice ...
					//mandar indice para algum lugar.

					candidato[0].indCandidato_em_analise = i;

					MenuPosVoto();

					

					

				
					

			}
	
		}

		if(aux == 0){

			cout << "Candidato não encontrado! tente novamente." << endl;

		}

	}while(aux == 0);




}






/////////////////--------FIM DAS FUNÇÕES E COMEÇO DA MAIN--------/////////////////////


int main() {

int i ;
//Leitura dos dados do arquivo de candidatos-DF
Leitura1();

//Configurações acerca da Urna:	

UrnaConfig();	

//Limpar buffer do teclado:

LimpaBuffer();
fflush(stdin);


	for(i=0 ; i <= eleitor[0].numero_de_eleitores - 1; i++){

		// Funções para votação:

	PegaNomeEleitor();
	VotarDeputadoFed();



	}


	
	
    return 0;
}
