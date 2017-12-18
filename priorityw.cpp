//
//  priorityw.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 18.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//
#include "priorityw.h"


priorityw::priorityw() {
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

priorityw::~priorityw() {
	// TODO Auto-generated destructor stub
}

void priorityw::loadFromFile()
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
		     rem_dur.push_back(std::stoi(line_duration));
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

void priorityw::sortByTime()
{

}

void priorityw::algorithm()
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
			if(pr.at(j) >= s_dur) continue;
			else
			{
			s_dur = pr.at(j);
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

    dr.loadData(remaining, time, akt_proces, pr);
}

void priorityw::draw(sf::RenderWindow &win)
{
    dr.draw(win,0);
}

