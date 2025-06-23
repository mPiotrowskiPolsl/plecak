/** @file
	Plik z funkcjami
*/
#pragma once
#include <random>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "przedmioty.h"
/** Funkcja generuje losow¹ liczbê ca³kowit¹
	@param low Dolna granica 
	@param high Górna granica
	@return Wylosowana liczba ca³kowita
*/
int rand_int(int low, int high);

/** Funkcja do wype³niania pliku danymi podanymi z konsoli
* aktualnie nie u¿ywana
	@param nazwa Nazwa pliku docelowego
	@param wiersze Liczba wierszy do wpisania
*/
void wypelnij(std::string nazwa, int wiersze);

/** Funkcja do zapisywania do pliku odpowiednio sformatowanych danych(plecak) wyjœciowych.
* Zapisuje podany w argumencie plecak
	@param out Strumieñ pliku wyjœciowego(docelowego)
	@param plec Plecak Ÿród³owy
	@param nrGene Nr. generacji*/
void dopliku(std::ofstream& out, plecak& plec, int nrGene);

/** Funkcja wyœwietla krótk¹ instrukcje korzystania z programu*/
void instrukcja();

