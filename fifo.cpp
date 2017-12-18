//
//  fifo.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "fifo.h"


fifo::fifo() {
	awt = 0;
	loadFromFile();
	algorithm();
}

fifo::~fifo() {
	// TODO Auto-generated destructor stub
}

void fifo::loadFromFile()
{
	std::ifstream plik ("example.txt");

	std::string line, line_time, line_duration;
	if (plik.is_open())
	{
	   while ( getline (plik,line) )
	   {
	     std::cout << line << '\n';
	     std::size_t pos = line.find(" ");
	     line_time = line.substr(0,line.size() - pos );
	     line_duration = line.substr(pos+1);

	     time.push_back(std::stoi(line_time));
	     duration.push_back(std::stoi(line_duration));
         remaining.push_back(std::stoi(line_duration));
	   }
	   plik.close();
	 }
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku!";
		exit(1);
	}

	for(int i = 0 ; i < time.size(); i++)
	{
		std::cout << time.at(i) << "+" << duration.at(i) << "\n";
	}

}

void fifo::saveToFile()
{
    std::ofstream plik("/Users/adamstanislawski/Desktop/file1.txt");
    if (plik.is_open())
    {
        plik << "Nr\t| nadejscie\t| czas trwania\t| wykonano\t| czas oczekiwania" << "\n";
        plik << "--------------------------------------------------------------\n";
        for(int i = 0; i < time.size(); i++)
        {
            plik << "P" << i << "\t| " << time.at(i) << "\t\t| " << duration.at(i) << "\t\t| " << out.at(i) << "\t\t| "<< waiting_time.at(i) << "\n";
        }
        
        plik << "\n\n\n";
        plik << "--------------------------------------------------------------\n";
        plik << "Sredni czas oczekiwania: " << awt;
        
        plik.close();
    }
    else std::cout << "Unable to open file";
}

void fifo::sortByTime()
{

}

void fifo::algorithm()
{
	int current_time = 0;
	for(int i = 0; i < time.size(); i++)
	{
		// jesli po wykonaniu nie ma zadan oczekujacych, przeskocz do nadejscia nastepnego zadania
		while(current_time < time.at(i))
        {
            current_time++;
            akt_proces.push_back(-1);
        }

		in.push_back(current_time);
		waiting_time.push_back(current_time - time.at(i));
		current_time+= duration.at(i);
        for(int k = 0; k < duration.at(i); k++)
        {
            akt_proces.push_back(i);
        }
		out.push_back(current_time);
	}

	// wyswietlanie wynikow algorytmu
	std::cout << "come\tdone\twait\n";
	for(int i = 0; i < time.size(); i++)
	{
		std::cout << in.at(i) << "\t" << out.at(i) << "\t" << waiting_time.at(i) << "\n";
	}

	// liczenie sredniego czasu oczekiwania
	awt = 0;
	for(int i = 0; i < time.size(); i++)
	{
		awt+=waiting_time.at(i);
	}

	awt = awt/time.size();
	std::cout << "Sredni czas oczekiwania: " << awt << "\n";
    
    dr.loadData(duration, time, akt_proces);
    saveToFile();
}

void fifo::draw(sf::RenderWindow &win)
{
    dr.draw(win, 0);
}


