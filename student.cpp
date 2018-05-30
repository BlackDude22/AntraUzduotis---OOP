#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <deque>
#include <list>
#include "student.h"
#include "antra_math.h"

bool customCompare(Student &stud1, Student &stud2){
    return stud1.getLastName() < stud2.getLastName();
}

template <> void sortContainer(std::vector<Student> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}

template <> void sortContainer(std::deque<Student> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}

template <> void sortContainer(std::list<Student> &stud){
    stud.sort(customCompare);
}

void createStudentFile(unsigned int fSize, std::string fileName){
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> mark(1,10);
    std::ofstream outf(fileName);
    //generuojamas studento irasas
    for (unsigned int i = 0; i < fSize; i++){
        outf << "Pavarde" << i << " Vardas" << i;
        //sugeneruojamas atsitiktinis skaicius atsitiktiniu pazymiu
        for (int j = 0; j < mark(mt)+1; j++)
            outf << " " << mark(mt);
        outf << std::endl;
    }
    outf.close();
}
