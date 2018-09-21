#include <iostream>
#include <fstream>
#include <string>
#include "Candidato.hpp"
#include "Eleitor.hpp"
#include <sstream>
#include <stdlib.h>
#include "LogicaUrna.hpp"



/////////////////--------FIM DAS FUNÇÕES E COMEÇO DA MAIN--------/////////////////////


int main() {

int i ;

LogicaUrna logica;

//Leitura dos dados do arquivo de candidatos-DF
logica.Leitura1();

//Configurações acerca da Urna:	

logica.UrnaConfig();	

//Limpar buffer do teclado:





	for(i=0 ; i < logica.RetornaNumeroEleitores(); i++){

		// Funções para votação:

	logica.PegaNomeEleitor();
	logica.VotarDeputadoFed();



	}

logica.GerarRelatorio();
	
	
    return 0;
}
