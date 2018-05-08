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

/**
 * @brief      Class for student.
 */
class Student{
private:
    std::string vardas;
    std::string pavarde;
    int egzaminas;
    std::vector<int> nDarbas;
    double average_;
    double median_;
public:
    /**
     * @brief      Constructor for an empty object
     */
    Student() : vardas(""), pavarde(""), egzaminas(1), average_(1), median_(1) { std::vector<int> d{0}; nDarbas = d;}
    /**
     * @brief      Constructor for a filled object
     *
     * @param[in]  v     Students name
     * @param[in]  p     Students last name
     * @param[in]  e     Students exam mark
     * @param[in]  d     Students marks vector
     */
    Student(std::string v, std::string p, int e, std::vector<int> d) : vardas(v), pavarde(p), egzaminas(e), nDarbas(d), average_(e*0.4+average(d)*0.6), median_(e*0.4+average(d)*0.6) {}

    /**
     * @brief      Gets the average.
     *
     * @return     The average.
     */
    double getAverage(){return average_;}
    /**
     * @brief      Gets the median.
     *
     * @return     The median.
     */
    double getMedian(){return median_;}
    /**
     * @brief      Gets the last name.
     *
     * @return     The last name.
     */
    std::string getLastName(){return pavarde;}

    /**
     * @brief      Sets the name.
     *
     * @param[in]  name  The name
     */
    void setName(std::string name){
        if (name.empty())
            throw "Neivestas vardas";
        else
            vardas = name;
    }
    /**
     * @brief      Sets the last name.
     *
     * @param[in]  lastName  The last name
     */
    void setLastName(std::string lastName){
        if (lastName.empty())
            throw "Neivesta pavarde";
        else 
            pavarde = lastName;
    }
    /**
     * @brief      Sets the exam.
     *
     * @param[in]  exam  The exam
     */
    void setExam(int exam){
        if (exam < 1 || exam > 10)
            throw "Negalimas egzamino pazymys";
        else 
            egzaminas = exam;
    }
    /**
     * @brief      Sets the marks.
     *
     * @param[in]  marks  The marks
     */
    void setMarks(std::vector<int> marks){
        if (marks.empty())
            throw "Negalimi pazymiai";
        else 
            nDarbas = marks;
    }
    /**
     * @brief      Sets the average.
     *
     * @param[in]  aver  The aver
     */
    inline void setAverage(double aver){average_ = aver;}
    /**
     * @brief      Sets the median.
     *
     * @param[in]  med   The median
     */
    inline void setMedian(double med){median_ = med;}

    /**
     * @brief      Adds a student to a selected container
     *
     * @param      stud       container
     * @param[in]  name       Students name
     * @param[in]  lastName   Students last name
     * @param[in]  marks      Students marks vector
     * @param[in]  exam       Students exam mark
     *
     * @tparam     T          container type
     */
    template <typename T> friend void addStudent(T &, std::string, std::string, std::vector<int>, int);

    /**
     * @brief      Prints out students for a selected container
     *
     * @param      stud       container
     *
     * @tparam     T          container type
     */
    template <typename T> friend void printStudent(T &);
    /**
     * @brief      Reads students from a selected file.
     *
     * @param      stud       container
     * @param[in]  fileName   name of the file
     *
     * @tparam     T          container type
     */
    template <typename T> friend void readStudentsFromFile(T &, std::string);
    /**
     * @brief      Sorts a container by students last name
     *
     * @param      stud       container
     *
     * @tparam     T          container type
     */
    template <typename T> friend void sortContainer(T &);

    /**
     * @brief      overloaded the operator<< to return student data
     *
     * @param      os    The output stream
     * @param[in]  stud  Student object to be outputted
     *
     * @return     Students data
     */
    inline friend std::ostream& operator<<(std::ostream& os, Student stud){
        const int width = 20;
        const int prec = 2;
        os << std::setw(width) << stud.pavarde << std::setw(width) << stud.vardas
        << std::setw(width) << std::fixed << std::setprecision(prec) << stud.average_
        << std::setw(width) << std::fixed << std::setprecision(prec) << stud.median_;
        return os;
    }

    /**
     * @brief      overloads > operator for Student class. Compares by average.
     *
     * @param[in]  stud  The Student
     *
     * @return     True if left Student has a higher average, False otherwise
     */
    inline bool operator>(const Student & stud)  {return stud.average_ - average_ > 0;}
    /**
     * @brief      overloads < operator for Student class. Compares by average.
     *
     * @param[in]  stud  The Student
     *
     * @return     True if left Student has a lower average, False otherwise
     */
    inline bool operator<(const Student & stud)  {return stud.average_ - average_ < 0;}
    /**
     * @brief      overloads >= operator for Student class. Compares by average.
     *
     * @param[in]  stud  The Student
     *
     * @return     True if left Student has a higher or equal average, False otherwise
     */
    inline bool operator>=(const Student & stud) {return stud.average_ - average_ >= 0;}
    /**
     * @brief      overloads <= operator for Student class. Compares by average.
     *
     * @param[in]  stud  The Student
     *
     * @return     True if left Student has a lower or equal average, False otherwise
     */    
    inline bool operator<=(const Student & stud) {return stud.average_ - average_ <= 0;}
    /**
     * @brief      overloads == operator for Student class. Compares by average.
     *
     * @param[in]  stud  The Student
     *
     * @return     True if left Student has an equal average, False otherwise
     */
    inline bool operator==(const Student & stud) {return stud.average_ - average_ == 0;}
    /**
     * @brief      overloads != operator for Student class. Compares by average.
     *
     * @param[in]  stud  The Student
     *
     * @return     True if left Student does not have an equal average, False otherwise
     */
    inline bool operator!=(const Student & stud) {return !operator==(stud);}

};

/**
 * @brief      Creates a student file.
 *
 * @param[in]  fSize  Number of students in the file
 * @param[in]  fileName  Name of the file
 */
void createStudentFile(unsigned int, std::string);
/**
 * @brief      Custom compare function for Student class. Compares by last name
 *
 * @param      stud1 Student1
 * @param      stud2 Student2
 *
 * @return     True if Student1 has a greater last name than Student2, False otherwise
 */
bool customCompare(Student &, Student &);


//--------------

void addStudentUI(std::vector<Student> &);

template <typename T> void addStudent(T &stud, std::string name, std::string lastName, std::vector<int> marks, int exam){
    Student student{name, lastName, exam, marks};
    // std::cout << "bl" << std::endl;
    stud.push_back(student);
}

template <typename T> void printStudent(T &stud){
    const int width = 20, prec = 2;
    //sortContainer(stud);
    std::cout << std::setw(width) << "Pavarde" << std::setw(width) <<  "Vardas"
    << std::setw(width) << "Galutinis-vidurkis" << std::setw(width) << "Galutinis-mediana" << std::endl;
    //isvardijami visi vectoriuje stud saugomi studentai
    for (const auto& i: stud)
        std::cout << i << std::endl;
}
template <typename T> void readStudentsFromFile(T &stud, std::string fileName){
    std::ifstream inf;
    inf.exceptions ( std::ifstream::failbit);
    try{
        inf.open(fileName);
        std::string singleLine;
        // std::cout << "bl" << std::endl;
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
                Student newStud(name, lastName, exam, marks);
                stud.push_back(newStud);
            }
            // std::cout << "bl" << std::endl;
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
