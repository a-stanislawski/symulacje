//
//  sjf.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "sjf.h"

sjf::sjf() {
	// TODO Auto-generated constructor stub
	awt = 0;
	loadFromFile();
	algorithm();

	/*for(int i = 0; i < time.size(); i++)
	{
		nr.push_back(i);
	}*/

}

sjf::~sjf() {
	// TODO Auto-generated destructor stub
}

void sjf::loadFromFile()
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
	     done.push_back(0);
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

void sjf::sortByTime()
{

}

void sjf::algorithm()
{
	int shortest = 0;
	int s_dur = 0;
	int current_time = 0;
	int prw = 0; // przynajmniej raz wykonano

		for(int i = 0; i < time.size(); i++)
		{
			s_dur = 10000;
			for(int j = 0; j < time.size() ; j++)
			{
				if( done.at(j) ) continue;
				if( time.at(j) > current_time) continue;
				prw = 1;
				if(duration.at(j) >= s_dur) continue;
				else
					{
					s_dur = duration.at(j);
					shortest = j;
					}
			}
			if(prw == 0)
			{
				current_time++;
				akt_proces.push_back(-1);
				i--;
				continue;
			}
			prw = 0;
			nr.push_back(shortest);

			in.push_back(current_time);
			waiting_time.push_back(current_time - time.at(shortest));
			current_time+=duration.at(shortest);
            for(int k = 0; k < duration.at(shortest); k++)
            {
                akt_proces.push_back(shortest);
            }
			out.push_back(current_time);
			done.at(shortest) = 1;

		}


	// wyswietlanie wynikow algorytmu
	std::cout << "Nr\tin\tout\twait\n";
	for(int i = 0; i < time.size(); i++)
	{
		std::cout << nr.at(i) << "\t" << in.at(i) << "\t" << out.at(i) << "\t" << waiting_time.at(i) << "\n";
		std::cout << "a" << i;
	}
	std::cout << "DD";
	// liczenie sredniego czasu oczekiwania
	awt = 0;
	for(int i = 0; i < time.size(); i++)
	{
		awt+=waiting_time.at(i);
	}

	awt = awt/time.size();
	std::cout << "Sredni czas oczekiwania: " << awt << "\n";

    dr.loadData(duration, time, akt_proces);
}

void sjf::draw(sf::RenderWindow &win)
{
    dr.draw(win,0);
}



