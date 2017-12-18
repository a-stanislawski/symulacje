//
//  robin.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 16.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "robin.hpp"


robin::robin() {
    // TODO Auto-generated constructor stub
    ready = 0;
    awt = 0;
    loadFromFile();
    algorithm();
    stop = 0;
}

robin::~robin() {
    // TODO Auto-generated destructor stub
}

void robin::loadFromFile()
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

void robin::sortByTime()
{
    
}

void robin::algorithm()
{
    int shortest = 0;
    int s_dur = 0;
    int current_time = 0;
    int wcr = 0;
    
    for(current_time = 0; ready < time.size(); current_time++)
    {
        //s_dur = 10000;

        for(int j = 0; j < time.size(); j++)
        {
            if(done.at(j) ) continue;

            if( time.at(j) > current_time)
            	{
            	if(wcr == 0) akt_proces.push_back(-1);
            		wcr = 0;
            	current_time++;
            	break;
            	}
            
            wcr = 1;
            duration.at(j)--;
            akt_proces.push_back(j);
            current_time++;
            if(duration.at(j) == 0)
            {
                ready++;
                done.at(j) = 1;
                nr.push_back(j);
                in.push_back(time.at(j));
                waiting_time.push_back(current_time + 1 - rem_dur.at(j) - time.at(j));
                out.push_back(current_time + 1);
            }
        }
        current_time--;
        
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
    
    dr.loadData(rem_dur, time, akt_proces);
}

void robin::draw(sf::RenderWindow &win)
{
    dr.draw(win, stop);
}

void robin::pause(bool p)
{
    stop = p;
}
