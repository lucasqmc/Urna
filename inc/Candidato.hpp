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

		string getNumeroCandidato();
		string getNumeroPartido();

		void setNomeCandidato(string nome_candidato);
		void setNumeroPartido(int partido);
		void setNumeroCandidato(int numero);
		void setCargo(string cargo);


		string cargo;
		string regiao;
		string nome_partido;
		string numero;
		string nome_candidato;
		string numero_partido;



};






#endif