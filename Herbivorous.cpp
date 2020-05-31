//
// Created by Velina on 28/04/2020.
//

#include "Herbivorous.h"

const char* const Herbivorous::food[3] = { "Grass" , "Meat", "Fish" };
const char* const Herbivorous::_order[4] = { "Carnivorous" , "Herbivorous", "Aqueous", "Flying"};


Herbivorous::Herbivorous(const char * dinosaurName, Gender dinosaurGender, Era era, const char * typeOfDinosaur)
        : Dinosaur(dinosaurName,dinosaurGender,era,typeOfDinosaur){
    this->foodThatHerbivorousDinosaurEats = Food::Grass;
    this->order = Order::Herbivorous;
}

Food Herbivorous::getFoodOfHerbivorousDinosaur() const {
    return this->foodThatHerbivorousDinosaurEats;
}

Order Herbivorous::getOrder() const {
    return this->order;
}

void Herbivorous::print() const {
    Dinosaur::print();
    std::cout<<"Food: "<<food[static_cast<int>(this->getFoodOfHerbivorousDinosaur())]<<std::endl;
    std::cout<<"Order: "<<_order[static_cast<int>(this->getOrder())]<<std::endl;
}

