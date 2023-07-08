#include "List.h"
#include <vector>

int main() {
    std::vector<int> myVector = { 1, 1, 2, 3, 4, 2, 3, 1 };

    List<int> myList = List<int>(myVector);

    myList.Print();

    myList.PushBack(5);
    myList.Print();

    myList.Reverse();
    myList.Print();

    myList.Unique();
    myList.Print();

    return 0;
}