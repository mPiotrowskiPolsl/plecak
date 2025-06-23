#include <iostream>
#include <vector>
#include <algorithm>
#include "przedmioty.h"
#include "funkcje.h"
#include <iomanip>
#include <list>
#include "genetyka.h"
//-i dane.txt -o wyjscie.txt -p 12 -g 10 -n 10
//./main.o -i dane.txt -o wyjsciee.txt -g 1000 -n 25 -p 12 -m


/**Funkcja g³ówna
*/
int main(int argc, char* argv[]) {
	std::string input = "";
	std::string output;
	float maxLoad = 0; // ladownosc plecaka
	int genCount = 0; // liczba generacji
	int indPerGen = 0; // osobnikow na generacje
	bool mutacje = false;
	if (argc > 1) {
		for (int i = 0; i < argc; i++) {
			if (argv[i] == std::string("-i")) {
				input = (argv[i + 1]);
			}
			if (argv[i] == std::string("-o")) {
				output = argv[i + 1];
			}
			if (argv[i] == std::string("-p")) {
				maxLoad = std::stof(argv[i + 1]);
			}
			if (argv[i] == std::string("-g")) {
				genCount = std::stoi(argv[i + 1]);
			}
			if (argv[i] == std::string("-n")) {
				indPerGen = std::stoi(argv[i + 1]);
			}
			if (argv[i] == std::string("-m")) {
				mutacje = true;
			}
		}
	}
	else {
		instrukcja();
		return 0;
	}
	
	auto rng = std::default_random_engine{ std::random_device{}()};
	std::vector<przedmiot> pula = pobierzDane(input);
	std::cout << "Plik wejsciowy: " << input << std::endl;
	std::cout << "Plik wyjsciowy: " << output << std::endl;
	std::cout << "Pojemnosc plecaka: " << maxLoad << std::endl;
	std::cout << "Liczba generacji: " << genCount << std::endl;
	std::cout << "Osobnikow na generacje: " << indPerGen << std::endl;
	std::cout << "Przedmiotow w puli: " << pula.size() << std::endl;
	std::cout << "\n\n";

	std::ofstream out;
	out.open(output);
	if (!(out.is_open())) { 
		std::cerr << "Plik nie zostal otwarty\n"; 
		return 0;
	}
	
	out << "Najlepsze rozwiazania z kazdej generacji: \n\n";
	//pierwsza generacja
	std::vector<plecak> biezaca;
	biezaca.resize(indPerGen);
	for (plecak &plec : biezaca) {
		for (przedmiot przed : pula) {
			if (rand_int(0, 1) && plec.wagaSuma + przed.waga < maxLoad) {
				plec.Przdmt.push_back(przed);
				plec.wagaSuma += przed.waga;
				plec.wartoscSuma += przed.wartosc;
			}
		}
		std::shuffle(pula.begin(), pula.end(), rng);
	}
	dopliku(out, biezaca[0], 1);

	//krzy¿owanie
	for (int g = 2; g <= genCount; ++g) {
		std::vector<plecak> poprzednia = biezaca;
		biezaca.clear();
		int x = ceil(sqrt(indPerGen));
		int y = ceil(indPerGen / x);
		plecak kandydat;

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (j == i) continue;
				if (rand_int(0, 1)) kandydat = cross(poprzednia[j], poprzednia[i]);
				else kandydat = cross(poprzednia[i], poprzednia[j]);
				if (!(rand_int(0, 20)) && mutacje==true) 
				{
					kandydat = mutacja(kandydat, pula);
					//std::cout << "Mutacja\n";
				}
				if (kandydat.wagaSuma > maxLoad) continue;
				biezaca.push_back(kandydat);
			}
		}

		//biezaca.push_back(poprzednia[0]);
		int tmpI=0;
		while (tmpI < x || biezaca.size() < indPerGen) {
			biezaca.push_back(poprzednia[tmpI]);
			tmpI++;
		}
		std::sort(biezaca.begin(), biezaca.end());
		biezaca.resize(indPerGen);
		biezaca.shrink_to_fit();
		dopliku(out, biezaca[0], g);
	}
	out.close();

	std::cout << "Gotowe!\n";
}