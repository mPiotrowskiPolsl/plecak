#include "funkcje.h"
int rand_int(int low, int high)
{
	static std::default_random_engine re{ std::random_device{}() };
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}
void wypelnij(std::string nazwa, int wiersze) {
	std::ofstream plik;
	std::string name;
	float mass;
	float value;
	plik.open(nazwa);
	for (int i = 0; i < wiersze; i++) {
		std::cin >> name >> mass >> value;
		plik << std::left << std::setw(20) << name << std::setw(10) << mass << std::setw(10) << value << std::endl;
	}
}

void dopliku(std::ofstream& out, plecak& plec, int nrGene)
{
	out << "\n================== - " << nrGene << " - ==================\n";
	out << std::left << std::setw(20) << "Nazwa" << std::setw(20) << "waga" << std::setw(12) << "Wartosc" << "\n\n";
	for (przedmiot przed : plec.Przdmt) {
		out << std::left << std::setw(20) << przed.nazwaP << std::setw(20) <<  przed.waga << std::setw(12) << przed.wartosc  << "\n";
	}
	out << "\n\nwaga: " << plec.wagaSuma << std::endl;
	out << "WARTOSC: " << plec.wartoscSuma << std::endl;
	out << "===========================================\n\n";
}

void instrukcja()
{
	std::cout << "Sposob korzystania z progamu: \n -i : sciezka pliku z danymi wejsciowymi\n - o : sciezka pliku wyjsciowego\n -p : pojemnosc plecaka\n -g : liczba generacji\n -n : liczba osobnikow na generacje\n -m : wlaczanie mutacji\n";
}
