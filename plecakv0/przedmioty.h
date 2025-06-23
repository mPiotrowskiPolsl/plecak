/**@file Plik zwi�zany z przedmiotami*/
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <list>

/**Struktura reprezentuj�ca przedmiot, kt�ry w p�niejszej fazie trafia do plecaka
*/
struct przedmiot {
	/**
	Nazwa przedmiotu
	*/
	std::string nazwaP;
	/**waga przedmiotu*/
	float waga = 0;
	/**Warto�� przedmiotu*/
	float wartosc = 0;
	/**ID przedmiotu, u�ywane do rozr�nienia r�nych przedmiot�w, nawet o tej samej nazwie*/
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
Struktura reprezentuj�ca plecak*/
struct plecak {
	/**Lista przedmiot�w w plecaku*/
	std::list<przedmiot>Przdmt;
	/**��czna waga przedmiot�w w plecaku*/
	float wagaSuma = 0;
	/**��czna warto�� przedmiot�w w plecaku*/
	float wartoscSuma = 0;

	bool operator<(plecak rhs) {
		return wartoscSuma > rhs.wartoscSuma;
	}
};
/**	Funkcja pobieraj�ca dane z pliku
	@param nazwa Nazwa pliku, z kt�rego maj� by� pobrane dane
	@return Wektor przedmiot�w
*/
std::vector<przedmiot> pobierzDane(const std::string& nazwa);

/**	Funkcja losuj�ca przedmiot z puli
	@param pula Pula losowania
	@return Wylosowany przedmiot
*/
przedmiot wybierzzPuli(std::vector<przedmiot>& pula);

/**	Funkcja obliczaj�ca ��czn� mase i warto�� przedmiot�w w plecaku
	@param plec Wybrany plecak
*/
void sumujMiW(plecak& plec);

/** Funkcja wy�wietlaj�ca zawarto�� plecaka
	@param plec Plecak do wyswietlenia
*/
void wyswietlPlecak(const plecak& plec);

