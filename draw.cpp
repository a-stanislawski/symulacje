//
//  draw.cpp
//  symulacje
//
//  Created by Adam Stanislawski on 15.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#include "draw.h"
#include <iostream>

draw::draw() {
    chosen = 0;
    highlighted = 0;
    klik = 0;
    if (!font.loadFromFile("LiberationMono-Bold.ttf"))
    {
       // return EXIT_FAILURE;
    }
    choice = 1;
    stop = 0;
    fps = 15;

}

draw::~draw() {
}

void draw::rect(int w, int h, int x, int y, bool color, sf::RenderWindow &win)
{
	sf::RectangleShape rect(sf::Vector2f(w,h));
	rect.setPosition(x,y);
	rect.setOutlineThickness(1);
	rect.setOutlineColor(sf::Color::Black);

	if(color) rect.setFillColor(sf::Color::Green);
	win.draw(rect);
}

void draw::handleEvent(sf::Event &event, eventHandler &ev)
{
    ev.handleEvent(event);
    
    highlighted = ev.isHighlighted();
    klik = ev.nr_menu();
    if(choice == ev.poz_menu()) klik = 0;
    else choice = ev.poz_menu();
    stop = ev.pause();

    if(fps != ev.getFPS())
    {
    	fps = ev.getFPS();

    }
}

void draw::menu(int col, sf::RenderWindow &win, eventHandler &ev)
{
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(15);
    
    //pozycje podmenu
    if(col != 1) {
    	for(int i = 1; i <= 4; i++)
    		rect(150,30,(col-1)*100,30*i,(ev.isHighlighted() == 10*col + i) ? 1 :0, win);
    }
    else
    {
    	for(int i = 1; i <= 6; i++)
    		rect(150,30,(col-1)*100,30*i,(ev.isHighlighted() == 10*col + i) ? 1 :0, win);
    }
    //tekst podmenu
    if(col == 1)
    {
        text.setString("FCFS");
        text.setPosition(15, 35);
        win.draw(text);
        text.setString("SJF");
        text.setPosition(15, 65);
        win.draw(text);
        text.setString("SJF (z wyw.)");
        text.setPosition(15, 95);
        win.draw(text);
        text.setString("Round-robin");
        text.setPosition(15, 125);
        win.draw(text);
        text.setString("Priority");
        text.setPosition(15, 155);
        win.draw(text);
        text.setString("Pr... (z wyw.)");
        text.setPosition(15, 185);
        win.draw(text);
    }
    else if(col == 2)
    {
        text.setString("Zapisz");
        text.setPosition(115, 35);
        win.draw(text);
        text.setString("Wczytaj");
        text.setPosition(115, 65);
        win.draw(text);
        text.setString("Zamknij");
        text.setPosition(115, 95);
        win.draw(text);
        text.setString("----");
        text.setPosition(115, 125);
        win.draw(text);
    }
    else if(col == 3)
    {
        text.setString((fps == 15) ? "* 15fps" : "15 fps");
        text.setPosition(215, 35);
        win.draw(text);
        text.setString((fps == 30) ? "* 30fps" : "30 fps");
        text.setPosition(215, 65);
        win.draw(text);
        text.setString((fps == 45) ? "* 45fps" : "45 fps");
        text.setPosition(215, 95);
        win.draw(text);
        text.setString((fps == 60) ? "* 60fps" : "60 fps");
        text.setPosition(215, 125);
        win.draw(text);
    }
}

void draw::window(sf::RenderWindow &win, eventHandler &ev)
{
	win.setFramerateLimit(fps);
	rect(800,30,0,0,0, win);
    rect(100,30,0,0,(ev.isHighlighted() == 1) ? 1 : 0, win);
	rect(100,30,100,0,(ev.isHighlighted() == 2) ? 1 : 0, win);
	rect(100,30,200,0,(ev.isHighlighted() == 3) ? 1 : 0, win);
    
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(15);
    text.setColor(sf::Color::Blue);

   
    if(!ev.pause())
    {
    sf::CircleShape triangle(15, 3);
    triangle.setPosition(785, 0);
    triangle.setFillColor(sf::Color::Blue);
    triangle.rotate(90);
    win.draw(triangle);
    } else
    {
    sf::RectangleShape rect(sf::Vector2f(10,20));
    rect.setPosition(755,5);
    rect.setOutlineThickness(1);
    rect.setFillColor(sf::Color::Red);
    win.draw(rect);
    
    sf::RectangleShape rect2(sf::Vector2f(10,20));
    rect2.setPosition(770,5);
    rect2.setOutlineThickness(1);
    rect2.setFillColor(sf::Color::Red);
    win.draw(rect2);
    }
    
    if(ev.nr_menu() == 1)
    {
        menu(1, win, ev);
    }
    if(ev.nr_menu() == 2)
    {
        menu(2, win, ev);
    }
    if(ev.nr_menu() == 3)
    {
        menu(3, win, ev);
    }
    text.setString("Algorytm");
    text.setPosition(15, 5);
    win.draw(text);

    text.setString("Dane...");
    text.setPosition(115, 5);
    win.draw(text);

    text.setString("FPS");
    text.setPosition(215, 5);
    win.draw(text);
}

int draw::wybor()
{
    return choice;
}

int draw::pause()
{
    return stop;
}



