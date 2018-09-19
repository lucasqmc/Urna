#include "Candidato.hpp"


Candidato::Candidato(){

	cargo = "VAZIO";

	regiao = "VAZIO";

	nome_candidato = "VAZIO";

	numero = "VAZIO";

	numero_partido = "VAZIO";

	nome_partido = "VAZIO";

	//Testando o construtor:
	// cout<<"Candidato criado com sucesso"<<endl;

}

Candidato::~Candidato(){}

string Candidato::getNomeCandidato(){

	return nome_candidato;
}

string Candidato::getCargoCandidato(){

	return cargo;
}

string Candidato::getNumeroCandidato(){

	return numero;
}

string Candidato::getNumeroPartido(){

	return numero_partido;
}