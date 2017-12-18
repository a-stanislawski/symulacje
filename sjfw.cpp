//
//  sjfw.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "sjfw.h"

sjfw::sjfw() {
	// TODO Auto-generated constructor stub
	ready = 0;
	awt = 0;
	loadFromFile();
	algorithm();
    if (!font.loadFromFile("LiberationMono-Bold.ttf"))
    {
      //  return EXIT_FAILURE;
    }
}

sjfw::~sjfw() {
	// TODO Auto-generated destructor stub
}

void sjfw::loadFromFile()
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
	     rem_dur.push_back(std::stoi(line_duration));
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

void sjfw::sortByTime()
{

}

void sjfw::algorithm()
{
	int shortest = 0;
	int s_dur = 0;
	int current_time = 0;
	int wpr = 0; // cyz wykonano chociaz raz petle

	for(current_time = 0; ready < time.size(); current_time++)
	{
		s_dur = 10000;


		for(int j = 0; j < time.size() ; j++)
		{
			if( done.at(j) ) continue;
			if( time.at(j) > current_time) break;
			wpr = 1;
			if(duration.at(j) >= s_dur) continue;
			else
			{
			s_dur = duration.at(j);
			shortest = j;
			}
		}
		if(wpr == 0)
		{
			current_time++;
			akt_proces.push_back(-1);
			continue;
		}
		wpr = 0;
		duration.at(shortest)--;
        akt_proces.push_back(shortest);
		if(duration.at(shortest) == 0)
		{
		ready++;
		nr.push_back(shortest);

		in.push_back(time.at(shortest));
		waiting_time.push_back(current_time + 1 - rem_dur.at(shortest) - time.at(shortest));

		//current_time+=duration.at(shortest);
		out.push_back(current_time + 1);
		done.at(shortest) = 1;
		}

	}


	// wyswietlanie wynikow algorytmu
	std::cout << "Nr\tcome\tdone\twait\n";
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

    dr.loadData(remaining, time, akt_proces);
}

void sjfw::draw(sf::RenderWindow &win)
{
    dr.draw(win,0);
}

