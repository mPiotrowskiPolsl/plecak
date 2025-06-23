/**@file Plik zwi¹zany z przedmiotami*/
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <list>

/**Struktura reprezentuj¹ca przedmiot, który w póŸniejszej fazie trafia do plecaka
*/
struct przedmiot {
	/**
	Nazwa przedmiotu
	*/
	std::string nazwaP;
	/**waga przedmiotu*/
	float waga = 0;
	/**Wartoœæ przedmiotu*/
	float wartosc = 0;
	/**ID przedmiotu, u¿ywane do rozró¿nienia ró¿nych przedmiotów, nawet o tej samej nazwie*/
	int id = 0;

	bool operator==(przedmiot rhs) {
		return id == rhs.id;
	};
	bool operator!=(przedmiot rhs) {
		return id != rhs.id;
	}
	bool operator<(przedmiot rhs) {
		return id < rhs.id;
	};
};
/**
Struktura reprezentuj¹ca plecak*/
struct plecak {
	/**Lista przedmiotów w plecaku*/
	std::list<przedmiot>Przdmt;
	/**£¹czna waga przedmiotów w plecaku*/
	float wagaSuma = 0;
	/**£¹czna wartoœæ przedmiotów w plecaku*/
	float wartoscSuma = 0;

	bool operator<(plecak rhs) {
		return wartoscSuma > rhs.wartoscSuma;
	}
};
/**	Funkcja pobieraj¹ca dane z pliku
	@param nazwa Nazwa pliku, z którego maj¹ byæ pobrane dane
	@return Wektor przedmiotów
*/
std::vector<przedmiot> pobierzDane(const std::string& nazwa);

/**	Funkcja losuj¹ca przedmiot z puli
	@param pula Pula losowania
	@return Wylosowany przedmiot
*/
przedmiot wybierzzPuli(std::vector<przedmiot>& pula);

/**	Funkcja obliczaj¹ca ³¹czn¹ mase i wartoœæ przedmiotów w plecaku
	@param plec Wybrany plecak
*/
void sumujMiW(plecak& plec);

/** Funkcja wyœwietlaj¹ca zawartoœæ plecaka
	@param plec Plecak do wyswietlenia
*/
void wyswietlPlecak(const plecak& plec);

