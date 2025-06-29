#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) : inputVector(other.inputVector), inputDeque(other.inputDeque)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->inputVector = other.inputVector;
        this->inputDeque = other.inputDeque;
    }
    return (*this);
}

void PmergeMe::binaryInsertVector(std::vector<int> &sorted, int value) {
    size_t left = 0;
    size_t right = sorted.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    sorted.insert(sorted.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value) {
    size_t left = 0;
    size_t right = sorted.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    sorted.insert(sorted.begin() + left, value);
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t size) {
    if (size == 0)
        return std::vector<size_t>();

    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    
    while (jacobsthal[jacobsthal.size() - 1] < size) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }

    std::vector<size_t> insertionOrder;
    size_t inserted = 0;
    
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t limit = std::min(jacobsthal[i], size);
        
        for (size_t j = limit; j > inserted; j--) {
            insertionOrder.push_back(j - 1);
        }
        inserted = limit;
        
        if (inserted >= size)
            break;
    }

    return insertionOrder;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int> &input) {
    if (input.size() <= 1)
        return;

    std::vector<int> larger, smaller;

    size_t i = 0;
    for (; i + 1 < input.size(); i += 2) {
        if (input[i] > input[i + 1]) {
            larger.push_back(input[i]);
            smaller.push_back(input[i + 1]);
        } else {
            larger.push_back(input[i + 1]);
            smaller.push_back(input[i]);
        }
    }

    bool hasOdd = (input.size() % 2 != 0);
    int oddElement = hasOdd ? input[input.size() - 1] : 0;

    fordJohnsonSortVector(larger);

    if (!smaller.empty()) {
        std::vector<size_t> insertionOrder = generateJacobsthalIndices(smaller.size());
        
        for (size_t j = 0; j < insertionOrder.size(); ++j) {
            size_t idx = insertionOrder[j];
            if (idx < smaller.size()) {
                binaryInsertVector(larger, smaller[idx]);
            }
        }
    }

    if (hasOdd) {
        binaryInsertVector(larger, oddElement);
    }

    input.clear();
    input.insert(input.begin(), larger.begin(), larger.end());
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int> &input) {
    if (input.size() <= 1)
        return;

    std::deque<int> larger, smaller;

    size_t i = 0;
    for (; i + 1 < input.size(); i += 2) {
        if (input[i] > input[i + 1]) {
            larger.push_back(input[i]);
            smaller.push_back(input[i + 1]);
        } else {
            larger.push_back(input[i + 1]);
            smaller.push_back(input[i]);
        }
    }

    bool hasOdd = (input.size() % 2 != 0);
    int oddElement = hasOdd ? input[input.size() - 1] : 0;

    fordJohnsonSortDeque(larger);

    if (!smaller.empty()) {
        std::vector<size_t> insertionOrder = generateJacobsthalIndices(smaller.size());
        
        for (size_t j = 0; j < insertionOrder.size(); ++j) {
            size_t idx = insertionOrder[j];
            if (idx < smaller.size()) {
                binaryInsertDeque(larger, smaller[idx]);
            }
        }
    }

    if (hasOdd) {
        binaryInsertDeque(larger, oddElement);
    }

    input.clear();
    input.insert(input.begin(), larger.begin(), larger.end());
}

bool PmergeMe::isValidNumber(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i])){
            return false;
        }
    }
    return true;
}

bool PmergeMe::safeStringToInt(const std::string &str, int &result) {
    std::istringstream iss(str);
    long temp;
    iss >> temp;
    if (iss.fail() || !iss.eof())
        return false;
    if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
        return false;
    result = static_cast<int>(temp);
    return true;
}

void PmergeMe::VectorParse(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error: not enough arguments.");

    inputVector.clear();

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (!isValidNumber(arg))
            throw std::runtime_error("Error: invalid input '" + arg + "'");

        int value;
        if (!safeStringToInt(arg, value))
            throw std::runtime_error("Error: input out of range '" + arg + "'");

        if (value < 0)
            throw std::runtime_error("Error: negative values are not allowed.");

        if (std::find(inputVector.begin(), inputVector.end(), value) != inputVector.end())
            throw std::runtime_error("Error: duplicate value detected -> " + arg);

        inputVector.push_back(value);
    }
}

void PmergeMe::DequeParse(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error: not enough arguments.");

    inputDeque.clear();

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (!isValidNumber(arg))
            throw std::runtime_error("Error: invalid input '" + arg + "'");

        int value;
        if (!safeStringToInt(arg, value))
            throw std::runtime_error("Error: input out of range '" + arg + "'");

        if (value < 0)
            throw std::runtime_error("Error: negative values are not allowed.");

        if (std::find(inputDeque.begin(), inputDeque.end(), value) != inputDeque.end())
            throw std::runtime_error("Error: duplicate value detected -> " + arg);

        inputDeque.push_back(value);
    }
}