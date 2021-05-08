#pragma once
#include "Taslar.h"
#include"Board.h"
#include<SFML/Graphics.hpp>
using namespace sf;
class Move
{

 public:
	 Taslar ts;
	 Board boar;
	 bool ValidPiyonHareketi(std::tuple<sf::Sprite, std::string> SelectedImage, std::pair<int, int>xxx)
	 {
		 int c = (std::get<0>(SelectedImage).getPosition().x) / 80;
		 int r = (std::get<0>(SelectedImage).getPosition().y) / 80;

		 if (std::get<1>(SelectedImage) == "bp")
		 {
			 if (boar.tahta[r - 2][c] == "e" && xxx.second + 2 == r && r == 6 && xxx.first == c && boar.tahta[r - 1][c] == "e")
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r - 2][c] = "bp";
				 return true;
			 }
			 if (boar.tahta[r - 1][c] == "e" && xxx.second + 1 == r && xxx.first == c)
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r - 1][c] = "bp";
				 return true;

			 }
			 if (boar.tahta[r - 1][c - 1][0] == 's' && xxx.second + 1 == r && xxx.first + 1 == c)
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r - 1][c - 1] = "bp";
				 return true;
			 }
			 if (xxx.first - 1 == c && xxx.second + 1 == r && boar.tahta[r - 1][c + 1][0] == 's')
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r - 1][c + 1] = "bp";
				 return true;
			 }

		 }
		 if (std::get<1>(SelectedImage) == "sp")
		 {
			 if (boar.tahta[r + 2][c] == "e" && xxx.second - 2 == r && r == 1 && xxx.first == c)
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r + 2][c] = "sp";
				 return true;
			 }
			 if (boar.tahta[r + 1][c] == "e" && xxx.second - 1 == r && xxx.first == c)
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r + 1][c] = "sp";
				 return true;

			 }
			 if (boar.tahta[r + 1][c + 1][0] == 'b' && xxx.second - 1 == r && xxx.first - 1 == c)
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r - 1][c - 1] = "sp";
				 return true;
			 }
			 if (xxx.first + 1 == c && xxx.second - 1 == r && boar.tahta[r + 1][c - 1][0] == 'b')
			 {
				 boar.tahta[r][c] = "e";
				 boar.tahta[r + 1][c - 1] = "sp";
				 return true;
			 }


		 }
		 if (std::get<1>(SelectedImage) == "bfil")
		 {

			 if (abs(c - xxx.first) == abs(r - xxx.second))
			 {
				 int sayac = 0;
				 int a = c;
				 int b = r;
				 if (c > xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b--;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }

						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bfil";
					 return true;
				 }
				 if (c < xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b++;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bfil";
					 return true;
				 }
				 if (c > xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b++;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }

						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }
					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bfil";
					 return true;
				 }
				 if (c < xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b--;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bfil";
					 return true;
				 }


			 }

		 }
		 if (std::get<1>(SelectedImage) == "sfil")
		 {

			 if (abs(c - xxx.first) == abs(r - xxx.second))
			 {
				 int sayac = 0;
				 int a = c;
				 int b = r;
				 if (c > xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b--;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "sfil";
					 return true;
				 }
				 if (c < xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b++;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "sfil";
					 return true;
				 }
				 if (c > xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b++;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "sfil";
					 return true;
				 }
				 if (c < xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b--;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }

						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }
					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "sfil";
					 return true;
				 }


			 }

		 }
		 if (std::get<1>(SelectedImage) == "bk")
		 {

			 if (c == xxx.first || r == xxx.second)
			 {
				 int a = c;
				 int b = r;
				 int sayac = 0;
				 if (c == xxx.first)
				 {
					 if (r > xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b--;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bk";
						 return true;
					 }
					 if (r < xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b++;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bk";
						 return true;
					 }
				 }
				 if (r == xxx.second)
				 {
					 if (c > xxx.first)
					 {
						 while (a != xxx.first)
						 {
							 a--;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bk";
						 return true;
					 }
					 if (c < xxx.first)
					 {

						 while (a != xxx.first)
						 {
							 a++;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bk";
						 return true;
					 }
				 }

			 }

		 }
		 if (std::get<1>(SelectedImage) == "sk")
		 {

			 if (c == xxx.first || r == xxx.second)
			 {
				 int a = c;
				 int b = r;
				 int sayac = 0;
				 if (c == xxx.first)
				 {
					 if (r > xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b--;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "sk";
						 return true;
					 }
					 if (r < xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b++;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "sk";
						 return true;
					 }
				 }
				 if (r == xxx.second)
				 {
					 if (c > xxx.first)
					 {
						 while (a != xxx.first)
						 {
							 a--;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "sk";
						 return true;
					 }
					 if (c < xxx.first)
					 {

						 while (a != xxx.first)
						 {
							 a++;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "sk";
						 return true;
					 }
				 }

			 }

		 }
		 if (std::get<1>(SelectedImage) == "bat")
		 {
			 if (boar.tahta[xxx.second][xxx.first][0]!='b')
			 {
				 if (abs(r-xxx.second)==2&&abs(c-xxx.first)==1 || abs(r - xxx.second) == 1 && abs(c - xxx.first) == 2)
				 {
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bat";
					  
					 return true;
				 }
			 }
		 }
		 if (std::get<1>(SelectedImage) == "sat")
		 {
			 if (boar.tahta[xxx.second][xxx.first][0] != 's')
			 {
				 if (abs(r - xxx.second) == 2 && abs(c - xxx.first) == 1 || abs(r - xxx.second) == 1 && abs(c - xxx.first) == 2)
				 {
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "sat";

					 return true;
				 }
			 }
		 }
		 if (std::get<1>(SelectedImage) == "skral")
		 {
			 if (abs(c - xxx.first) == 0 || abs(c - xxx.first) == 0 && abs(r - xxx.second) == 0 || abs(r - xxx.second) == 0)
			 {
				 if (boar.tahta[xxx.second][xxx.first][0] != 's')
				 {
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bkral";

					 return true;

				 }

			 }
			 if (abs(c - xxx.first) == 1 && abs(r - xxx.second) == 1)
			 {

				 if (boar.tahta[xxx.second][xxx.first][0] != 's')
				 {
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bkral";

					 return true;

				 }

			 }
		 }
		 if (std::get<1>(SelectedImage) == "bkral")
		 {
			 if (abs(c-xxx.first)==0|| abs(c - xxx.first) == 0 && abs(r - xxx.second) == 0 || abs(r - xxx.second) == 0)
			 {
				 if (boar.tahta[xxx.second][xxx.first][0]!='b')
				 {
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bkral";

					 return true;

				 }
				 
			 }
			 if (abs(c-xxx.first)==1&& abs(r-xxx.second)==1)
			 {

				 if (boar.tahta[xxx.second][xxx.first][0] != 'b')
				 {
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bkral";

					 return true;

				 }

			 }
		 }
		 if (std::get<1>(SelectedImage) == "bvezir")
		 {
			 if (c == xxx.first || r == xxx.second)
			 {
				 int a = c;
				 int b = r;
				 int sayac = 0;
				 if (c == xxx.first)
				 {
					 if (r > xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b--;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bvezir";
						 return true;
					 }
					 if (r < xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b++;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bvezir";
						 return true;
					 }
				 }
				 if (r == xxx.second)
				 {
					 if (c > xxx.first)
					 {
						 while (a != xxx.first)
						 {
							 a--;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bvezir";
						 return true;
					 }
					 if (c < xxx.first)
					 {

						 while (a != xxx.first)
						 {
							 a++;
							 if (boar.tahta[b][a][0] == 'b')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 's')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "bvezir";
						 return true;
					 }
				 }

			 }
			 if (abs(c - xxx.first) == abs(r - xxx.second))
			 {
				 int sayac = 0;
				 int a = c;
				 int b = r;
				 if (c > xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b--;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }

						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bvezir";
					 return true;
				 }
				 if (c < xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b++;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bvezir";
					 return true;
				 }
				 if (c > xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b++;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }

						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }
					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bvezir";
					 return true;
				 }
				 if (c < xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b--;
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 's')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "bvezir";
					 return true;
				 }


			 }
		 
		 }
		 if (std::get<1>(SelectedImage) == "svezir")
		 {
			 if (c == xxx.first || r == xxx.second)
			 {
				 int a = c;
				 int b = r;
				 int sayac = 0;
				 if (c == xxx.first)
				 {
					 if (r > xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b--;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "svezir";
						 return true;
					 }
					 if (r < xxx.second)
					 {
						 while (b != xxx.second)
						 {
							 b++;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "svezir";
						 return true;
					 }
				 }
				 if (r == xxx.second)
				 {
					 if (c > xxx.first)
					 {
						 while (a != xxx.first)
						 {
							 a--;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "svezir";
						 return true;
					 }
					 if (c < xxx.first)
					 {

						 while (a != xxx.first)
						 {
							 a++;
							 if (boar.tahta[b][a][0] == 's')
							 {
								 return false;
							 }

							 if (boar.tahta[b][a][0] == 'b')
							 {
								 sayac++;
							 }
							 if (sayac > 1)
							 {
								 return false;
							 }

						 }
						 boar.tahta[r][c] = "e";
						 boar.tahta[xxx.second][xxx.first] = "svezir";
						 return true;
					 }
				 }

			 }
			 if (abs(c - xxx.first) == abs(r - xxx.second))
			 {
				 int sayac = 0;
				 int a = c;
				 int b = r;
				 if (c > xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b--;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }

						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "svezir";
					 return true;
				 }
				 if (c < xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b++;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "svezir";
					 return true;
				 }
				 if (c > xxx.first && r < xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a--;
						 b++;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }

						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }
					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "svezir";
					 return true;
				 }
				 if (c < xxx.first && r > xxx.second)
				 {
					 while (a != xxx.first && b != xxx.second)
					 {
						 a++;
						 b--;
						 if (boar.tahta[b][a][0] == 's')
						 {
							 return false;
						 }
						 if (boar.tahta[b][a][0] == 'b')
						 {
							 sayac++;
						 }
						 if (sayac > 1)
						 {
							 return false;
						 }

					 }
					 boar.tahta[r][c] = "e";
					 boar.tahta[xxx.second][xxx.first] = "svezir";
					 return true;
				 }


			 }

		 }
		 return false;
	 }

};

