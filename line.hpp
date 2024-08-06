/*
 * line.hpp
 *
 *  Created on: 6 de ago. de 2024
 *      Author: user
 */

#ifndef LINE_HPP_
#define LINE_HPP_

#include <cstdlib>

class Line{
private:
	int limiteInferior, limiteSuperior, inicioFila, finalFila;
	int *elementos = 0;
public:
	Line(){
		InicializarLineArr(10);
	}

	Line(int elementos){
		InicializarLineArr(elementos);
	}

	void InicializarLineArr(int elementos){
		this->inicioFila = -1;
		this->finalFila = this->inicioFila;
		this->limiteInferior = 0;
		this->limiteSuperior = elementos;

		if(this->elementos == 0){
			this->elementos = (int*) malloc(sizeof(int) * elementos);
		}
	}

	bool InserirLineArr(int valor){
		if((finalFila != inicioFila - 1) && ((inicioFila != limiteInferior) || (finalFila != limiteSuperior))){
			if(inicioFila == limiteInferior - 1){
				inicioFila = limiteInferior;
				finalFila = limiteInferior;
			}else if(finalFila == limiteSuperior){
				finalFila = limiteInferior;
			}else{
				finalFila = finalFila + 1;
			}

			elementos[finalFila] = valor;

			return true;
		}else{
			return false;
		}
	}

	bool RemoverFilaArr(){
		if(inicioFila != limiteInferior - 1){
			if(inicioFila == finalFila){
				inicioFila = limiteInferior - 1;
				finalFila = limiteInferior - 1;
			}else if(inicioFila == limiteSuperior){
				inicioFila = limiteInferior;
			}else{
				inicioFila = inicioFila + 1;
			}

			return true;
		}else{
			return false;
		}
	}

	bool ConsultarFilaArr(int* valor){
		if(inicioFila != limiteInferior - 1){
			*valor = elementos[inicioFila];

			return true;
		}else{
			return false;
		}
	}

	int getLimiteInferior(){
		return limiteInferior;
	}

	int getLimiteSuperior(){
		return limiteSuperior;
	}

	~Line(){
		free(elementos);
	}
};

#endif /* LINE_HPP_ */
