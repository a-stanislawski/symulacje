//
//  robin.hpp
//  symulacje
//
//  Created by Adam Stanislawski on 16.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#ifndef robin_hpp
#define robin_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "drawCpu.hpp"


class robin {
    sf::Font font;
    std::vector<int> duration;        // wektor z dlugoscia zadan
    std::vector<int> rem_dur;        // wektor z pozostala dlugoscia zadan
    std::vector<int> time;            // wektor z czasem nadejscia
    std::vector<int> in;            // wektor z czasem wejscia
    std::vector<int> out;            // wektor z czasem wyjscia
    std::vector<int> waiting_time;    // wektor z czasem oczekiwania zadania
    std::vector<bool> done;            // wektor z informacja o wykonaniu zadania
    
    std::vector<int> nr;            // numer zadania
    
    std::vector<int> akt_proces;
    std::vector<int> remaining;
    double awt;                        // sredni czas oczekiwania zadan
    bool stop;
    
    int ready;
    
    drawCpu dr;
public:
    robin();
    void loadFromFile();            // zaladuj dane z pliku
    void sortByTime();                // posortuj dane wg czasu nadejscia
    void algorithm();                // algorytm FIFO
    virtual ~robin();
    void draw(sf::RenderWindow &win);
    void pause(bool p);
};


#endif /* robin_hpp */
