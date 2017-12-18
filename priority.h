//
//  priority.hpp
//  symulacje
//
//  Created by Adam Stanislawski on 18.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#ifndef PRIORITY_H_
#define PRIORITY_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "drawCpu.hpp"

class priority {
	std::vector<int> duration;		// wektor z dlugoscia zadania
	std::vector<int> time;			// wektor z czasem nadejscia
	std::vector<int> pr;			// wektor z priorytetem
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
	priority();
	void loadFromFile();			// zaladuj dane z pliku
	void sortByTime();				// posortuj dane wg czasu nadejscia
	void algorithm();				// algorytm FIFOv
	virtual ~priority();
    void draw(sf::RenderWindow &win);
};

#endif /* PRIORITY_H_ */
