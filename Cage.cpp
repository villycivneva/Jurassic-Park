//
// Created by Velina on 29/04/2020.
//

#include "Cage.h"
#include <cassert>
#include <cstring>
#include <fstream>

const char* const Cage::_climate[3] = {"Terrestrial", "Air", "Water"};
const char* const Cage::_era[3] = {"Triassic" , "Cretaceous", "Jurassic"};


Cage::Cage(Climate climate, Era eraOfDinosaursInCage, int sizeOfCage){
    setClimate(climate);
    setEraOfDinosaursInCage(eraOfDinosaursInCage);
    setDinosaursInCage();
    setSizeOfCage(sizeOfCage);
}

Cage::Cage(const Cage & other) {
    setClimate(other.climate);
    setEraOfDinosaursInCage(other.eraOfDinosaursInCage);
    setDinosaursInCage();
    setCapacityOfCage(other.capacityOfCage);
    setNumberOfDinosaurs(other.numberOfDinosaurs);
    setSizeOfCage(other.sizeOfCage);
}

Cage & Cage::operator=(const Cage & other) {
    if(this!=&other){
        delete[] this->dinosaursInCage;

        setClimate(other.climate);
        setEraOfDinosaursInCage(other.eraOfDinosaursInCage);
        setDinosaursInCage();
        setCapacityOfCage(other.capacityOfCage);
        setSizeOfCage(other.sizeOfCage);
        setNumberOfDinosaurs(other.numberOfDinosaurs);
    }
    return *this;
}

Cage::~Cage() {
    delete[] this->dinosaursInCage;
    this->dinosaursInCage = nullptr;
}

void Cage::setClimate(Climate newClimate) {
    this->climate = newClimate;
}

void Cage::setDinosaursInCage() {
    delete [] this->dinosaursInCage;
    this->dinosaursInCage = new Dinosaur[capacityOfCage];
}

void Cage::setEraOfDinosaursInCage(Era newEraOfDinosaursInCage) {
    this->eraOfDinosaursInCage = newEraOfDinosaursInCage;
}

void Cage::setNumberOfDinosaurs(size_t newNumberOfDinosaursInCage) {
    this->numberOfDinosaurs = newNumberOfDinosaursInCage;
}

void Cage::setCapacityOfCage(size_t newCapacityOfCage) {
    this->capacityOfCage = newCapacityOfCage;
}

void Cage::setSizeOfCage(int newSizeOfCage) {
    if(newSizeOfCage == 1 || newSizeOfCage == 3 || newSizeOfCage == 10 ){
        this->sizeOfCage = newSizeOfCage;
    } else{
        std::cout<<"Invalid input!"<<std::endl;
        exit(1);
    }
}

Climate Cage::getClimate() const {
    return this->climate;
}

Dinosaur * Cage::getDinosaursInCage() const {
    return this->dinosaursInCage;
}

Era Cage::getEraOfDinosaursInCage() const {
    return this->eraOfDinosaursInCage;
}

size_t Cage::getCapacityOfCage() const {
    return this->capacityOfCage;
}

size_t Cage::getNumberOfDinosaurs() const {
    return this->numberOfDinosaurs;
}

int Cage::getSizeOfCage() const {
    return this->sizeOfCage;
}

void Cage::print() const {
    std::cout<<"Climate: "<<_climate[static_cast<int>(this->climate)]<<std::endl;
    std::cout<<"Dinosaurs: ";
    for(int i = 0; i< numberOfDinosaurs;i++){
        getDinosaursInCage()[i].print();
    }
    std::cout<<std::endl;
    std::cout<<"Era: "<<_era[static_cast<int>(this->eraOfDinosaursInCage)]<<std::endl;
    std::cout<<"Size: "<< sizeOfCage<<std::endl;
}

bool Cage::addDinosaurInTheCage(const Dinosaur& newDinosaur) {
    // Here we check if the number of dinosaurs are equal to the size of cage.
    if(numberOfDinosaurs == this->sizeOfCage){
        // We return false because the cage is full and we don't have place for another dinosaur.
        return false;
    }
    this->dinosaursInCage[this->numberOfDinosaurs++] = newDinosaur;
    if(numberOfDinosaurs == capacityOfCage){
        //with this function we doubled the capacity of cage;
        resize();
    }
    return true;
}

bool Cage::removeDinosaurFromTheCage(const char* theNameOfDinosaurWhoWantsToRemove) {
    if(numberOfDinosaurs != 0){ // If we have any dinosaurs in the cage
        Dinosaur* tmp = new Dinosaur[capacityOfCage];
        int index = 0;
        for(int i = 0; i < this->numberOfDinosaurs;i++){
            if(strcmp(dinosaursInCage[i].getDinosaurName(),
                    theNameOfDinosaurWhoWantsToRemove) != 0){
                // We move the dinosaurs with different from "theNameOfDinosaurWhoWantsToRemove" in that tmp array;
                tmp[index++] = this->dinosaursInCage[i];
            }
        }
        delete[] dinosaursInCage;
        this->dinosaursInCage = nullptr;

        this->dinosaursInCage = new Dinosaur[capacityOfCage];
        this->setSizeOfCage(index);
        for (int i = 0; i < this->getSizeOfCage(); i++) {
            this->dinosaursInCage[i] = tmp[i];
        }
        delete[] tmp;
        return true;
    }
    return false;
}

void Cage::storeInBinaryFile() {
    // We make a file where we are going to store the information about cages.
    std::ofstream outputFile("InformationAboutCages", std::ios::out | std::ios::ate | std::ios::app | std::ios::binary);
    if (!outputFile.is_open()) {
        std::cout << "The file can not be opened!" << std::endl;
        exit(1);
    }

    // write the climate into the file;
    int _climate = this->getClimate();
    outputFile.write(reinterpret_cast<const char *>(&_climate), sizeof(int));

    // write the dinosaurs into the file;
    for(int i = 0;i < getNumberOfDinosaurs();i++){
        dinosaursInCage[i].storeInBinaryFile();
    }

    // write the number of dinosaurs into the file;
    int size = this->getNumberOfDinosaurs();
    outputFile.write(reinterpret_cast<const char *>(&size), sizeof(int));

    // write the capacity into the file;
    int capacity = this->getCapacityOfCage();
    outputFile.write(reinterpret_cast<const char *>(&capacity), sizeof(int));

    // write the size of cage into the file;
    int _sizeOfCage = this->getSizeOfCage();
    outputFile.write(reinterpret_cast<const char *>(&_sizeOfCage), sizeof(int));

    // write the era of dinosaurs into the file;
    int _era = this->getEraOfDinosaursInCage();
    outputFile.write(reinterpret_cast<const char *>(&_era), sizeof(int));

    //closing the file;
    outputFile.close();
}

void Cage::resize() {
    this->capacityOfCage = this->capacityOfCage * 2; // we doubled the capacity;
    if(this->capacityOfCage > sizeOfCage)
        capacityOfCage = sizeOfCage;
    Dinosaur* newDinosaursInCage = new Dinosaur[capacityOfCage];
    for(int i = 0; i < this->getNumberOfDinosaurs(); i++){
        newDinosaursInCage[i] = dinosaursInCage[i];
    }
    delete[] this->dinosaursInCage;
    this->dinosaursInCage = newDinosaursInCage;
}

