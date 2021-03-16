
#ifndef MAIN_
#define MAIN_

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "framework/Framework.h"
#include "./include/QuicksortP.h"
#include "./include/QuicksortS.h"
#include "./include/MergesortP.h"
#include "./include/MergesortS.h"

using namespace std;


int main(int argc, char* argv[]){
	if (argc != 2) {
		cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requerido 1."<< endl;
		cout << "Ejecute de la forma ./sort nombreFicheroEntrada.txt\n";
		exit(-1);
	}
	std::ifstream inFile;
	inFile.open(argv[1]);
	std::vector<int> numbers;
	int element;
	while (inFile >> element) {
		numbers.push_back(element);
	}

	Problema* problemaQuicksort = new QuicksortP(numbers, 0, numbers.size() - 1);
	Solucion* solucionQuicksort = new QuicksortS();
	Framework* frameworkQuick = new Framework();

	frameworkQuick->divideyVenceras(problemaQuicksort, solucionQuicksort);
	cout << "\nResultado QuickSort:" << endl;
	solucionQuicksort -> resolver();

	Problema* problemaMergesort = new MergesortP(numbers, 0, numbers.size() - 1);
	Solucion* solucionMergesort = new MergesortS();
	Framework* frameworkMerge = new Framework();

	frameworkMerge->divideyVenceras(problemaMergesort, solucionMergesort);
	cout << "\nResultado Mergesort:" << endl;
	solucionMergesort -> resolver();

};

#endif /* MAIN_ */
