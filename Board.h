#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<string>
#include <array>

class Board
{ 
public:
    std::string tahta[8][8] = {
    {"sk","sat","sfil","svezir","skral","sfil","sat","sk"},
    {"sp","sp","sp","sp","sp","sp","sp","sp"},
    {"e","e","e","e","e","e","e","e"},
    {"e","e","e","e","e","e","e","e"},
    {"e","e","e","e","e","e","e","e"},
    {"e","e","e","e","e","e","e","e"},
    {"bp","bp","bp","bp","bp","bp","bp","bp"},
    {"bk","bat","bfil","bvezir","bkral","bfil","bat","bk"}

    };
    std::vector<std::pair<int, int>> koordinatlar;
    
   
    sf::RectangleShape dortgen;
   
   
    std::pair<int,int>  dikkoordinat(sf::Vector2f mouse_pos)
    {
         int xkoord = std::floor(mouse_pos.x/80);
         int ykoord = std::floor(mouse_pos.y / 80);
         std::pair<int, int>kordinatlar;
         kordinatlar.first = xkoord;
         kordinatlar.second = ykoord;
         return kordinatlar;
    
    }

    Board()
    {
       
        dortgen.setSize(sf::Vector2f(80, 80));
        
        sf::Color renk;
        dortgen.setFillColor(renk.White);
		int x = 0;
		int y = 0;
		int px = 0;
		int py = 80;

        while (y != 640)
        {
            while (y != 640) {
                while (x != 640)
                {
                    koordinatlar.push_back(std::pair<int, int >(x, y));

                    x += 160;

                }
                y += 160;
                x = 0;
            }

            y = 80;
            x = 80;
            while ((y != 880))
            {
                while (x != 720)
                {
                    koordinatlar.push_back(std::pair<int, int >(x, y));

                    x += 160;

                }
                x = 80;
                y += 160;
            }
            y = 640;
        }

        

    }
};

