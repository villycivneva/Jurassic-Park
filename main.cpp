#include <iostream>
#include "Dinosaur.h"
#include "Carnivorous.h"
#include "Herbivorous.h"
#include "Aqueous.h"
#include "Flying.h"
#include "Cage.h"
#include <fstream>

int main() {
    Dinosaur dinosaur1("Rexa",Gender::Female,Era::Jurassic,"Tiranosavyr");
    Dinosaur dinosaur2("Rex",Gender::Male,Era::Jurassic,"Tiranosavyr");

    dinosaur1.storeInBinaryFile();
    dinosaur2.storeInBinaryFile();

    class Carnivorous carnivorous("Carcho",Gender::Male,Era::Triassic,"pteradoktil");
    carnivorous.print();

    Cage cage(Climate::Air,Era::Triassic,3);


    cage.addDinosaurInTheCage(carnivorous);
    cage.addDinosaurInTheCage(flying1);

    cage.storeInBinaryFile();
    cage.print();

    return 0;
}
