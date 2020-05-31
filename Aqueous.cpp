//
// Created by Velina on 28/04/2020.
//

#include "Aqueous.h"

const char* const Aqueous::food[3] = { "Grass" , "Meat", "Fish" };
const char* const Aqueous::_order[4] = { "Carnivorous" , "Herbivorous", "Aqueous", "Flying"};


Aqueous::Aqueous(const char * dinosaurName, Gender dinosaurGender, Era era, const char * typeOfDinosaur, Food foodThatAqueousDinosaurEats, Order order)
        : Dinosaur(dinosaurName,dinosaurGender,era,typeOfDinosaur){
    setFoodThatAqueousDinosaurEats(foodThatAqueousDinosaurEats);
    setOrder(order);
}

void Aqueous::setFoodThatAqueousDinosaurEats(Food newFoodThatAqueousDinosaurEats) {
    this->foodThatAqueousDinosaurEats = newFoodThatAqueousDinosaurEats;
}

void Aqueous::setOrder(Order newOrder) {
    this->order = newOrder;
}

Food Aqueous::getFoodThatAqueousDinosaurEats() const {
    return this->foodThatAqueousDinosaurEats;
}

Order Aqueous::getOrder() const {
    return this->order;
}

void Aqueous::print() const {
    Dinosaur::print();
    std::cout<<"Food: "<<food[static_cast<int>(this->foodThatAqueousDinosaurEats)]<<std::endl;
    std::cout<<"Order: "<<_order[static_cast<int>(this->order)]<<std::endl;
}