#pragma once
#include <iostream>
#include <string>
using namespace std;

class Travoyadni 
{
protected:
    int weight;
    bool life;
public:
    Travoyadni(int w, bool isAlive = true) : weight(w), life(isAlive) {}
    virtual ~Travoyadni() {}

    virtual void eatGrass() = 0;

    int getWeight() const { return weight; }
    bool isAlive() const { return life; }
    void setAlive(bool state) { life = state; }
    virtual string getName() const = 0;
};

class Xishnik 
{
protected:
    int power;
public:
    Xishnik(int p) : power(p) {}
    virtual ~Xishnik() {}

    virtual void eat(Travoyadni* herbivore) = 0;

    int getPower() const { return power; }
    virtual string getName() const = 0;
};

class Wildebeest : public Travoyadni 
{
public:
    Wildebeest();
    void eatGrass();
    string getName() const;
};

class Bison : public Travoyadni 
{
public:
    Bison();
    void eatGrass();
    string getName() const;
};

class Lion : public Xishnik 
{
public:
    Lion();
    void eat(Travoyadni* herbivore);
    string getName() const;
};

class Wolf : public Xishnik 
{
public:
    Wolf();
    void eat(Travoyadni* herbivore);
    string getName() const;
};

class Continent 
{
public:
    virtual ~Continent() {}
    virtual Travoyadni* createTravoyadni() const = 0;
    virtual Xishnik* createXishnik() const = 0;
    virtual string getName() const = 0;
};

class Africa : public Continent 
{
public:
    Travoyadni* createTravoyadni() const;
    Xishnik* createXishnik() const;
    string getName() const;
};

class NorthAmerica : public Continent 
{
public:
    Travoyadni* createTravoyadni() const;
    Xishnik* createXishnik() const;
    string getName() const;
};

class AnimalWorld 
{
private:
    Travoyadni** herbivores;
    int herbivoreCount;

    Xishnik** carnivores;
    int carnivoreCount;

public:
    AnimalWorld(const Continent& continent);
    ~AnimalWorld();

    void Mealstrava();
    void OxotaXishnik(); 
};