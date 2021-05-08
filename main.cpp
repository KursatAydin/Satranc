
#include"Taslar.h"
#include"Board.h"
#include"Move.h";
using namespace sf;


int main() 
{ 
    int x=0;
    int y=0;
   
    sf::Event ev;
    Board brd;
    Move move;
    Taslar  ts;
    std::vector <std::tuple<sf::Sprite, std::string>> butuntaslar{ ts.sk,ts.sat,ts.sfil,ts.svezir,ts.skral,ts.sfil,ts.sat,ts.sk,ts.sp,ts.sp,ts.sp,ts.sp,ts.sp,ts.sp,ts.sp,ts.sp,ts.bp,ts.bp,ts.bp,ts.bp,ts.bp,ts.bp,ts.bp,ts.bp,ts.bk,ts.bat,ts.bfil,ts.bvezir,ts.bkral,ts.bfil,ts.bat,ts.bk };

       int i=0;
        for (int row = 0; row < 8; row++)
        {
            
            for (int col = 0; col < 8; col++)
            {
                   if (brd.tahta[row][col] == std::get<1>(butuntaslar[i]))
                   {
                       std::get<0>(butuntaslar[i]).setPosition(col * 80, row * 80);
                           i++;


                   }
            }    
          
        }

    bool sonuc = false;
    std::tuple<Sprite, std::string>* SelectedImage = nullptr;
    sf::RenderWindow w(sf::VideoMode(640, 640), "Chess", sf::Style::Default);
    w.setFramerateLimit(30);
    sf::RectangleShape dortgen2;
    dortgen2.setFillColor(Color::Transparent);
    dortgen2.setSize(sf::Vector2f(75, 75));
    dortgen2.setOutlineThickness(5);
    dortgen2.setOutlineColor(Color::Red);
   
    
    //Game Loop*********************************************************

    while (w.isOpen())
    {
      

        
        w.clear(Color(160, 82, 45));
     
        while (w.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                w.close();
            }
            
            if (ev.type == sf::Event::MouseButtonReleased)
            {
              
                if(ev.mouseButton.button==Mouse::Left)
                {
                    auto mouse_pos = sf::Mouse::getPosition(w); // Mouse position relative to the window
                    auto translated_pos = w.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
                  
                    for (int  i = 0; i < butuntaslar.size(); i++)
                    {
                        if (std::get<0>(butuntaslar[i]).getGlobalBounds().contains(translated_pos))
                        {
                            SelectedImage = &butuntaslar[i];
                            dortgen2.setPosition(std::get<0>(butuntaslar[i]).getPosition().x, std::get<0>(butuntaslar[i]).getPosition().y);
                            sonuc = true;

                        }
                    }
                    
                }



            }
            if (ev.type == sf::Event::MouseButtonPressed)
            {
                if (ev.mouseButton.button == Mouse::Right)
                {
                    dortgen2.setPosition(1000, 1000);
                    auto mouse_po = sf::Mouse::getPosition(w); // Mouse position relative to the window
                    auto translated_p = w.mapPixelToCoords(mouse_po);
                    auto xxx = brd.dikkoordinat(translated_p);
                    
                    if(move.ValidPiyonHareketi(*SelectedImage, xxx))
                    { 

                        std::get<0>(*SelectedImage).setPosition(xxx.first * 80, xxx.second * 80);
                        for (int  i = 0; i <butuntaslar.size(); i++)
                        {
                            if (std::get<0>(butuntaslar[i]).getPosition()==std::get<0>(*SelectedImage).getPosition() && std::get<1>(butuntaslar[i])[0]!=std::get<1>(*SelectedImage)[0])
                            {
                                std::get<0>(butuntaslar[i]).setPosition(1000, 10000);
                            }
                        }
                    
                    }
                    
                    
                }



            }


        }
        for (int i = 0; i < brd.koordinatlar.size() - 1; i++)
        {

            brd.dortgen.setPosition(Vector2f(brd.koordinatlar[i].first, brd.koordinatlar[i].second));
            w.draw(brd.dortgen);

        }
        for (int  i = 0; i <butuntaslar.size(); i++)
        {
            w.draw(std::get<0>(butuntaslar[i]));

        }
      
        if (sonuc) { w.draw(dortgen2); }
       
        w.display();
        
        
    }
    return 0;

    
}
	


