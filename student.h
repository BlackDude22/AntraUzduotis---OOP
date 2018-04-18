#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <random>
#include "antra_math.h"

class Student{
private:
    std::string vardas;
    std::string pavarde;
    int egzaminas;
    std::vector<int> nDarbas;
    double average_;
    double median_;
public:
    Student() : vardas(""), pavarde(""), egzaminas(1), average_(1), median_(1) {}
    Student(std::string v, std::string p, int e, std::vector<int> d) : vardas(v), pavarde(p), egzaminas(e), nDarbas(d), average_(e*0.4+average(d)*0.6), median_(e*0.4+average(d)*0.6) {}

    double getAverage(){return average_;}
    double getMedian(){return median_;}
    std::string getPavarde(){return pavarde;}

    template <typename T> friend void addStudent(T &, std::string, std::string, std::vector<int>, int);
    template <typename T> friend void printStudent(T &);
    template <typename T> friend void readStudentsFromFile(T &, std::string);
    template <typename T> friend void sortContainer(T &);

};

void createStudentFile(unsigned int, std::string);
bool customCompare(Student &, Student &);

//--------------

void addStudentUI(std::vector<Student> &);

template <typename T> void addStudent(T &stud, std::string name, std::string lastName, std::vector<int> marks, int exam){
    if (name.empty())
        throw "Neivestas vardas";
    else if (lastName.empty())
        throw "Neivesta pavarde";
    else if (marks.size() == 0)
        throw "Neivestas ne vienas pazymys";
    else {
        Student student;
        student.vardas = name;
        student.pavarde = lastName;
        student.nDarbas = marks;
        student.egzaminas = exam;
        student.average_ = average(marks);
        student.median_ = median(marks);
        stud.push_back(student);
    }
}

template <typename T> void printStudent(T &stud){
    const int width = 20, prec = 2;
    sortContainer(stud);
    std::cout << std::setw(width) << "Pavarde" << std::setw(width) <<  "Vardas"
    << std::setw(width) << "Galutinis-vidurkis" << std::setw(width) << "Galutinis-mediana" << std::endl;
    //isvardijami visi vectoriuje stud saugomi studentai
    for (const auto& i: stud)
        std::cout << std::setw(width) << i.pavarde << std::setw(width) << i.vardas
        << std::setw(width) << std::fixed << std::setprecision(prec) << i.average_*0.4+i.egzaminas*0.6 
        << std::setw(width) << std::fixed << std::setprecision(prec) << i.median_*0.4+i.egzaminas*0.6 << std::endl;
}
template <typename T> void readStudentsFromFile(T &stud, std::string fileName){
    std::ifstream inf;
    inf.exceptions ( std::ifstream::failbit);
    try{
        inf.open(fileName);
        std::string singleLine;
        //failas nuskaitomas po viena eilute
        while (getline(inf, singleLine)){
            std::vector<std::string> words;
            std::istringstream ss(singleLine);
            std::string temp;
            //gauta eilute skaidoma i zodzius
            while (ss >> temp)
                words.push_back(temp);
            //minimalus zodziu skaicius kad irasas butu galimas 4
            if (words.size() > 3) {
                std::string name = words[1], lastName = words[0];
                std::vector<int> marks;
                for (unsigned int i = 2; i < words.size()-1; i++)
                    marks.push_back(std::stoi(words[i]));
                int exam = std::stoi(words[words.size()-1]);
                try {
                    addStudent(stud, name, lastName, marks, exam);
                } catch (const char* msg){
                    std::cout << msg << std::endl;
                }
            }
        }
        inf.close();
    } catch (std::exception& e){
        // sitas labai letina programos darba
        if (!inf.eof())
            std::cout << "Failed to read from " + fileName << std::endl;
        inf.clear();
    }
}
template <typename T> void sortContainer(T &);

#endif
