#include "animal.h"

Wildebeest::Wildebeest() : Travoyadni(120, true) {}

void Wildebeest::eatGrass() 
{
    if (!life) 
    {
        cout << "Антилопа Гну не может есть - она мертва.\n";
        return;
    }
    weight += 10;
    cout << "Антилопа Гну поела траву. Вес: " << weight << "\n";
}

string Wildebeest::getName() const 
{
    return "Антилопа Гну";
}

Bison::Bison() : Travoyadni(250, true) {}

void Bison::eatGrass() 
{
    if (!life) 
    {
        cout << "Бизон не может есть - он мёртв.\n";
        return;
    }
    weight += 10;
    cout << "Бизон поел траву. Вес: " << weight << "\n";
}

string Bison::getName() const 
{
    return "Бизон";
}

Lion::Lion() : Xishnik(150) {}

void Lion::eat(Travoyadni* herbivore) 
{
    if (!herbivore || !herbivore->isAlive()) 
    {
        cout << "Лев не может поймать цель.\n";
        return;
    }

    if (power > herbivore->getWeight()) 
    {
        power += 10;
        herbivore->setAlive(false);
        cout << "Лев успешно поймал (" << herbivore->getName() << "). Сила льва: " << power << "\n";
    } 
    else 
    {
        power -= 10;
        cout << "Лев не справился с (" << herbivore->getName() << "). Сила льва уменьшена: " << power << "\n";
    }
}

string Lion::getName() const 
{
    return "Лев";
}

Wolf::Wolf() : Xishnik(100) {}

void Wolf::eat(Travoyadni* herbivore) 
{
    if (!herbivore || !herbivore->isAlive()) 
    {
        cout << "Волк не может поймать цель.\n";
        return;
    }

    if (power > herbivore->getWeight()) 
    {
        power += 10;
        herbivore->setAlive(false);
        cout << "Волк успешно поймал (" << herbivore->getName() << "). Сила волка: " << power << "\n";
    } 
    else 
    {
        power -= 10;
        cout << "Волк не справился с (" << herbivore->getName() << "). Сила волка уменьшена: " << power << "\n";
    }
}

string Wolf::getName() const 
{
    return "Волк";
}

Travoyadni* Africa::createTravoyadni() const 
{
    return new Wildebeest();
}

Xishnik* Africa::createXishnik() const 
{
    return new Lion();
}

string Africa::getName() const 
{
    return "Африка";
}

Travoyadni* NorthAmerica::createTravoyadni() const 
{
    return new Bison();
}

Xishnik* NorthAmerica::createXishnik() const 
{
    return new Wolf();
}

string NorthAmerica::getName() const
{
    return "Северная Америка";
}

AnimalWorld::AnimalWorld(const Continent& continent) 
{
    herbivoreCount = 1;
    carnivoreCount = 1;

    herbivores = new Travoyadni*[herbivoreCount];
    carnivores = new Xishnik*[carnivoreCount];

    herbivores[0] = continent.createTravoyadni();
    carnivores[0] = continent.createXishnik();

    cout << "Континент: " << continent.getName() << endl;
}

AnimalWorld::~AnimalWorld() 
{
    for (int i = 0; i < herbivoreCount; ++i) 
    {
        delete herbivores[i];
    }
    delete[] herbivores;

    for (int i = 0; i < carnivoreCount; ++i) 
    {
        delete carnivores[i];
    }
    delete[] carnivores;
}

void AnimalWorld::Mealstrava() 
{
    cout << "\nПитание травоядных \n";
    for (int i = 0; i < herbivoreCount; ++i) 
    {
        herbivores[i]->eatGrass();
    }
}

void AnimalWorld::OxotaXishnik() 
{
    cout << "\nПитание плотоядных \n";
    for (int i = 0; i < carnivoreCount; ++i) 
    {
        for (int j = 0; j < herbivoreCount; ++j) 
        {
            if (herbivores[j]->isAlive()) 
            {
                carnivores[i]->eat(herbivores[j]);
                break;
            }
        }
    }
}

int main() {
    Africa africa;
    AnimalWorld africaWorld(africa);
    africaWorld.Mealstrava();
    africaWorld.OxotaXishnik();

    cout << "-" << endl;

    NorthAmerica northAmerica;
    AnimalWorld americaWorld(northAmerica);
    americaWorld.Mealstrava();
    americaWorld.OxotaXishnik();

    return 0;
}