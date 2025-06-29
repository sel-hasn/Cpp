#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe obj;
        PmergeMe before;
        
        clock_t startVec = clock();
        obj.VectorParse(argc, argv);
        obj.fordJohnsonSortVector(obj.inputVector);
        clock_t endVec = clock();
    
        before.VectorParse(argc, argv);

        std::cout << "Before: ";
        for (size_t i = 0; i < before.inputVector.size(); ++i)
            std::cout << before.inputVector[i] << " ";
        std::cout << std::endl;

        clock_t startDeq = clock();
        obj.DequeParse(argc, argv);
        obj.fordJohnsonSortDeque(obj.inputDeque);
        clock_t endDeq = clock();

        std::cout << "After: ";
        for (size_t i = 0; i < obj.inputDeque.size(); ++i)
            std::cout << obj.inputDeque[i] << " ";
        std::cout << std::endl;

        double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
        double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

        std::cout << "Time to process a range of " << obj.inputVector.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
        std::cout << "Time to process a range of " << obj.inputDeque.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}