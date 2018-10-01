#include <iostream>
#include <fstream>
#include <string>
#include "Candidato.hpp"
#include "Eleitor.hpp"
#include <sstream>
#include <stdlib.h>
#include "LogicaUrna.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//   Nome : Lucas Leite Macedo Maduro 
//   Matricula : 170016811
//   Conta GitLab : lucasqmc

				//******************************************/////////////////--------URNA ELETRONICA--------/////////////////////**********************************//


int main() {

int i ;


//Criação do objeto responsável por toda logica interna da urna :

LogicaUrna logica;


//Leitura dos dados do arquivo de candidatos-DF
logica.Leitura1();
logica.Leitura2();

//Configurações acerca da Urna :	

logica.UrnaConfig();	

//Inicio do loop de votação :

	for(i=0 ; i < logica.RetornaNumeroEleitores(); i++){

		// Funções para votação :

	logica.PegaNomeEleitor();
	logica.VotarDeputadoFed();
	logica.VotarDeputadoDist();
	logica.VotarSen();
	logica.VotarSen2();
	logica.VotarGov();
	logica.VotarPres();



	}


//Geração do relatório :

logica.GerarRelatorio();

logica.IndentificaGanhador();
	
	
    return 0;
}
