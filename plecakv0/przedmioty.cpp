#include "przedmioty.h"
#include "funkcje.h"

std::vector<przedmiot> pobierzDane(const std::string& nazwa) {
	std::fstream plikO;
	przedmiot buf;
	plikO.open(nazwa);
	std::string linia= "";
	std::vector<przedmiot> gen1;
	int i = 0;
	while (getline(plikO, linia)) {
		std::istringstream ln(linia);
		ln >> buf.nazwaP >> buf.waga >> buf.wartosc;
		buf.id = i;
		gen1.push_back(buf);
		i++;
	}
	return gen1;
}
przedmiot wybierzzPuli(std::vector<przedmiot>& pula) {
	pula.shrink_to_fit();
	return pula[rand_int(0, pula.size()-1)];
}

void sumujMiW(plecak& plec)
{
	plec.wagaSuma = 0;
	plec.wartoscSuma = 0;
	for (przedmiot przed : plec.Przdmt) {
		plec.wagaSuma += przed.waga;
		plec.wartoscSuma += przed.wartosc;
	}
}

void wyswietlPlecak(const plecak& plec)
{
	for (przedmiot przed : plec.Przdmt) {
		std::cout << std::left << std::setw(12) << przed.nazwaP << std::setw(12) << przed.wartosc << std::setw(12) << przed.waga << "\n";
	}
	std::cout << "				waga: " << plec.wagaSuma << std::endl;
	std::cout << "				WARTOSC: " << plec.wartoscSuma << std::endl;
}
