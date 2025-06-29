#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>
#include <limits>
#include <algorithm>

class PmergeMe {
private:
    bool isValidNumber(std::string &str);
    bool safeStringToInt(const std::string &str, int &result);

    void binaryInsertDeque(std::deque<int> &sorted, int value);
    void binaryInsertVector(std::vector<int> &sorted, int value);
    std::vector<size_t> generateJacobsthalIndices(size_t size);
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    std::vector<int> inputVector;
    std::deque<int> inputDeque;

    void fordJohnsonSortVector(std::vector<int> &input);
    void fordJohnsonSortDeque(std::deque<int> &input);
    void VectorParse(int arc, char** arv);
    void DequeParse(int arc, char** arv);
};

#endif