#include"Header.h"


class CaR : public traffic
{
private:

    int result;
    bool val = true;

public:

    int getRandomNumber()
    {
        if (val)
        {
            srand(time(NULL));
            val = false;
        }

        result = borderLeft + rand() % ((borderRight + 1) - borderLeft);

        return result;
    }


    void speed()
    {
        if (CarY > sc_height) //when the object crosses the lower end of the window
        {
            CarY = 0;
            CarX = getRandomNumber();
            score++;
        }

        else
            CarY = CarY + Carspeed;
    }

    friend class gameplay;

};



class TrucK : public traffic
{
private:

    int result;
    bool val = true;

public:

    int getRandomNumber()
    {
        if (val)
        {
            srand(time(NULL));
            val = false;
        }

        result = borderLeft + rand() % ((borderRight + 1) - borderLeft);

        return result;
    }


    void speed()
    {
        if (TruckY > sc_height) //when the object crosses the lower end of the window
        {
            TruckY = 0;
            TruckX = getRandomNumber();
            score++;
        }

        else
            TruckY = TruckY + Truckspeed;
    }

    friend class gameplay;

};



class Bike : public traffic
{
private:

    int result;
    bool val = true;

public:

    int getRandomNumber()
    {
        if (val)
        {
            srand(time(NULL));
            val = false;
        }

        int result = borderLeft + rand() % ((borderRight + 1) - borderLeft);

        return result;
    }


    void speed()
    {
        if (BikerY > sc_height) //when the object crosses the lower end of the window
        {
            BikerY = 0;
            BikerX = getRandomNumber();
            score++;
        }

        else
            BikerY = BikerY + Bikespeed;
    }

    friend class gameplay;

};



// this class act as a powerup in game
class AmbulancE : public traffic
{
private:

    int result;
    bool val = true;

public:

    int getRandomNumber()
    {
        if (val)
        {
            srand(time(NULL));
            val = false;
        }

        int result = borderLeft + rand() % ((borderRight + 1) - borderLeft);

        return result;
    }


    void speed()
    {
        if (AmbulanceY > sc_height) //when the object crosses the lower end of the window
        {
            AmbulanceY = 0;
            AmbulanceX = getRandomNumber();
            score++;
        }

        else
            AmbulanceY = AmbulanceY + Ambulancespeed;
    }

    friend class gameplay;

};

