/** @file 
	Plik z funkcjami zwi¹zanymi z genetyk¹
*/
#pragma once
#include "przedmioty.h"
/**	Funkcja krzy¿uj¹ca geny dwóch osobników
	@param pl1 Osobnik nr. 1
	@param pl2 Osobnik nr. 2
	@return Nowy osobnik z genami osobników wejœciowych
*/
plecak cross(plecak pl1, plecak pl2);

/** Funkcja odpowiedzialna za mutacje
*Podmienia losowy przedmiot z plecaka na losowy przedmiot z puli
@param pl1 Plecak do zmutowania
@param pula Pula genów
@return Zmutowany plecak
*/
plecak mutacja(plecak pl1, std::vector<przedmiot>& pula);