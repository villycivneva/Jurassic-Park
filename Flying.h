//
// Created by Velina on 28/04/2020.
//

#ifndef JURASSICPARK_FLYING_H
#define JURASSICPARK_FLYING_H


#include "Dinosaur.h"


/// This class **constructs a flying dinosaur**.
///
/// This is the class that inherits from Dinosaur class. It called derived class.
///
/// The variables(data members of the class, which ARE NOT in Dinosaur) are:
///
/// @arg Food **foodThatFlyingDinosaurEats** - this is the food that dinosaur eats. It's *enum variable* : **Grass**,**Meat** or **Fish**.
/// @arg static const char* food - this is static variable for food. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the food that dinosaur eats.
/// @arg Order **order** - the order of dinosaur. It's *enum variable* : **Order::Carnivorous**, **Order::Herbivorous**, **Order::Aqueous** or **Order::Flying**.
/// @arg static const char* _order - this is static variable for order. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the order of dinosaur.
class Flying : public Dinosaur{
public:

    ///This is the **default** constructor and **constructor with parameters** in one place.
    ///
    /// The default values of data members that the Flying inherits from Dinosaur are:
    ///
    /// @arg **dinosaurName** - The default name of dinosaur is *nullptr*;
    /// @arg **dinosaurGender** - The default gender of dinosaur is *Female*;
    /// @arg **era** - The default era is *Triassic*;
    /// @arg **typeOfDinosaur** - The default type of dinosaur is *nullptr*;
    ///
    ///The The default values of of data members of Flying are:
    ///
    /// @arg **foodThatFlyingDinosaurEats** - The default food is Fish;
    /// @arg **order** - The default order is Order::Flying;
    ///
    /// @param dinosaurName -> this is the name that you want to set to dinosaur;
    /// @param dinosaurGender -> this is the gender that your dinosaur is going to be(or he is going to decide when he grow up);
    /// @param era -> this is era of dinosaur;
    /// @param typeOfDinosaur -> this is the type that your dinosaur is going to be;
    /// @param foodThatFlyingDinosaurEats -> This is the food that we want out dinosaur to eat.
    /// @param order -> This is the order that we want.
    Flying(const char* = nullptr,Gender = Female, Era = Triassic,const char* = nullptr, Food = Fish, Order = Order::Flying);




    ///This is a mutator for the **foodThatFlyingDinosaurEats**.
    ///
    ///That function allow us to **change** the food that flying dinosaur eats.
    ///
    ///@param newFoodThatFlyingDinosaurEats -> This is the new food that flying dinosaur eats and we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setFoodThatFlyingDinosaurEats(Food);


    ///This is a mutator for the **order**.
    ///
    ///That function allow us to **change** the order of dinosaur.
    ///
    ///@param newOrder -> This is the new order of dinosaur that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setOrder(Order);



    ///This is accessor for the *foodThatFlyingDinosaurEats*.
    ///
    ///@returns Food, which is enum variable: It can be : **Grass**, **Meat** or **Fish**.
    ///@attention The accessor has **const** at the end of a function because the current Flying object that we return - doesn't change.
    Food getFoodThatFlyingDinosaurEats() const;


    ///This is accessor for the *order*.
    ///
    ///@returns Order, which is enum variable: It can be : **Carnivorous**, **Herbivorous**, **Aqueous**, **Flying**;
    ///@attention The accessor has **const** at the end of a function because the current Flying object that we return - doesn't change.
    Order getOrder() const;

    virtual void print() const;
private:
    Food foodThatFlyingDinosaurEats;
    Order order;
    static const char* const food[];
    static const char* const _order[];
};


#endif //JURASSICPARK_FLYING_H
