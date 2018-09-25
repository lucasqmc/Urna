#include "LogicaUrna.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "Candidato.hpp"
#include "Eleitor.hpp"



using namespace std;

LogicaUrna::LogicaUrna(){}
LogicaUrna::~LogicaUrna(){}


///--- _*** ----  ///        Criação dos obejetos principais :           /// --- _*** ---- ///

Candidato candidato[1265];
Eleitor eleitor[1000];



///////////////----------INICIO DAS FUNÇÕES---------///////////////////////


//_____Função de leitura dos dados dos candidatos do DF:

void LogicaUrna::Leitura1(){

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

void LogicaUrna::Leitura2(){

	system("clear");

	int i;

	       // ABERTURA DO ARQUIVO DOS CANDIDATOS(APENAS DF):
	

	ifstream cbr("./data/candidatos_BR.csv");


	        // ERRO CASO A ABERTURA FALHE :

		if(!cbr.is_open()){

			cout << "ERRO: NAO ABRIU" << endl ;


		}

               //Leitura dos dados do arquivo por meio da função getline(),Feito com dois for's para evitar erro de seguimentação.


		for(i=1237;i<=1265;i++){

				getline(cbr,candidato[i].regiao,',');
				getline(cbr,candidato[i].cargo,',');
				getline(cbr,candidato[i].numero,',');
				getline(cbr,candidato[i].nome_candidato,',');
				getline(cbr,candidato[i].apelido_candidato,',');
				getline(cbr,candidato[i].numero_partido,',');
				getline(cbr,candidato[i].nome_partido,',');
				getline(cbr,candidato[i].sigla_partido,'\n');






		}	

	

	//Fechando arquivos dos candidatos do DF...

	cbr.close();


}


//_____Função para limpar buffer:

void LogicaUrna::LimpaBuffer(){



		fflush(stdin);
		fflush(stdin);
		fflush(stdin);
		fflush(stdin);
		cin.clear();
		setbuf(stdin, NULL);


		//**


}


//_____Função para configurar numero de eleitores da urna:

void LogicaUrna::UrnaConfig(){

	cout << "Digite o numero de eleitores que irão votar nessa urna:" << endl;

	cin >> eleitor[0].numero_de_eleitores;


}


//_____Função para ler nome do eleitor:

void LogicaUrna::PegaNomeEleitor(){

// Limpando tela :	

system("clear");
	

	cout << "Nome do eleitor:"<<endl;


	cin.ignore();  //Função para limpar cin 

	getline(cin,eleitor[eleitor[0].contaeleitor].nome_eleitor);




	eleitor[0].contaeleitor++; //--> Essa variavel da classe eleitor é usada somente para contar em qual indice referente ao vetor dos  eleitores eu estou.

}

//_____Função que retorna numero de eleitores:

int LogicaUrna::RetornaNumeroEleitores(){


return eleitor[0].numero_de_eleitores;


}

//_____Função MENU toda vez que o voto é realizado:       --****_*_*_*_*_*_*_*_*_*_*__*_*_*_*_*_*___*_**__--****_*_*_*_*_*_*_*_*_*_*__*_*_*_*_*_*___*_**__--****_*_

void LogicaUrna::MenuPosVoto(){
	char cmd;

				cout<<"Digite:  1-Confirmar  2-Cancelar passo  3-Votar em branco 4-Cancelar Votação"<<endl;



				LimpaBuffer();

				cmd = getchar();

						

					if(cmd == '1'){

					// BOTÃO CONFIRMA:

						cout << "VOTO CONFIRMADO !" << endl;

						cout << "-------------------------------------" << endl;
						cout  << endl;
						cout  << endl;


					//Contabilizando voto do candidato:

						/////////INDICE(POSIÇÃO) DO CANDIDATO NO VETOR///////////////////
						candidato[candidato[0].indCandidato_em_analise].numero_de_votos++;
								//Variavel Acima definida em VotarDeputadoFed()//

						
					//Atribuindo nome do candidato votado ao eleitor da vez(relacionando eleitor e candidato) :

						//Se for deputado federal:

						if(candidato[candidato[0].indCandidato_em_analise].cargo == "DEPUTADO FEDERAL" ){

							eleitor[eleitor[0].contaeleitor-1].VotoDepFed = candidato[candidato[0].indCandidato_em_analise].nome_candidato ;
						}

						//Se for deputado distrital:

						else if(candidato[candidato[0].indCandidato_em_analise].cargo == "DEPUTADO DISTRITAL" ){

							eleitor[eleitor[0].contaeleitor-1].VotoDepDist = candidato[candidato[0].indCandidato_em_analise].nome_candidato ;
						}

						//Se for senador:

						else if(candidato[candidato[0].indCandidato_em_analise].cargo == "SENADOR" ){


							// Atribuindo nome dos candidatos votados  a variaveis da classe eleitor,para facilitar relatorio :

							eleitor[eleitor[0].contaeleitor-1].VotoSen = candidato[candidato[0].indCandidato_em_analise].nome_candidato ;
							eleitor[eleitor[0].contaeleitor-1].Voto1sup = candidato[candidato[1].indCandidato_em_analise].nome_candidato ;
							eleitor[eleitor[0].contaeleitor-1].Voto2sup = candidato[candidato[2].indCandidato_em_analise].nome_candidato ;



						}

						else if(candidato[candidato[0].indCandidato_em_analise].cargo == "GOVERNADOR" ){


							// Atribuindo nome dos candidatos votados  a variaveis da classe eleitor,para facilitar relatorio :

							eleitor[eleitor[0].contaeleitor-1].VotoGov = candidato[candidato[0].indCandidato_em_analise].nome_candidato ;
							eleitor[eleitor[0].contaeleitor-1].VotoViceGov = candidato[candidato[1].indCandidato_em_analise].nome_candidato ;
							



						}


						else if(candidato[candidato[0].indCandidato_em_analise].cargo == "PRESIDENTE" ){


							// Atribuindo nome dos candidatos votados  a variaveis da classe eleitor,para facilitar relatorio :

							eleitor[eleitor[0].contaeleitor-1].VotoPres = candidato[candidato[0].indCandidato_em_analise].nome_candidato ;
							eleitor[eleitor[0].contaeleitor-1].VotoVicePres = candidato[candidato[1].indCandidato_em_analise].nome_candidato ;
							



						}

						system("clear");
					}

					else if(cmd == '2'){

					// BOTÃO CANCELA:

						cout << "PASSO CANCELADO !" << endl;


							if(candidato[candidato[0].indCandidato_em_analise].cargo == "DEPUTADO FEDERAL" ){


								VotarDeputadoFed();
							}

							//Se for deputado distrital:

							else if(candidato[candidato[0].indCandidato_em_analise].cargo == "DEPUTADO DISTRITAL" ){

								VotarDeputadoDist();

							
							}


							else if(candidato[candidato[0].indCandidato_em_analise].cargo == "SENADOR" || candidato[candidato[0].indCandidato_em_analise].cargo == "1º SUPLENTE"  || candidato[candidato[0].indCandidato_em_analise].cargo == "2º SUPLENTE" ){

								VotarSen();

							
							}


							else if(candidato[candidato[0].indCandidato_em_analise].cargo == "GOVERNADOR" || candidato[candidato[0].indCandidato_em_analise].cargo == "VICE-GOVERNADOR" ){

								VotarGov();

							
							}


							else if(candidato[candidato[0].indCandidato_em_analise].cargo == "PRESIDENTE" || candidato[candidato[0].indCandidato_em_analise].cargo == "VICE-GOVERNADOR" ){

								VotarPres();

							
							}

					}				


}







//____Função para votar em Deputado Federal:

void LogicaUrna::VotarDeputadoFed(){

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

				aux = 1; // Variavel auxiliar ultilizada para detectar se foi achado o candidato .

					cout << "-------------------------------------" << endl;

					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout << "-------------------------------------" << endl;

					//Passando indice do candidato no vetor  para atributo indCandidato_em_analise do objeto Candidato...
					//Dessa maneira poderei armazenar o indice do candidato a ser votado em uma variavel independente.

					candidato[0].indCandidato_em_analise = i;	
					

			}
	
		}
		
		if(aux == 1){

			MenuPosVoto();
		}

		else if(aux == 0){

			cout << "Candidato não encontrado! tente novamente." << endl;

		}

	}while(aux == 0);

}

