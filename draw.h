//
//  draw.h
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "eventHandler.hpp"

#ifndef DRAW_H_
#define DRAW_H_

class draw {
	sf::Font font;
    int chosen;
    int highlighted;
    int klik;
    int choice;
    int stop;
    int fps;
    
public:
	draw();
	void window(sf::RenderWindow &win, eventHandler &ev);
	virtual ~draw();
	void handleEvent(sf::Event &event, eventHandler &ev);
	void rect(int w, int h, int x, int y, bool color, sf::RenderWindow &win);
    void menu(int col, sf::RenderWindow &win, eventHandler &ev);
    int wybor();
    int pause();
};

#endif /* DRAW_H_ */
