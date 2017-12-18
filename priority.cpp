//
//  priority.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 18.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "priority.h"

priority::priority() {
	// TODO Auto-generated constructor stub
	awt = 0;
	loadFromFile();
	algorithm();

	/*for(int i = 0; i < time.size(); i++)
	{
		nr.push_back(i);
	}*/

}

priority::~priority() {
	// TODO Auto-generated destructor stub
}

void priority::loadFromFile()
{
	std::ifstream plik ("example.txt");

	std::string line, line_time, line_duration, line_priority;
	if (plik.is_open())
	{
	   while ( getline (plik,line) )
	   {
	     std::cout << line << '\n';
	     std::size_t pos = line.find(" ");
	     line_time = line.substr(0,line.size() - pos );
	     std::cout << line << "\n";

	     line_duration = line.substr(pos+1);
	     pos = line_duration.find(" ");
	     std::cout << line_duration << "\n";

	     line_priority = line_duration.substr(pos+1);
	     line_duration = line_duration.substr(0,line_duration.size()-pos);

	     time.push_back(std::stoi(line_time));
	     duration.push_back(std::stoi(line_duration));
         remaining.push_back(std::stoi(line_duration));
         pr.push_back(std::stoi(line_priority));
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
		std::cout << time.at(i) << "+" << duration.at(i) << "+" << pr.at(i) << "\n";
	}
}

void priority::sortByTime()
{

}

void priority::algorithm()
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
				if(pr.at(j) >= s_dur) continue;
				else
					{
					s_dur = pr.at(j);
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
	}

	// liczenie sredniego czasu oczekiwania
	awt = 0;
	for(int i = 0; i < time.size(); i++)
	{
		awt+=waiting_time.at(i);
	}

	awt = awt/time.size();
	std::cout << "Sredni czas oczekiwania: " << awt << "\n";

    dr.loadData(duration, time, akt_proces, pr);
}

void priority::draw(sf::RenderWindow &win)
{
    dr.draw(win,0);
}