//_____Função para votar em Deputado Distrital :

void LogicaUrna::VotarDeputadoDist(){


int aux = 0 ; // Variavel para auxiliar quando foi achado candidato,facilitando uso do "do while" 


	string codigo_cand_depdist;
	int i;


	do{
		cout<<"Vote para Deputado Distrital :"<<endl;


		do{                        // Laço usado para fazer a validação do codigo digitado :

			LimpaBuffer();
	
			//Lendo codigo do candidato:

			cin >> codigo_cand_depdist;

			if(codigo_cand_depdist.size()!=5){

				cout << "Insira 5 digitos !"<<endl;
			}

		}while(codigo_cand_depdist.size()!=5);


		for(i=0;i<=1237;i++){

			if(candidato[i].numero == codigo_cand_depdist){

				aux = 1; // Variavel auxiliar ultilizada para detectar se foi achado o candidato .

				//Printo as informações do candidato na tela :

					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;

					//Passando indice para o objeto candidato.
					
					candidato[0].indCandidato_em_analise = i;
		
					

			}
	
		}

		
		if(aux == 1){

			// Se foi achado o candidato é chamada a função MenuPosVoto() :

			MenuPosVoto();
		}

		else if(aux == 0){

			// Se nao foi achado candidato a variavel aux continua como zero e o laço while se repete. 

			cout << "Candidato não encontrado! tente novamente." << endl;

		}

	}while(aux == 0);

}




