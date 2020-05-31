#include <iostream>
#include "Dinosaur.h"
#include "Carnivorous.h"
#include "Herbivorous.h"
#include "Aqueous.h"
#include "Flying.h"
#include "Cage.h"
#include <fstream>

int main() {
    //Dinosaur dinosaur1("Rexa",Gender::Female,Era::Jurassic,"Tiranosavyr");
    //Dinosaur dinosaur2("Rex",Gender::Male,Era::Jurassic,"Tiranosavyr");
    //Dinosaur dinosaur3("Re",Gender::Female,Era::Jurassic,"Tiranosavyr");

    /*dinosaur1.storeInBinaryFile();
    dinosaur2.storeInBinaryFile();
    dinosaur3.storeInBinaryFile();
     */

    class Carnivorous carnivorous("Hello1",Gender::Male,Era::Triassic,"pteradoktil");
    carnivorous.print();
    //class Flying flying1("Hello2",Gender::Female,Era::Triassic,"kor",Food::Fish,Order::Carnivorous);
    //class Flying flying2("Hello3",Gender::Male,Era::Triassic,"pter",Food::Fish,Order::Carnivorous);



   // Cage cage(Climate::Air,Era::Triassic,3);


    //cage.addDinosaurInTheCage(carnivorous);
    //cage.addDinosaurInTheCage(flying1);
    //cage.addDinosaurInTheCage(flying2);

    //cage.storeInBinaryFile();
    //cage.print();

    return 0;
}
