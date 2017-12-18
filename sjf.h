//
//  sjf.h
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#ifndef SJF_H_
#define SJF_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "drawCpu.hpp"

class sjf {

	std::vector<int> duration;		// wektor z dlugoscia zadania
	std::vector<int> time;			// wektor z czasem nadejscia
	std::vector<int> in;			// wektor z czasem wejscia
	std::vector<int> out;			// wektor z czasem wyjscia
	std::vector<int> waiting_time;	// wektor z czasem oczekiwania zadania
	std::vector<bool> done;			// wektor z informacja o wykonaniu zadania

	std::vector<int> nr;			// numer zadania

    std::vector<int> akt_proces;
    std::vector<int> remaining;
    double awt;                        // sredni czas oczekiwania zadan

    drawCpu dr;

public:
	sjf();
	void loadFromFile();			// zaladuj dane z pliku
	void sortByTime();				// posortuj dane wg czasu nadejscia
	void algorithm();				// algorytm FIFOv
	virtual ~sjf();
    void draw(sf::RenderWindow &win);
};

#endif /* SJF_H_ */
