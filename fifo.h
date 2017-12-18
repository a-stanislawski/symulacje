//
//  fifo.h
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#ifndef FIFO_H_
#define FIFO_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "drawCpu.hpp"



class fifo {
	std::vector<int> duration;		// wektor z dlugoscia zadania
	std::vector<int> time;			// wektor z czasem nadejscia
	std::vector<int> in;			// wektor z czasem wejscia
	std::vector<int> out;			// wektor z czasem wyjscia
	std::vector<int> waiting_time;	// wektor z czasem oczekiwania zadania
    std::vector<int> akt_proces;    // wektor zmian (do wyswietlania)
    std::vector<int> remaining;     // wektor pozostalego czasu (do wyswietlania)
	double awt;						// sredni czas oczekiwania zadan
    
    drawCpu dr;                     // obiekt rysuje
public:
	fifo();
	void loadFromFile();			// zaladuj dane z pliku
    void saveToFile();
	void sortByTime();				// posortuj dane wg czasu nadejscia
	void algorithm();				// algorytm FIFO
    void draw(sf::RenderWindow &win);
	virtual ~fifo();
};

#endif /* FIFO_H_ */
