#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<string>
#include<tuple>
class Taslar
{

public:
	sf::Texture siyah_piyon;
	sf::Texture siyah_fil;
	sf::Texture siyah_kale;
	sf::Texture siyah_at;
	sf::Texture siyah_vezir;
	sf::Texture siyah_sah;


	sf::Image beyaz_piyonn;
	sf::Texture  beyaz_piyon;
	sf::Texture beyaz_kale;
	sf::Texture beyaz_at;
	sf::Texture beyaz_fil;
	sf::Texture beyaz_sah;
	sf::Texture beyaz_vezir;
	sf::Texture yol;


	std::tuple<sf::Sprite, std::string> sp;
	std::tuple<sf::Sprite, std::string> bp;
	std::tuple<sf::Sprite, std::string> bk;

		 std::tuple<sf::Sprite, std::string> sk;
	 std::tuple<sf::Sprite, std::string> bfil;
		 std::tuple<sf::Sprite, std::string> sfil;
		 std::tuple<sf::Sprite, std::string> bat;
		 std::tuple<sf::Sprite, std::string> sat;
		 std::tuple<sf::Sprite, std::string> bvezir;
		 std::tuple<sf::Sprite, std::string> svezir;
		 std::tuple<sf::Sprite, std::string> bkral;
		 std::tuple<sf::Sprite, std::string> skral;
	sf::Sprite sp1;
	sf::Sprite bp1;
	sf::Sprite bk1;
	sf::Sprite sk1;
	sf::Sprite bfil1;
	sf::Sprite sfil1;
	sf::Sprite bat1;
	sf::Sprite sat1;
	sf::Sprite bvezir1;
	sf::Sprite svezir1;
	sf::Sprite bkral1;
	sf::Sprite skral1;
	
	Taslar() 
	{
		
		if (!siyah_piyon.loadFromFile("piyon4.png"))
		{
			std::cout << "Hata";
			system("pause");

		} 
		sp1.setTexture(siyah_piyon);
		std::get<0>(sp) = sp1;
		std::get<1>(sp) = "sp";
	

		if (!beyaz_piyon.loadFromFile("beyazpiyon.png"))
		{
			std::cout << "Hata";
			system("pause");

		}
		bp1.setTexture(beyaz_piyon);
		
		std::get<0>(bp) = bp1;
		std::get<1>(bp) = "bp";

		if (!beyaz_kale.loadFromFile("beyazkale.png"))
		{
			std::cout << "Hata";
			system("pause");

		}
		bk1.setTexture(beyaz_kale);
		std::get<0>(bk) = bk1;
		std::get<1>(bk) = "bk";
		if (!siyah_kale.loadFromFile("siyahkale.png"))
		{
			std::cout << "Hata";
			system("pause");

		}
		sk1.setTexture(siyah_kale);
		std::get<0>(sk) = sk1;
		std::get<1>(sk) = "sk";


		if (!beyaz_at.loadFromFile("beyazat.png"))
		{
			std::cout << "Hata";
			system("pause");

		}
		bat1.setTexture(beyaz_at);
		
		std::get<0>(bat) = bat1;
		std::get<1>(bat) = "bat";



		if (!siyah_at.loadFromFile("siyahat.png"))
		{
			std::cout << "Hata";
			system("pause");

		}
		sat1.setTexture(siyah_at);
		std::get<0>(sat) = sat1;
		std::get<1>(sat) = "sat";
		if (!beyaz_fil.loadFromFile("beyazfil.png"))
		{
			std::cout << "Hata";
			system("pause");

		}

		bfil1.setTexture(beyaz_fil);
		std::get<0>(bfil) = bfil1;
		std::get<1>(bfil) = "bfil";

		if (!beyaz_vezir.loadFromFile("beyazvezir.png"))
		{
			std::cout << "Hata";
			system("pause");

		}

		bvezir1.setTexture(beyaz_vezir);
		std::get<0>(bvezir) = bvezir1;
		std::get<1>(bvezir) = "bvezir";

		if (!beyaz_sah.loadFromFile("beyazsah.png"))
		{
			std::cout << "Hata";
			system("pause");

		}
		
		bkral1.setTexture(beyaz_sah);
		std::get<0>(bkral) = bkral1;
		std::get<1>(bkral) = "bkral";
		if (!siyah_fil.loadFromFile("siyahfil.png"))
		{
			std::cout << "Hata";
			system("pause");

		}

		sfil1.setTexture(siyah_fil);
		std::get<0>(sfil) = sfil1;
		std::get<1>(sfil) = "sfil";
		if (!siyah_vezir.loadFromFile("siyahvezir.png"))
		{
			std::cout << "Hata";
			system("pause");

		}

		svezir1.setTexture(siyah_vezir);
		std::get<0>(svezir) = svezir1;
		std::get<1>(svezir) = "svezir";
		if (!siyah_sah.loadFromFile("siyahsah.png"))
		{
			std::cout << "Hata";
			system("pause");

		}
		skral1.setTexture(siyah_sah);
		std::get<0>(skral) = skral1;
		std::get<1>(skral) = "skral";
	


	}
	
	
};