void LogicaUrna::VotarSen(){

int aux = 0 ;


	string codigo_cand_sen;
	int i;


	do{
		cout<<"Vote para Senador :"<<endl;


		do{

			LimpaBuffer();
	


			cin >> codigo_cand_sen;

			if(codigo_cand_sen.size()!=3){

				cout << "Insira 3 digitos !"<<endl;
			}

		}while(codigo_cand_sen.size()!=3);


		for(i=0;i<=1237;i++){

			if(candidato[i].numero == codigo_cand_sen && candidato[i].cargo == "SENADOR"){

				aux = 1; // Variavel auxiliar ultilizada para detectar se foi achado o candidato .



					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;

					//Passando indice para o objeto candidato.
					
					candidato[0].indCandidato_em_analise = i;


			}



	
		}

		for(i=0;i<=1237;i++){

			if(candidato[i].numero == codigo_cand_sen && candidato[i].cargo == "1º SUPLENTE"){

				aux = 1;



					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;


					candidato[1].indCandidato_em_analise = i;

					
					
			}


	
		}

				for(i=0;i<=1237;i++){

					if(candidato[i].numero == codigo_cand_sen && candidato[i].cargo == "2º SUPLENTE"){

					aux = 1; 



					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;


					candidato[2].indCandidato_em_analise = i;

									
			}


		}


		if(aux == 1){

			MenuPosVoto();
		}

		else if(aux == 0){

			cout << "Candidato não encontrado! tente novamente." << endl;

		}

	}while(aux == 0);

}

void LogicaUrna::VotarGov(){



int aux = 0 ;


	string codigo_cand_gov;
	int i;


	do{
		cout << "Vote para Governador :"<< endl;


		do{

			LimpaBuffer();
	


			cin >> codigo_cand_gov;

			if(codigo_cand_gov.size()!=2){

				cout << "Insira 2 digitos !"<< endl;
			}

		}while(codigo_cand_gov.size()!=2);


		for(i=0;i<=1237;i++){

			if(candidato[i].numero == codigo_cand_gov && candidato[i].cargo == "GOVERNADOR"){

				aux = 1;



					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;

					//Passando indice para o objeto candidato.
					
					candidato[0].indCandidato_em_analise = i;


			}

		}

		for(i=0;i<=1237;i++){

			if(candidato[i].numero == codigo_cand_gov && candidato[i].cargo == "VICE-GOVERNADOR"){

				aux = 1;



					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;


					candidato[1].indCandidato_em_analise = i;

					
					
			}


	
		}




		if(aux == 1){

			MenuPosVoto();
		}

		else if(aux == 0){

			cout << "Candidato não encontrado! tente novamente." << endl;

		}

	}while(aux == 0);

}

