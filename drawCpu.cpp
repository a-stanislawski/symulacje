//
//  drawCpu.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 17.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "drawCpu.hpp"

drawCpu::drawCpu()
{
    if (!font.loadFromFile("LiberationMono-Bold.ttf"))
    {
      //  return EXIT_FAILURE;
    }
    a = 0;
    d = 0;
    idle = 0;
}

void drawCpu::loadData(std::vector<int> dur, std::vector<int> t, std::vector<int> akt, std::vector<int> pr)
{
	int a = 1;
	if(pr.empty()) a = 0;
    for(int i = 0; i < dur.size(); i++)
    {
        time.push_back(t.at(i));
        remaining.push_back(dur.at(i));
        duration.push_back(dur.at(i));
        if(a) priority.push_back(pr.at(i));
    }
    for(int i = 0; i < akt.size(); i++)
    {
        change.push_back(akt.at(i));
    }

}

void drawCpu::bar(int height, int width, int time, int x, int y, sf::RenderWindow &win)
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(x,y);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setFillColor(sf::Color(220,220,220));
    
    win.draw(rect);
}

void drawCpu::colorBar(int height, int width, int time, int x, int y, sf::RenderWindow &win)
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(x,y);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setFillColor(sf::Color::Red);
    
    win.draw(rect);
}

void drawCpu::activeBar(int height, int width, int time, int x, int y, sf::RenderWindow &win)
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(x,y);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setFillColor(sf::Color::Green);
    
    win.draw(rect);
}

void drawCpu::draw(sf::RenderWindow &win, int stop)
{
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(10);
    text.setColor(sf::Color::Black);
    for(int i = 0; i < time.size(); i++)
    {
        
        if(a < time.at(i)) bar(20*duration.at(i), 7, 0, 50+10*i, 300 - 20*duration.at(i), win);
        else
        {
            activeBar(20*duration.at(i), 7, 0, 50+10*i, 300 - 20*duration.at(i), win);
            if( a == change.size()) colorBar(20*remaining.at(i), 7, 0, 50+10*i, 300 - 20*remaining.at(i), win);
            else if( i == change.at(a)) colorBar(20*remaining.at(i)-2*d, 7, 0, 50+10*i, 300 - 20*remaining.at(i)+2*d, win);
            else colorBar(20*remaining.at(i), 7, 0, 50+10*i, 300 - 20*remaining.at(i), win);
        }
        if(!priority.empty())
        	{
        	text.setString(std::to_string(priority.at(i)));
        	text.setPosition(50+10*i,305);
        	win.draw(text);
        	}
    }
    
    if(a < change.size())
    {
        if(d == 10)
        {
            if(change.at(a) != -1) remaining.at(change.at(a))--;
            else idle++;
            d = 0;
            a++;
        }
        if(!stop) d++;
    }
    

    text.setCharacterSize(15);
    text.setString("Sredni czas: xxx");
    text.setPosition(300, 400);
    win.draw(text);
    text.setString("Czas procesora: " + std::to_string(a));
    text.setPosition(300, 450);
    win.draw(text);
    text.setString("Idle time: " + std::to_string(idle));
    text.setPosition(300, 500);
    win.draw(text);
    
}
