//
//  eventHandler.hpp
//  symulacje
//
//  Created by Adam Stanislawski on 17.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#ifndef eventHandler_hpp
#define eventHandler_hpp


#include <SFML/Graphics.hpp>
#include <stdio.h>

class eventHandler
{
    int menu;
    int stop;
    int choice;
    int rwx;
    int klik;
    int highlighted;
    int fps;
public:
    eventHandler();
    void handleEvent(sf::Event &event);
    int czyKlik(sf::Event &event, int x1, int x2, int y1, int y2);
    int isOver(sf::Event &event, int x1, int x2, int y1, int y2);
    int poz_menu();
    int nr_menu();
    int pause();
    int isHighlighted();
    int getFPS();
};

#endif /* eventHandler_hpp */
