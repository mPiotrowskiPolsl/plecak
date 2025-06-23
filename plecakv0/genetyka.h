/** @file 
	Plik z funkcjami zwi�zanymi z genetyk�
*/
#pragma once
#include "przedmioty.h"
/**	Funkcja krzy�uj�ca geny dw�ch osobnik�w
	@param pl1 Osobnik nr. 1
	@param pl2 Osobnik nr. 2
	@return Nowy osobnik z genami osobnik�w wej�ciowych
*/
plecak cross(plecak pl1, plecak pl2);

/** Funkcja odpowiedzialna za mutacje
*Podmienia losowy przedmiot z plecaka na losowy przedmiot z puli
@param pl1 Plecak do zmutowania
@param pula Pula gen�w
@return Zmutowany plecak
*/
plecak mutacja(plecak pl1, std::vector<przedmiot>& pula);