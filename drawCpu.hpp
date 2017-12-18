//
//  drawCpu.hpp
//  symulacje
//
//  Created by Adam Stanislawski on 17.12.2017.
//  Copyright © 2017 Adam Stanislawski. All rights reserved.
//

#ifndef drawCpu_hpp
#define drawCpu_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>

class drawCpu
{
    sf::Font font;
    std::vector<int> remaining;
    std::vector<int> duration;
    std::vector<int> time;
    std::vector<int> change;
    std::vector<int> priority;
    int a;
    int d;
    int idle; // idle time procesora
public:
    drawCpu();
    void loadData(std::vector<int> dur, std::vector<int> t, std::vector<int> akt, std::vector<int> pr = {});
    void loadAddData(int awt);
    void draw(sf::RenderWindow &win, int stop);
    
    void bar(int height, int width, int time, int x, int y, sf::RenderWindow &win);
    void colorBar(int height, int width, int time, int x, int y, sf::RenderWindow &win);
    void activeBar(int height, int width, int time, int x, int y, sf::RenderWindow &win);
};

#endif /* drawCpu_hpp */
