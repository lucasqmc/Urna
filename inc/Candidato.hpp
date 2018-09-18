#ifndef CANDIDATO_H
#define CANDIDATO_H
#include <iostream>
#include <string>

using namespace std;

class Candidato {


	public:

//Métodos construtor e destrutor :

		Candidato();
		~Candidato();

		string getNomeCandidato();
		string getCargoCandidato();
		int getNumeroCandidato();
		int getNumeroPartido();


		void setNumeroPartido(int partido);
		void setNumeroCandidato(int numero_canditado);
		void setCargo(string cargo);


	private:

		string cargo;
		string regiao;

		int numero_candidato;
		string nome_candidato;
		int numero_partido;



};






#endif