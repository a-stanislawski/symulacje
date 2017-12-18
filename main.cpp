//
//  main.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "fifo.h"
#include "sjf.h"
#include "sjfw.h"
#include "draw.h"
#include "robin.hpp"
#include "priority.h"
#include "priorityw.h"
#include "eventHandler.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Symulacje");
    window.setFramerateLimit(15);
    
    fifo f;
    sjf s;
    sjfw w;
    robin r;
    draw d;
    priority pr;
    priorityw prw;
    eventHandler ev;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            r.pause(d.pause());

            d.handleEvent(event, ev);
        }
        
        window.clear(sf::Color(220,220,220));
        if(d.wybor() == 1) f.draw(window);
        if(d.wybor() == 2) s.draw(window);
        if(d.wybor() == 3) w.draw(window);
        if(d.wybor() == 4) r.draw(window);
        if(d.wybor() == 5) pr.draw(window);
        if(d.wybor() == 6) prw.draw(window);
        //pw.draw(window);
        d.window(window, ev);
        
        window.display();
    }

    return 0;
}
