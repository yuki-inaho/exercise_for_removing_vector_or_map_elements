#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Test
{
public:
    Test() : _id(0){};
    Test(int32_t id)
    {
        _id = id;
    }

    friend bool operator==(const Test &obj1, const Test &obj2)
    {
        return obj1._id == obj2._id;
    }

    int32_t _id;
};

template <class T>
void print_vector(std::vector<T> vector)
{
    for (T elem : vector)
    {
        std::cout << elem << std::endl;
    }
    std::cout << "size:" << vector.size() << std::endl;
}

int main(int argv, char *argc[])
{
    std::vector<int> test{1, 2, 3, 4};
    print_vector(test);

    test.erase(std::remove(test.begin(), test.end(), 2), test.end());
    print_vector(test);

    std::unordered_map<int32_t, Test> map;
    Test obj_4map1 = Test(0);
    Test obj_4map2 = Test(1);
    Test obj_4map3 = Test(2);
    map.insert(std::pair<int32_t, Test>{1, obj_4map1});
    map.insert(std::pair<int32_t, Test>{2, obj_4map2});
    map.insert(std::pair<int32_t, Test>{3, obj_4map3});
    map.erase(2);
    //std::cout << map.at(2)._id << std::endl; // out of range error
    std::cout << map.at(3)._id << std::endl;

    Test obj1 = Test(0);
    Test obj2 = Test(1);
    Test obj3 = Test(2);
    std::vector<Test> test_with_myclass{obj1, obj2, obj3};
    std::unordered_map<int32_t, int32_t> map_with_myclass;
    for (size_t i = 0; i < test_with_myclass.size(); i++)
    {
        map_with_myclass.insert(std::pair<int32_t, int32_t>{i, test_with_myclass[i]._id});
    }
    test_with_myclass.erase(std::remove(test_with_myclass.begin(), test_with_myclass.end(), obj2), test_with_myclass.end());
    std::cout << test_with_myclass[1]._id << std::endl;
    std::cout << map_with_myclass.at(1) << std::endl;
    

    return 0;
}