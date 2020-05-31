//
// Created by Velina on 30/03/2020.
//

#include "Carnivorous.h"
#include "Dinosaur.h"

const char* const Carnivorous::food[3] = { "Grass" , "Meat", "Fish" };
const char* const Carnivorous::_order[4] = { "Carnivorous" , "Herbivorous", "Aqueous", "Flying"};

Carnivorous::Carnivorous(const char * dinosaurName, Gender dinosaurGender, Era era, const char * typeOfDinosaur)
        : Dinosaur(dinosaurName,dinosaurGender,era,typeOfDinosaur){
    this->foodThatCarnivorousDinosaurEats = Food::Meat;
    this->order = Order::Carnivorous;
}


Food Carnivorous::getFoodOfCarnivorousDinosaur() const {
    return this->foodThatCarnivorousDinosaurEats;
}

Order Carnivorous::getOrder() const {
    return this->order;
}

void Carnivorous::print() const {
    Dinosaur::print();
    std::cout<<"Food: "<<food[static_cast<int>(this->foodThatCarnivorousDinosaurEats)]<<std::endl;
    std::cout<<"Order: "<<_order[static_cast<int>(this->order)]<<std::endl;
}
