#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;
using namespace sf;

//values declared and initialised to the variables

int sc_width = 800;
int sc_height = 600;
int borderLeft = 160;
int borderRight = 650;

string stringscore = "";
int score = 0;


double Carspeed = 7.5;
double Truckspeed = 5;
double Bikespeed = 8.5;
double Ambulancespeed = 10;

// texture and sprites declared
Texture background, racer, car, truck, biker, ambulance, gameover;
Sprite Background, Background1, Racer, Car, Truck, Biker, Ambulance, Gameover;

double RacerX, RacerY, CarX, CarY = 0, TruckX, TruckY = -400, BikerX, BikerY = -700, AmbulanceX, AmbulanceY = -3000;

// game window initialised
RenderWindow window(VideoMode(sc_width, sc_height), "CAR DRIVING GAME");

Event event;

Sound GameSound;



// class of player game object
class player
{
private:

    int racerWidth = 40;
    int racerHeight = 70;

public:

    // function for positioning the racer car
    void set_pos()
    {
        RacerX = sc_width / 2;
        RacerY = sc_height - racerHeight;
    }


    // functions for moving game object with keys
    void move_left()
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            if (RacerX > borderLeft)
                RacerX = RacerX - 10;
        }
    }


    void move_right()
    {
        if (event.key.code == sf::Keyboard::Right)
        {
            if (RacerX < borderRight)
                RacerX = RacerX + 10;
        }
    }

    void move_up()
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            if (RacerY > 0)
                RacerY = RacerY - 10;
        }
    }

    void move_down()
    {
        if (event.key.code == sf::Keyboard::Down)
        {
            if (RacerY < sc_height - 70)
                RacerY = RacerY + 10;
        }
    }
};



// class of traffic containing virtual functions generating random mumber and speed
class traffic
{
    virtual int getRandomNumber()
    {
        bool first = true;

        if (first)
        {
            srand(time(NULL));
            first = false;
        }

        int result = borderLeft + rand() % ((borderRight + 1) - borderLeft);

        return result;
    }

    virtual void speed()
    {
        if (CarY > sc_height) //when the object crosses the lower end of the window
        {
            CarY = 0;
            CarX = getRandomNumber();
            score++;
        }

        else
            CarY = CarY + 0.1;
    }

};


