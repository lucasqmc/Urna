#include "Candidato.hpp"


Candidato::Candidato(){

	cargo = "VAZIO";

	regiao = "";

	nome_candidato = "";

	numero = "";

	numero_partido = "";

	nome_partido = "";

	

    //Testando o construtor:     cout<<"Candidato criado com sucesso"<<endl;

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