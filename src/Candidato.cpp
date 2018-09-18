#include "Candidato.hpp"


Candidato::Candidato(){

	cargo = "";

	regiao = "";

	nome_candidato = "";

	numero_candidato = 0000;

	numero_partido = 00;



}

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