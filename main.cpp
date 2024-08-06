/*
 * main.cpp
 *
 *  Created on: 6 de ago. de 2024
 *      Author: user
 */


#include <iostream>
#include <clocale>
#include "line.hpp"

using namespace std;

void testaLine(){
	Line line(5);
	bool sucesso;
	int valorConsultado;

	for(int i = 1; i <= line.getLimiteSuperior(); i++){
		sucesso = line.InserirLineArr(i);
	}

	if(sucesso){
		cout << "Linha criada!" << endl;
	}else{
		cout<< "Não foi possível adicionar a linha." << endl;

		return;
	}

	sucesso = line.ConsultarFilaArr(&valorConsultado);

	if(sucesso){
		cout << endl << "O valor no início da fila é: " << valorConsultado << endl;
	}else{
		cout << endl << "Não foi possível consultar a fila." << endl;

		return;
	}

	sucesso = line.RemoverFilaArr();

	if(sucesso){
		line.ConsultarFilaArr(&valorConsultado);

		cout << endl << "O valor no início da fila após a remoção do primeiro é: " << valorConsultado << endl;
	}else{
		cout << endl << "Não foi possível remover o valor da fila." << endl;

		return;
	}

}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "Portuguese");

	testaLine();

	return 0;
}
