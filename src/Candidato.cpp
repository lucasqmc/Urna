#include "Candidato.hpp"


Candidato::Candidato(){

	cargo = "";

	regiao = "";

	nome_candidato = "VAZIO";

	numero_candidato = 0000;

	numero_partido = 00;

	cout<<"Candidato criado com sucesso"<<endl;

}

Candidato::~Candidato(){}

string Candidato::getNomeCandidato(){

	return nome_candidato;
}

string Candidato::getCargoCandidato(){

	return cargo;
}

int Candidato::getNumeroCandidato(){

	return numero_candidato;
}

int Candidato::getNumeroPartido(){

	return numero_partido;
}