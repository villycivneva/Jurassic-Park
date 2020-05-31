//
// Created by Velina on 29/04/2020.
//

#ifndef JURASSICPARK_CAGE_H
#define JURASSICPARK_CAGE_H

#include "Dinosaur.h"

enum Climate {Terrestrial, Air, Water};

/// This class **constructs a cage**.
///
/// In this cages we are going to collect the dinosaurs.
///
/// The variables(data members of the class) which are declared in Cage are:
///
/// @arg Climate **climate** - this is the climate in cage.
/// @arg static const char* const _climate - this is static variable for climate. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the climate in cage.
/// @arg Dinosaur* **dinosaursInCage** - a lot of dinosaurs from Dinosaur in cage.
/// @arg size_t **numberOfDinosaurs** - the number of dinosaurs in array *dinosaursInCage*.
/// @arg size_t **capacityOfCage** - the capacity of cage.
/// @arg int **sizeOfCage** - we have **3 options for cage**:
///
///         Small cage - 1 dinosaur
///         Middle cage - 3 dinosaurs
///         Large cage - 10 dinosaurs
///
/// @arg Era **eraOfDinosaursInCage** - the era of dinosaur in the cage. It's *enum variable* : **Triassic** , **Cretaceous**, **Jurassic**
/// @arg static const char* const _era - this is static variable for era. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the era of dinosaurs in the cage.
class Cage {
public:

    ///This is the **default** constructor.
    ///
    ///Default constructor is the constructor which does not take any argument. It has no parameters.
    ///
    ///@arg **climate** - The default climate in cage is *Air*.
    ///@arg **dinosaursInCage** - The default value of dinosaursInCage is *nullptr*;
    ///@arg **numberOfDinosaurs** - The default number of dinosaurs in array dinosaursInCage is 0;
    ///@arg **capacityOfCage** - The default capacity of cage is 1;
    ///@arg **sizeOfCage** - The default size of cage that we set is 1(for one dinosaur);
    ///@arg **eraOfDinosaursInCage** - The default era of dinosaurs in cage is *Triassic*;
    Cage() = default;


    ///This is the constructor with parameters.
    ///
    ///It has 3 parameters, which are making a cage:
    ///
    ///@param climate -> this is the climate in cage.
    ///@param eraOfDinosaursInCage -> this is the era of dinosaurs in cage.
    ///@param sizeOfCage -> this is the size of cage(it is 1,3 or 10);
    ///@see Cage() Cage(const Cage&)
    Cage(Climate,Era, int);


    ///This is copy constructor.
    ///
    ///With this constructor we make copies of the cages.
    Cage(const Cage&);


    /// This is copy assignment operator.
    ///@note And assignment operator is called when an already initialized object is assigned a new value from another existing object.
    Cage&operator=(const Cage&);


    ///This is the **destructor**.
    ///
    /// When a class contains a pointer to memory allocated in class(as we have here for **dinosaursInCage**);
    ~Cage();



    ///This is a mutator for the **climate**.
    ///
    ///That function allow us to **change** the climate in cages.
    ///
    ///@param newClimate -> This is the new climate in cage, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setClimate(Climate);


    ///This is a mutator for the **dinosaursInCage**.
    ///
    ///This function cleans whatever it was in the *dinosaursInCage* array and then allocates memory with *capacityOfCage* size.
    ///
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setDinosaursInCage();


    ///This is a mutator for the **eraOfDinosaursInCage**.
    ///
    ///That function allow us to **change** the era of dinosaurs in cages.
    ///
    ///@param newEraOfDinosaursInCage -> This is the new era, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setEraOfDinosaursInCage(Era);


    ///This is a mutator for the **numberOfDinosaurs**.
    ///
    ///That function allow us to **change** the number of dinosaurs in *dinosaursInCage*.
    ///
    ///@param newNumberOfDinosaursInCage -> This is the new number of dinosaurs, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setNumberOfDinosaurs(size_t);

    ///This is a mutator for the **capacityOfCage**.
    ///
    ///That function allow us to **change** the capacity of *dinosaursInCage*.
    ///
    ///@param newCapacityOfCage -> This is the new capacity, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setCapacityOfCage(size_t);


    ///This is a mutator for the **capacityOfCage**.
    ///
    ///That function allow us to **change** the capacity of cage(1,3 or 10).
    ///
    ///@param newSizeOfCage -> This is the new size of cage, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setSizeOfCage(int);




    ///This is accessor for the *climate*.
    ///
    ///@returns Climate, which is enum variable: It can be : **Terrestrial**, **Air**, **Water**.
    ///@attention The accessor has **const** at the end of a function because the current Cage object that we return - doesn't change.
    Climate getClimate() const;


    ///This is accessor for the *dinosaursInGage*.
    ///
    ///@returns dinosaurs in cage.
    ///@attention The accessor has **const** at the end of a function because the current Cage object that we return - doesn't change.
    Dinosaur* getDinosaursInCage() const;


    ///This is accessor for the *eraOfDinosaursInCage*.
    ///
    ///@returns Era, which is enum variable: It can be : **Triassic** , **Cretaceous** or **Jurassic**;
    ///@attention The accessor has **const** at the end of a function because the current Cage object that we return - doesn't change.
    Era getEraOfDinosaursInCage() const;


    ///This is accessor for the *numberOfDinosaurs*.
    ///
    ///@returns the number of dinosaurs in array *dinosaursInCage*.
    ///@attention The accessor has **const** at the end of a function because the current Cage object that we return - doesn't change.
    size_t getNumberOfDinosaurs() const;


    ///This is accessor for the *capacityOfCage*.
    ///
    ///@returns the capacity of array *dinosaursInCage*.
    ///@attention The accessor has **const** at the end of a function because the current Cage object that we return - doesn't change.
    size_t getCapacityOfCage() const;


    ///This is accessor for the *sizeOfCage*.
    ///
    ///@returns the size of cage.
    ///@attention The accessor has **const** at the end of a function because the current Cage object that we return - doesn't change.
    int getSizeOfCage() const;





    ///This function adds a dinosaur into the cage;
    ///
    ///@note More details about the function, You may see the comments in code :)
    bool addDinosaurInTheCage(const Dinosaur&);


    ///This function removes a dinosaur from the cage;
    ///
    ///@note More details about the function, You may see the comments in code :)
    bool removeDinosaurFromTheCage(const char*);



    ///In this function we store the information about the dinosaurs in binary file **InformationAboutTheCages.bin**.
    void storeInBinaryFile();

    /// This function prints all the information about the dinosaurs.
    ///
    ///@attention The function print() const has **const** at the end of a function because the things that we return - doesn't change.
    void print() const;

private:
    Climate climate{Air};
    static const char* const _climate[];

    Dinosaur* dinosaursInCage{nullptr};
    size_t numberOfDinosaurs{0};
    size_t capacityOfCage{1};
    int sizeOfCage{1};

    Era eraOfDinosaursInCage{Triassic};
    static const char* const _era[];

    void resize();
};


#endif //JURASSICPARK_CAGE_H