void LogicaUrna::VotarPres(){



int aux = 0 ;


	string codigo_cand_pres;
	int i;


	do{
		cout << "Vote para Presidente :"<< endl;


		do{

			LimpaBuffer();
	


			cin >> codigo_cand_pres;

			if(codigo_cand_pres.size()!=2){

				cout << "Insira 2 digitos !"<< endl;
			}

		}while(codigo_cand_pres.size()!=2);


		for(i=1237;i<=1265;i++){

			if(candidato[i].numero == codigo_cand_pres && candidato[i].cargo == "PRESIDENTE"){

				aux = 1;



					cout << "Nome: "<< candidato[i].nome_candidato << endl;
					cout << "Apelido: "<< candidato[i].apelido_candidato << endl;
					cout << "Regiao: "<< candidato[i].regiao << endl;
					cout << "Cargo: "<< candidato[i].cargo << endl;
					cout << "Partido: "<< candidato[i].nome_partido << endl;
					cout << "Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;

					//Passando indice para o objeto candidato.
					
					candidato[0].indCandidato_em_analise = i;


			}

		}

		for(i=1237;i<=1265;i++){

			if(candidato[i].numero == codigo_cand_pres && candidato[i].cargo == "VICE-PRESIDENTE"){

				aux = 1;



					cout<<"Nome: "<< candidato[i].nome_candidato << endl;
					cout<<"Regiao: "<< candidato[i].regiao << endl;
					cout<<"Cargo: "<< candidato[i].cargo << endl;
					cout<<"Partido: "<< candidato[i].nome_partido << endl;
					cout<<"Numero do partido: "<< candidato[i].numero_partido << endl;

					cout<<"-------------------------------------"<<endl;


					candidato[1].indCandidato_em_analise = i;

					
					
			}


	
		}




		if(aux == 1){

			MenuPosVoto();
		}

		else if(aux == 0){

			cout << "Candidato não encontrado! tente novamente." << endl;

		}

	}while(aux == 0);

}



void LogicaUrna::GerarRelatorio(){

int i;

	for(i=0;i<eleitor[0].numero_de_eleitores ;i++){

		
		cout << "NOME DO ELEITOR :    " << eleitor[i].nome_eleitor << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	
		cout << "Relatório de votos:" << endl;

		cout << "__________________________________" << endl;
		cout << endl;

		cout << "Deputado Federal : " << eleitor[i].VotoDepFed << endl;
		cout << "Deputado Distrital : " << eleitor[i].VotoDepDist << endl;
		cout << "Senador : " << eleitor[i].VotoSen <<  " Primeiro Suplente : " << eleitor[i].Voto1sup << " Segundo Suplente : " << eleitor[i].Voto2sup << endl;
		cout << "Governador : " << eleitor[i].VotoGov <<  " Vice : " << eleitor[i].VotoViceGov << endl;
		cout << "Presidente : " << eleitor[i].VotoPres <<  " Vice : " << eleitor[i].VotoVicePres << endl;


		cout << "__________________________________" << endl;
		cout << endl;
		cout << endl;

	}


}

void LogicaUrna::IndentificaGanhador(){

int i;

int maior = 0;
string DepFedGanhador;

	for(i=0;i<=1237;i++){

			if(candidato[i].cargo == "DEPUTADO FEDERAL" ){

					if(candidato[i].numero_de_votos > maior ){

						maior = candidato[i].numero_de_votos;
						DepFedGanhador = candidato[i].nome_candidato;


					}

			}

	}

cout << "Deputado Federal Vencedor : " << DepFedGanhador << endl;		


}


void LogicaUrna::PrintaDados(){


cout <<" codigo do presidente: " << candidato[1237].numero << endl;
cout <<" codigo do presidente: " << candidato[1238].numero << endl;
cout <<" codigo do presidente: " << candidato[1239].numero << endl;
cout <<" codigo do presidente: " << candidato[1240].numero << endl;






}
