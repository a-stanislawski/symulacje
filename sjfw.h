//
//  sjfw.h
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#ifndef SJFW_H_
#define SJFW_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "drawCpu.hpp"


class sjfw {
    sf::Font font;
	std::vector<int> duration;		// wektor z dlugoscia zadan
	std::vector<int> rem_dur;		// wektor z pozostala dlugoscia zadan
	std::vector<int> time;			// wektor z czasem nadejscia
	std::vector<int> in;			// wektor z czasem wejscia
	std::vector<int> out;			// wektor z czasem wyjscia
	std::vector<int> waiting_time;	// wektor z czasem oczekiwania zadania
	std::vector<bool> done;			// wektor z informacja o wykonaniu zadania

	std::vector<int> nr;			// numer zadania

    std::vector<int> akt_proces;
    std::vector<int> remaining;
    double awt;                        // sredni czas oczekiwania zadan

	int ready;
    
    drawCpu dr;
public:
	sjfw();
	void loadFromFile();			// zaladuj dane z pliku
	void sortByTime();				// posortuj dane wg czasu nadejscia
	void algorithm();				// algorytm FIFO
	virtual ~sjfw();
    void draw(sf::RenderWindow &win);
};

#endif /* SJFW_H_ */
