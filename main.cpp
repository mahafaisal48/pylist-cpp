#include "PyList.h"
#include <iostream>
#include <string>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        os << vec[i];
        if (i < vec.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

struct Person
{
    std::string name;
    int age;
    bool operator<(const Person& other) const
    {
        if (name != other.name) return name < other.name;
        return age < other.age;
    }
    bool operator==(const Person& other) const
    {
        return name == other.name && age == other.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    return os << "Person(" << p.name << ", " << p.age << ")";
}

void displayMenu()
{
    std::cout << "\n=== PyList Tester Menu ===" << std::endl;
    std::cout << "1. append()" << std::endl;
    std::cout << "2. count()" << std::endl;
    std::cout << "3. extend()" << std::endl;
    std::cout << "4. index()" << std::endl;
    std::cout << "5. insert()" << std::endl;
    std::cout << "6. pop()" << std::endl;
    std::cout << "7. pop(index)" << std::endl;
    std::cout << "8. remove()" << std::endl;
    std::cout << "9. reverse()" << std::endl;
    std::cout << "10. sort()" << std::endl;
    std::cout << "11. clear()" << std::endl;
    std::cout << "12. operator+" << std::endl;
    std::cout << "13. contains()" << std::endl;
    std::cout << "14. operator[]" << std::endl;
    std::cout << "15. len()" << std::endl;
    std::cout << "16. setitem()" << std::endl;
    std::cout << "17. slice()" << std::endl;
    std::cout << "18. push()" << std::endl;
    std::cout << "19. pop_stack()" << std::endl;
    std::cout << "20. enqueue()" << std::endl;
    std::cout << "21. dequeue()" << std::endl;
    std::cout << "22. print()" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{

    PyList list1, list2;
    int choice;
    bool running = true;

    while (running)
    {
        displayMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value: ";
                std::cin >> val;
                list1.append(val);
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value: ";
                std::cin >> val;
                list1.append(val);
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value: ";
                std::cin >> val;
                list1.append(val);
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value: ";
                std::cin >> val;
                list1.append(val);
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value: ";
                std::cin >> val;
                list1.append(val);
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                list1.append(p);
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                list1.append(vec);
            }
            else if (type == 8)
            {
                PyList nestedList;
                int nestedChoice;
                std::cout << "Create nested PyList. How many elements? ";
                int count;
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        nestedList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        nestedList.append(vec);
                    }
                }
                list1.append(nestedList);
            }
            std::cout << "List after append: " << list1 << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value to count: ";
                std::cin >> val;
                std::cout << "Count: " << list1.count(val) << std::endl;
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value to count: ";
                std::cin >> val;
                std::cout << "Count: " << list1.count(val) << std::endl;
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value to count: ";
                std::cin >> val;
                std::cout << "Count: " << list1.count(val) << std::endl;
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value to count: ";
                std::cin >> val;
                std::cout << "Count: " << list1.count(val) << std::endl;
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value to count: ";
                std::cin >> val;
                std::cout << "Count: " << list1.count(val) << std::endl;
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                std::cout << "Count: " << list1.count(p) << std::endl;
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                std::cout << "Count: " << list1.count(vec) << std::endl;
            }
            else if (type == 8)
            {
                PyList searchList;
                int count;
                std::cout << "Enter PyList to search for. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        searchList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        searchList.append(vec);
                    }
                }
                std::cout << "Count: " << list1.count(searchList) << std::endl;
            }
            break;
        }
        case 3:
        {
            std::cout << "First, add some elements to list2:" << std::endl;
            list2.append(1);
            list2.append(2);
            list2.append(3);
            std::cout << "list1: " << list1 << std::endl;
            std::cout << "list2: " << list2 << std::endl;
            list1.extend(list2);
            std::cout << "list1 after extend: " << list1 << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value to find index: ";
                std::cin >> val;
                std::cout << "Index: " << list1.index(val) << std::endl;
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value to find index: ";
                std::cin >> val;
                std::cout << "Index: " << list1.index(val) << std::endl;
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value to find index: ";
                std::cin >> val;
                std::cout << "Index: " << list1.index(val) << std::endl;
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value to find index: ";
                std::cin >> val;
                std::cout << "Index: " << list1.index(val) << std::endl;
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value to find index: ";
                std::cin >> val;
                std::cout << "Index: " << list1.index(val) << std::endl;
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                std::cout << "Index: " << list1.index(p) << std::endl;
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                std::cout << "Index: " << list1.index(vec) << std::endl;
            }
            else if (type == 8)
            {
                PyList searchList;
                int count;
                std::cout << "Enter PyList to search for. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        searchList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        searchList.append(vec);
                    }
                }
                std::cout << "Index: " << list1.index(searchList) << std::endl;
            }
            break;
        }
        case 5:
        {
            long long int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value: ";
                std::cin >> val;
                list1.insert(index, val);
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value: ";
                std::cin >> val;
                list1.insert(index, val);
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value: ";
                std::cin >> val;
                list1.insert(index, val);
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value: ";
                std::cin >> val;
                list1.insert(index, val);
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value: ";
                std::cin >> val;
                list1.insert(index, val);
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                list1.insert(index, p);
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                list1.insert(index, vec);
            }
            else if (type == 8)
            {
                PyList nestedList;
                int count;
                std::cout << "Create nested PyList. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        nestedList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        nestedList.append(vec);
                    }
                }
                list1.insert(index, nestedList);
            }
            std::cout << "List after insert: " << list1 << std::endl;
            break;
        }
        case 6:
        {
            auto popped = list1.pop();
            std::cout << "Popped value: ";
            popped->print();
            std::cout << std::endl;
            std::cout << "List after pop: " << list1 << std::endl;
            break;
        }
        case 7:
        {
            size_t index;
            std::cout << "Enter index: ";
            std::cin >> index;
            auto popped = list1.pop(index);
            std::cout << "Popped value: ";
            popped->print();
            std::cout << std::endl;
            std::cout << "List after pop: " << list1 << std::endl;
            break;
        }
        case 8:
        {
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value to remove: ";
                std::cin >> val;
                list1.remove(val);
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value to remove: ";
                std::cin >> val;
                list1.remove(val);
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value to remove: ";
                std::cin >> val;
                list1.remove(val);
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value to remove: ";
                std::cin >> val;
                list1.remove(val);
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value to remove: ";
                std::cin >> val;
                list1.remove(val);
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                list1.remove(p);
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                list1.remove(vec);
            }
            else if (type == 8)
            {
                PyList searchList;
                int count;
                std::cout << "Enter PyList to remove. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        searchList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        searchList.append(vec);
                    }
                }
                list1.remove(searchList);
            }
            std::cout << "List after remove: " << list1 << std::endl;
            break;
        }
        case 9:
        {
            list1.reverse();
            std::cout << "List after reverse: " << list1 << std::endl;
            break;
        }
        case 10:
        {
            bool reverse;
            std::cout << "Reverse sort? (0-false, 1-true): ";
            std::cin >> reverse;
            list1.sort(reverse);
            std::cout << "List after sort: " << list1 << std::endl;
            break;
        }
        case 11:
        {
            list1.clear();
            std::cout << "List after clear: " << list1 << std::endl;
            break;
        }
        case 12:
        {
            PyList list3 = list1 + list2;
            std::cout << "list1: " << list1 << std::endl;
            std::cout << "list2: " << list2 << std::endl;
            std::cout << "list1 + list2: " << list3 << std::endl;
            break;
        }
        case 13:
        {
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value: ";
                std::cin >> val;
                std::cout << "Contains: " << (list1.contains(val) ? "true" : "false") << std::endl;
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value: ";
                std::cin >> val;
                std::cout << "Contains: " << (list1.contains(val) ? "true" : "false") << std::endl;
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value: ";
                std::cin >> val;
                std::cout << "Contains: " << (list1.contains(val) ? "true" : "false") << std::endl;
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value: ";
                std::cin >> val;
                std::cout << "Contains: " << (list1.contains(val) ? "true" : "false") << std::endl;
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value: ";
                std::cin >> val;
                std::cout << "Contains: " << (list1.contains(val) ? "true" : "false") << std::endl;
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                std::cout << "Contains: " << (list1.contains(p) ? "true" : "false") << std::endl;
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                std::cout << "Contains: " << (list1.contains(vec) ? "true" : "false") << std::endl;
            }
            else if (type == 8)
            {
                PyList searchList;
                int count;
                std::cout << "Enter PyList to search for. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        searchList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        searchList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        searchList.append(vec);
                    }
                }
                std::cout << "Contains: " << (list1.contains(searchList) ? "true" : "false") << std::endl;
            }
            break;
        }
        case 14:
        {
            long long int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            auto item = list1[index];
            std::cout << "Item at index " << index << ": ";
            item->print();
            std::cout << std::endl;
            break;
        }
        case 15:
        {
            std::cout << "Length of list: " << list1.len() << std::endl;
            break;
        }
        case 16:
        {
            long long int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value: ";
                std::cin >> val;
                list1.setitem(index, val);
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value: ";
                std::cin >> val;
                list1.setitem(index, val);
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value: ";
                std::cin >> val;
                list1.setitem(index, val);
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value: ";
                std::cin >> val;
                list1.setitem(index, val);
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value: ";
                std::cin >> val;
                list1.setitem(index, val);
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                list1.setitem(index, p);
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                list1.setitem(index, vec);
            }
            else if (type == 8)
            {
                PyList nestedList;
                int count;
                std::cout << "Create nested PyList. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        nestedList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        nestedList.append(vec);
                    }
                }
                list1.setitem(index, nestedList);
            }
            std::cout << "List after setitem: " << list1 << std::endl;
            break;
        }
        case 17:
        {
            long long int start, end;
            std::cout << "Enter start index: ";
            std::cin >> start;
            std::cout << "Enter end index: ";
            std::cin >> end;
            PyList sliced = list1.slice(start, end);
            std::cout << "Sliced list: " << sliced << std::endl;
            break;
        }
        case 18:
        {
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value: ";
                std::cin >> val;
                list1.push(val);
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value: ";
                std::cin >> val;
                list1.push(val);
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value: ";
                std::cin >> val;
                list1.push(val);
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value: ";
                std::cin >> val;
                list1.push(val);
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value: ";
                std::cin >> val;
                list1.push(val);
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                list1.push(p);
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                list1.push(vec);
            }
            else if (type == 8)
            {
                PyList nestedList;
                int count;
                std::cout << "Create nested PyList. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        nestedList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        nestedList.append(vec);
                    }
                }
                list1.push(nestedList);
            }
            std::cout << "List after push: " << list1 << std::endl;
            break;
        }
        case 19:
        {
            auto popped = list1.pop_stack();
            std::cout << "Popped value: ";
            popped->print();
            std::cout << std::endl;
            std::cout << "List after pop_stack: " << list1 << std::endl;
            break;
        }
        case 20:
        {
            std::cout << "Select data type (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector, 8-PyList): ";
            int type;
            std::cin >> type;
            if (type == 1)
            {
                int val;
                std::cout << "Enter int value: ";
                std::cin >> val;
                auto boxed = std::make_shared<Boxed<int>>(val);
                list1.enqueue(boxed);
            }
            else if (type == 2)
            {
                std::string val;
                std::cout << "Enter string value: ";
                std::cin >> val;
                auto boxed = std::make_shared<Boxed<std::string>>(val);
                list1.enqueue(boxed);
            }
            else if (type == 3)
            {
                char val;
                std::cout << "Enter char value: ";
                std::cin >> val;
                auto boxed = std::make_shared<Boxed<char>>(val);
                list1.enqueue(boxed);
            }
            else if (type == 4)
            {
                double val;
                std::cout << "Enter double value: ";
                std::cin >> val;
                auto boxed = std::make_shared<Boxed<double>>(val);
                list1.enqueue(boxed);
            }
            else if (type == 5)
            {
                float val;
                std::cout << "Enter float value: ";
                std::cin >> val;
                auto boxed = std::make_shared<Boxed<float>>(val);
                list1.enqueue(boxed);
            }
            else if (type == 6)
            {
                Person p;
                std::cout << "Enter person name: ";
                std::cin >> p.name;
                std::cout << "Enter person age: ";
                std::cin >> p.age;
                auto boxed = std::make_shared<Boxed<Person>>(p);
                list1.enqueue(boxed);
            }
            else if (type == 7)
            {
                std::vector<int> vec;
                int size, value;
                std::cout << "Enter vector size: ";
                std::cin >> size;
                std::cout << "Enter " << size << " values: ";
                for (int i = 0; i < size; i++)
                {
                    std::cin >> value;
                    vec.push_back(value);
                }
                auto boxed = std::make_shared<Boxed<std::vector<int>>>(vec);
                list1.enqueue(boxed);
            }
            else if (type == 8)
            {
                PyList nestedList;
                int count;
                std::cout << "Create nested PyList. How many elements? ";
                std::cin >> count;
                for (int i = 0; i < count; i++)
                {
                    std::cout << "Select data type for element " << i + 1 << " (1-int, 2-string, 3-char, 4-double, 5-float, 6-Person, 7-Vector): ";
                    int elemType;
                    std::cin >> elemType;
                    if (elemType == 1)
                    {
                        int val;
                        std::cout << "Enter int value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 2)
                    {
                        std::string val;
                        std::cout << "Enter string value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 3)
                    {
                        char val;
                        std::cout << "Enter char value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 4)
                    {
                        double val;
                        std::cout << "Enter double value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 5)
                    {
                        float val;
                        std::cout << "Enter float value: ";
                        std::cin >> val;
                        nestedList.append(val);
                    }
                    else if (elemType == 6)
                    {
                        Person p;
                        std::cout << "Enter person name: ";
                        std::cin >> p.name;
                        std::cout << "Enter person age: ";
                        std::cin >> p.age;
                        nestedList.append(p);
                    }
                    else if (elemType == 7)
                    {
                        std::vector<int> vec;
                        int vecSize, vecValue;
                        std::cout << "Enter vector size: ";
                        std::cin >> vecSize;
                        std::cout << "Enter " << vecSize << " values: ";
                        for (int j = 0; j < vecSize; j++)
                        {
                            std::cin >> vecValue;
                            vec.push_back(vecValue);
                        }
                        nestedList.append(vec);
                    }
                }
                auto boxed = std::make_shared<Boxed<PyList>>(nestedList);
                list1.enqueue(boxed);
            }
            std::cout << "List after enqueue: " << list1 << std::endl;
            break;
        }
        case 21:
        {
            auto dequeued = list1.dequeue();
            std::cout << "Dequeued value: ";
            dequeued->print();
            std::cout << std::endl;
            std::cout << "List after dequeue: " << list1 << std::endl;
            break;
        }
        case 22:
        {
            std::cout << "List: " << list1 << std::endl;
            break;
        }
        case 0:
            running = false;
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}