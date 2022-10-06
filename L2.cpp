#include <iostream>

using namespace std;

class Hero
{
    int hp, money;

    public:
        void set_hp(int the_hp)
        {
            hp = the_hp;
        }

        int get_hp()
        {
            return hp;
        }
};

class Slime
{
    protected:
        string color;
        int attack;
        int money;
        bool status = true;

    public:
        void set_slime(string the_color, int the_attack)
        {
            color = the_color;
            attack = the_attack;
        }
        void set_status(bool the_status)
        {
            status = the_status;
        }
        string get_color()
        {
            return color;
        }
        int get_attack()
        {
            return attack;
        }
        int get_money()
        {
            return money;
        }
        bool get_status()
        {
            return status;
        }
};

class Sword
{
    protected:
        string color;
    
    public:
        void set_color(string the_color)
        {
            color = the_color;
        }
        string get_color()
        {
            return color;
        }

};

class FireSlime : public Slime
{
    public:
        int fire_ball()
        {
            cout << "I'm gonna burn yo ass" << endl;
            return attack + 10;
        }
        void set_fire_slime()
        {
            color = "fire";
            attack = 10;
        }
};

class WaterSlime : public Slime
{
    public:
        int splash()
        {
            cout << "Get wet" << endl;
            return attack + 12;
        }
        void set_water_slime()
        {
            color = "water";
            attack = 13;
        }
};

class AirSlime : public Slime
{
    public:
        int air_cut()
        {
            cout << "GURIEGEDON" << endl;
            return attack + 20;
        }
        void set_air_slime()
        {
            color = "air";
            attack = 15;
        }
};

class EarthSlime : public Slime
{
    public:
        int earthquake()
        {
            cout << "EARTHQUAKEEEEE" << endl;
            return attack + 9;
        }
        void set_earth_slime()
        {
            color = "earth";
            attack = 4;
        }
};



int main(void)
{
    Hero hero;
    hero.set_hp(20);
    Sword sword;

    AirSlime air_slime;
    air_slime.set_air_slime();
    FireSlime fire_slime;
    fire_slime.set_fire_slime();
    WaterSlime water_slime;
    water_slime.set_water_slime();
    EarthSlime earth_slime;
    earth_slime.set_earth_slime();

    string our_color;

    cout << "YOU ARE A HERO THAT HAS TO DEFEAT 4 SLIMES" << endl;
    cout << "CHOOSE THE RIGHT ELEMENT TO DEFEAT A SLIME" << endl;
    cout << "air, fire, earth, water" << endl;
    cout << "Your HP: " << hero.get_hp() << endl;
    cout << endl;
    while (hero.get_hp() > 0 && earth_slime.get_status())
    {
        while (hero.get_hp() > 0 && air_slime.get_status())
        {
            cout << "YOU ARE AGAINST AIR SLIME, PREPARE YOURSELF" << endl;

            cout << "Choose element: ";
            cin >> our_color;
            sword.set_color(our_color);

            if (air_slime.get_color() == sword.get_color())
            {
                air_slime.set_status(false);
                cout << "Congratulations! you have dfeated this slime" << endl;
            }
            else
            {
                int taken_damage = air_slime.air_cut();
                hero.set_hp(hero.get_hp() - taken_damage);
                cout << "You've taken: " << taken_damage << endl;
                cout << "HP: " << hero.get_hp() << endl;
            }
        }

        while (hero.get_hp() > 0 && water_slime.get_status())
        {
            cout << "YOU ARE AGAINST WATER SLIME, PREPARE YOURSELF" << endl;

            cout << "Choose element: ";
            cin >> our_color;
            sword.set_color(our_color);

            if (water_slime.get_color() == sword.get_color())
            {
                water_slime.set_status(false);
                cout << "Congratulations! you have dfeated this slime" << endl;
            }
            else
            {
                int taken_damage = water_slime.splash();
                hero.set_hp(hero.get_hp() - taken_damage);
                cout << "You've taken: " << taken_damage << endl;
                cout << "HP: " << hero.get_hp() << endl;
            }
        }

        while (hero.get_hp() > 0 && fire_slime.get_status())
        {
            cout << "YOU ARE AGAINST FIRE SLIME, PREPARE YOURSELF" << endl;

            cout << "Choose element: ";
            cin >> our_color;
            sword.set_color(our_color);

            if (fire_slime.get_color() == sword.get_color())
            {
                fire_slime.set_status(false);
                cout << "Congratulations! you have dfeated this slime" << endl;
            }
            else
            {
                int taken_damage = fire_slime.fire_ball();
                hero.set_hp(hero.get_hp() - taken_damage);
                cout << "You've taken: " << taken_damage << endl;
                cout << "HP: " << hero.get_hp() << endl;
            }
        }

        while (hero.get_hp() > 0 && earth_slime.get_status())
        {
            cout << "YOU ARE AGAINST EARTH SLIME, PREPARE YOURSELF" << endl;

            cout << "Choose element: ";
            cin >> our_color;
            sword.set_color(our_color);

            if (earth_slime.get_color() == sword.get_color())
            {
                earth_slime.set_status(false);
                cout << "Congratulations! you have dfeated this slime" << endl;
            }
            else
            {
                int taken_damage = earth_slime.earthquake();
                hero.set_hp(hero.get_hp() - taken_damage);
                cout << "You've taken: " << taken_damage << endl;
                cout << "HP: " << hero.get_hp() << endl;
            }
        }

        if (hero.get_hp() < 0)
            cout << "YOU'RE DEAD" << endl;
        else
            cout << "YOU DEFEATED ALL THE SLIMES! NOICE!" << endl;
    }

    return 0;
}
