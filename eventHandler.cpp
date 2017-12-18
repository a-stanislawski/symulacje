//
//  eventHandler.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 17.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "eventHandler.hpp"

eventHandler::eventHandler()
{
    menu = 0;
    stop = 0;
    highlighted = 0;
    klik = 0;
    choice = 0;
    rwx = 0;
    fps = 15;
}

void eventHandler::handleEvent(sf::Event &event)
{
    // najechanie na pozycje menu
    if(isOver(event, 0, 100, 0, 30)) highlighted = 1; // 1 menu
    else if(isOver(event, 100, 200, 0, 30)) highlighted = 2; // 2 menu
    else if(isOver(event, 200, 300, 0, 30)) highlighted = 3; // 3 menu
    else if(isOver(event, 0, 150, 30, 60) && klik == 1) highlighted = 11;
    else if(isOver(event, 0, 150, 60, 90) && klik == 1) highlighted = 12;
    else if(isOver(event, 0, 150, 90, 120) && klik == 1) highlighted = 13;
    else if(isOver(event, 0, 150, 120, 150) && klik == 1) highlighted = 14;
    else if(isOver(event, 0, 150, 150, 180) && klik == 1) highlighted = 15;
    else if(isOver(event, 0, 150, 180, 210) && klik == 1) highlighted = 16;
    else if(isOver(event, 100, 250, 30, 60) && klik == 2) highlighted = 21;
    else if(isOver(event, 100, 250, 60, 90) && klik == 2) highlighted = 22;
    else if(isOver(event, 100, 250, 90, 120) && klik == 2) highlighted = 23;
    else if(isOver(event, 100, 250, 120, 150) && klik == 2) highlighted = 24;
    else if(isOver(event, 200, 350, 30, 60) && klik == 3) highlighted = 31;
    else if(isOver(event, 200, 350, 60, 90) && klik == 3) highlighted = 32;
    else if(isOver(event, 200, 350, 90, 120) && klik == 3) highlighted = 33;
    else if(isOver(event, 200, 350, 120, 150) && klik == 3) highlighted = 34;
    else highlighted = 0;
    
    
    // klik menu
    if(czyKlik(event, 0, 100, 0, 30)) klik = (klik != 1) ? 1 : 0;
    if(czyKlik(event, 100, 200, 0, 30)) klik = (klik != 2) ? 2 : 0;
    if(czyKlik(event, 200, 300, 0, 30)) klik = (klik != 3) ? 3 : 0;
    
    // klik pauza
    if(czyKlik(event, 750, 800, 0, 30)) stop = !stop;
    
    // klik algorytm
    for(int i = 1; i <= 6; i++)
    {
        if(czyKlik(event, 0, 150, 30*i, 30*i+30) && klik == 1)
        {
            klik = 0;
            choice = i;
        }
        if(czyKlik(event, 100, 250, 30*i, 30*i+30) && klik == 2)
        {
            klik = 0;
            rwx = i;
        }
        if(czyKlik(event, 200, 350, 30*i, 30*i+30) && klik == 3)
        {
            klik = 0;
            fps = 15*i;
        }
    }
    
    if(rwx == 1)
    {
        rwx = 0;
        system("open -a \"TextEdit\" ~/Desktop/file1.txt");
    }
}

int eventHandler::getFPS()
{
	return fps;
}

int eventHandler::czyKlik(sf::Event &event, int x1, int x2, int y1, int y2)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if( event.mouseButton.x > x1 && event.mouseButton.x < x2)
            if( event.mouseButton.y > y1 && event.mouseButton.y < y2)
                return 1;
    }
    return 0;
}

int eventHandler::isOver(sf::Event &event, int x1, int x2, int y1, int y2)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if( event.mouseMove.x > x1 && event.mouseMove.x < x2)
            if( event.mouseMove.y > y1 && event.mouseMove.y < y2)
                return 1;
    }
    return 0;
}

int eventHandler::poz_menu()
{
    return choice;
}

int eventHandler::nr_menu()
{
    return klik;
}

int eventHandler::pause()
{
    return stop;
}

int eventHandler::isHighlighted()
{
    return highlighted;
}
