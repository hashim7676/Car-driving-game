#include"Header1.h"




// main gameplay class
class gameplay : public player
{
private:

    double BackgroundY1 = 0;
    double BackgroundY2 = -600;

public:

    //function for moving the road
    void backgroundmovement()
    {
        Background.setPosition(0, BackgroundY1);
        Background1.setPosition(0, BackgroundY2);

        if (BackgroundY2 > 0)
        {
            BackgroundY1 = 0;
            BackgroundY2 = BackgroundY1 - 500;
        }

        BackgroundY1 += 3.0;
        BackgroundY2 += 3.0;
    }

    //function for loading textures and loading images in game window
    int load_texture()
    { 
        if (!background.loadFromFile("cars/background.png")) return EXIT_FAILURE;
        if (!racer.loadFromFile("cars/racer.png")) return EXIT_FAILURE;
        if (!car.loadFromFile("cars/car.png")) return EXIT_FAILURE;
        if (!truck.loadFromFile("cars/truck.png")) return EXIT_FAILURE;
        if (!biker.loadFromFile("cars/biker.png")) return EXIT_FAILURE;
        if (!ambulance.loadFromFile("cars/ambulance.png")) return EXIT_FAILURE;

        Background.setTexture(background);
        Background1.setTexture(background);
        Racer.setTexture(racer);
        Car.setTexture(car);
        Truck.setTexture(truck);
        Biker.setTexture(biker);
        Ambulance.setTexture(ambulance);
    }


    void menu()
    {
        Texture menu;
        menu.loadFromFile("cars/formula1.png");
        Sprite Menu(menu);

        Font myfont;
        myfont.loadFromFile("font/xirod.ttf");
        Text start("Start Game!", myfont, 60);
        start.setPosition(110, 100);

        Vector2i v;

        window.clear();
        window.draw(Menu);
        window.draw(start);
        window.display();

        while (window.isOpen())
        {
            v = Mouse::getPosition(window);

            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            if ((Mouse::isButtonPressed(Mouse::Left) || Mouse::isButtonPressed(Mouse::Right))
                && v.x > 110 && v.x < 700 && v.y > 100 && v.y < 165)
                break;
        }
    }


    //function for gameover
    int gameOver()
    {
        Texture troll;

        if (!troll.loadFromFile("cars/troll.png")) return EXIT_FAILURE;
        //if (!troll.loadFromFile("cars/trol.png")) return EXIT_FAILURE;

        Sprite Troll(troll);
        Troll.setPosition(40, 0);

        SoundBuffer gameOver;
        gameOver.loadFromFile("sound/crash.wav");
        Sound GameOver;
        GameOver.setBuffer(gameOver);
        GameOver.play();

        //font for loading score in game
        Font myfont;
        myfont.loadFromFile("font/xirod.ttf");
        stringscore = "SCORE : " + to_string(score);

        Text text(stringscore, myfont, 30);
        text.setPosition(270, 230);

        Text g_over("Game Over!", myfont, 60);
        g_over.setPosition(130, 90);

        Text playagain("Play Again", myfont, 40);
        playagain.setPosition(210, 450);

        Vector2i v;

        window.clear();
        window.draw(Troll);
        window.draw(g_over);
        window.draw(text);
        window.draw(playagain);
        window.display();

        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            v = Mouse::getPosition(window);

            if ((Mouse::isButtonPressed(Mouse::Left) || Mouse::isButtonPressed(Mouse::Right))
                && v.x > 210 && v.x < 600 && v.y > 450 && v.y < 490)
            {
                score = 0;
                CarY = 0;
                TruckY = -400;
                BikerY = -700;
                AmbulanceY = -3000;

                set_pos();

                GameSound.play();
                GameSound.setLoop(true);

                break;
            }
        }
    }


    //function for detecting collision when two sprites interact
    void collision_detection()
    {
        if (((RacerX >= (CarX - 30)) && (RacerX <= (CarX + 30)))
            && ((RacerY >= (CarY - 30)) && (RacerY) <= (CarY + 30)))
        {
            GameSound.stop();
            gameOver();
        }

        if (((RacerX >= (TruckX - 50)) && (RacerX <= (TruckX + 50)))
            && ((RacerY >= (TruckY - 50)) && (RacerY) <= (TruckY + 50)))
        {
            GameSound.stop();
            gameOver();
        }

        if (((RacerX >= (BikerX - 30)) && (RacerX <= (BikerX + 30)))
            && ((RacerY >= (BikerY - 30)) && (RacerY) <= (BikerY + 30)))
        {
            GameSound.stop();
            gameOver();
        }

        // if statement for increasing score if collide with ambulance
        if (((RacerX >= (AmbulanceX - 30)) && (RacerX <= (AmbulanceX + 30)))
            && ((RacerY >= (AmbulanceY - 30)) && (RacerY) <= (AmbulanceY + 30)))
            score = score + 4;
    }


    void game_play()
    {
        SoundBuffer gameSoundBuffer;
        gameSoundBuffer.loadFromFile("sound/tokyodrift.wav");
        GameSound.setBuffer(gameSoundBuffer);

        Font myfont;
        myfont.loadFromFile("font/xirod.ttf");

        load_texture();

        //traffic* bptr[4];
        CaR object_car;
        Bike object_bike;
        TrucK object_truck;
        AmbulancE object_ambulance;

        //bptr[0] = &object_car;
        //bptr[1] = &object_bike;
        //bptr[2] = &object_truck;
        //bptr[3] = &object_ambulance;


        set_pos();
        CarX = object_car.getRandomNumber();
        TruckX = object_truck.getRandomNumber();
        BikerX = object_bike.getRandomNumber();
        AmbulanceX = object_ambulance.getRandomNumber();

        menu();

        GameSound.play();
        GameSound.setLoop(true);

        //loop for counting score, setting position for game objects
        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed)
                {
                    move_left();
                    move_right();
                    move_up();
                    move_down();
                }
            }


            stringscore = "SCORE : " + to_string(score);
            Text text(stringscore, myfont, 15);
            text.setPosition(5, 0);


            //Set car position
            Racer.setPosition(RacerX, RacerY);
            Car.setPosition(CarX, CarY);
            Truck.setPosition(TruckX, TruckY);
            Biker.setPosition(BikerX, BikerY);
            Ambulance.setPosition(AmbulanceX, AmbulanceY);


            backgroundmovement();
            object_car.speed();
            object_bike.speed();
            object_truck.speed();
            object_ambulance.speed();

            //if statements for level of difficulty
            if (score > 25 && score < 70)
            {
                Carspeed = 13;
                Truckspeed = 7.5;
                Bikespeed = 13.5;
            }

            if (score > 70 && score < 150)
            {
                Carspeed = 15.5;
                Truckspeed = 8;
                Bikespeed = 15;
            }

            if (score > 150)
            {
                Carspeed = 16.5;
                Truckspeed = 9;
                Bikespeed = 16.5;
            }

            load_texture();
            collision_detection();

            window.clear();
            window.draw(Background);
            window.draw(Background1);
            window.draw(Racer);
            window.draw(Car);
            window.draw(Truck);
            window.draw(Biker);
            window.draw(Ambulance);
            window.draw(text);
            window.display();
        }
    }

};



int main()
{
    gameplay game;

    game.game_play();

}