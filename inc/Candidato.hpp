#ifndef CANDIDATO_H
#define CANDIDATO_H
#include <iostream>
#include <string>

using namespace std;

class Candidato {



//Métodos construtor e destrutor :
public:
		Candidato();
		~Candidato();

		string getNomeCandidato();
		string getCargoCandidato();
		int getNumeroCandidato();
		int getNumeroPartido();

		void setNomeCandidato(string nome_candidato);
		void setNumeroPartido(int partido);
		void setNumeroCandidato(int numero_canditado);
		void setCargo(string cargo);


		string cargo;
		string regiao;
		int numero_candidato;
		string nome_candidato;
		int numero_partido;



};






#endif