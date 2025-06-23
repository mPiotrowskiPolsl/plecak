#include "genetyka.h"
#include "funkcje.h"
#include <list>

plecak mutacja(plecak pl1, std::vector<przedmiot>& pula) {
    //pl1.Przdmt.push_back(pula[rand_int(0, pula.size()-1)]);
    auto it = pl1.Przdmt.begin();
    advance(it, rand_int(0, pl1.Przdmt.size()-1));
    *it = pula[rand_int(0, pula.size() - 1)];
    pl1.Przdmt.sort();
    pl1.Przdmt.unique();
    sumujMiW(pl1);
    //wyswietlPlecak(pl1);
    return pl1;
}
plecak cross(plecak pl1, plecak pl2)
{
    //std::cout << "KRZYZOWANIE: " << "\n";
    auto it1 = pl1.Przdmt.begin();
    auto it2 = pl2.Przdmt.begin();
    //if(it1!=pl1.Przdmt.end())std::advance(it1, (int)floor(pl1.Przdmt.size() / 2)+rand_int(0,1));
    if(it1!=pl1.Przdmt.end())std::advance(it1, rand_int(0,pl1.Przdmt.size()-1));
    //if(it2!=pl2.Przdmt.end()) std::advance(it2, (int)floor(pl2.Przdmt.size() / 2)+rand_int(0,1));
    if(it2!=pl2.Przdmt.end()) std::advance(it2, rand_int(0,pl2.Przdmt.size()-1));
    pl1.Przdmt.erase(pl1.Przdmt.begin(), it1);
    pl2.Przdmt.erase(it2, pl2.Przdmt.end());
    pl1.Przdmt.sort();
    pl2.Przdmt.sort();
    pl1.Przdmt.merge(pl2.Przdmt);
    pl1.Przdmt.sort();
    pl1.Przdmt.unique();
    sumujMiW(pl1);

    //std::cout << "KONIEC KRZYZOWANIA" << "\n";

    return pl1;
}
