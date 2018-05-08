#ifndef ANTRA_MATH_H
#define ANTRA_MATH_H

#include <vector>
#include <chrono>

/**
 * @brief      Gets average value of a std::vector<int> containers elements
 *
 * @param      arr  input vector
 *
 * @return     average value of a vectors elements
 */
double average(std::vector<int> &);
/**
 * @brief      Gets median value of a std::vector<int> containers elements
 *
 * @param      arr input vector
 *
 * @return     median value of vectors elements
 */
double median(std::vector<int> &); 
/**
 * @brief      Gets the current time
 *
 * @return     current time
 */
std::chrono::high_resolution_clock::time_point getTime();
/**
 * @brief      Determines if a string has only digits.
 *
 * @param[in]  s  input string
 *
 * @return     True if has only digits, False otherwise.
 */
bool hasOnlyDigits(std::string);
/**
 * @brief      Gets a string input from cin. 
 *
 * @return     input string
 */
std::string safeInput();
/**
 * @brief      Gets an int input from cin.
 *
 * @return     input int
 */
int safeIntInput();

#endif
