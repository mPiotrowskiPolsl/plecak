/** @file
	Plik z funkcjami
*/
#pragma once
#include <random>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "przedmioty.h"
/** Funkcja generuje losow� liczb� ca�kowit�
	@param low Dolna granica 
	@param high G�rna granica
	@return Wylosowana liczba ca�kowita
*/
int rand_int(int low, int high);

/** Funkcja do wype�niania pliku danymi podanymi z konsoli
* aktualnie nie u�ywana
	@param nazwa Nazwa pliku docelowego
	@param wiersze Liczba wierszy do wpisania
*/
void wypelnij(std::string nazwa, int wiersze);

/** Funkcja do zapisywania do pliku odpowiednio sformatowanych danych(plecak) wyj�ciowych.
* Zapisuje podany w argumencie plecak
	@param out Strumie� pliku wyj�ciowego(docelowego)
	@param plec Plecak �r�d�owy
	@param nrGene Nr. generacji*/
void dopliku(std::ofstream& out, plecak& plec, int nrGene);

/** Funkcja wy�wietla kr�tk� instrukcje korzystania z programu*/
void instrukcja();

