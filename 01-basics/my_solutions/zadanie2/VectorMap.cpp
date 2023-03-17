// Zadanie - VectorMap
// Napisz klasę szablonową VectorMap, która ma reprezentować przekombinowaną std::map.

// Wewnątrz ma ona mieć 2 std::vector tego samego rozmiaru. Pierwszy vector będzie przechowywał klucze, a drugi wartości.

// Elementy na tej samej pozycji w obu wektorach tworzą parę, tak jak 1 i c na poniższym przykładzie.

// VectorMap<int, char> map;
// map.insert(1, 'c');
// map[1] = 'e';           // replaces value under 1
// std::cout << map[1];    // prints 'e'
// map.at(2);              // throw std::out_of_range
// Zaimplementuj metody insert(), operator[], at().

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T1, typename T2>
class VectorMap{
    private:
        std::vector<T1> keys;
        std::vector<T2> values;

    public:
        VectorMap() = default;
        void insert(T1 key, T2 value);
        void displayAll();
        T2& at(T1 key);
        T2& operator[](T1 key);
};

template <typename T1, typename T2>
void VectorMap<T1, T2>::insert(T1 key, T2 value){

    keys.push_back(key);
    values.push_back(value);
}

template <typename T1, typename T2>
void VectorMap<T1, T2>::displayAll(){

    for(int i = 0; i < keys.size(); i++)
    {
        std::cout<<i<<".\t"<<keys[i]<<"\t"<<values[i]<<std::endl;
    }
    std::cout<<"------------\n";

}

template <typename T1, typename T2>
T2& VectorMap<T1, T2>::at(T1 key){

    auto it = std::find_if(keys.begin(), keys.end(), [&key](auto k){return key == k;});

    if(it != keys.end()){
        auto dist = std::distance(keys.begin(), it);
        return values[dist];
    }
        throw std::out_of_range{"out of range error\n"};
    
}

template <typename T1, typename T2>
T2& VectorMap<T1, T2>::operator[](T1 key){
    
    auto it = std::find_if(keys.begin(), keys.end(), [key](auto k){return key == k;});

    if(it != keys.end()){
        auto dist = std::distance(keys.begin(), it);
        return values[dist];
    }
    else{
        //T2 val {};
        insert(key, {});
        return operator[](key);
    }


}

int main(){

    VectorMap<int, char> map;
    map.insert(10, 'a');
    map.insert(15, 'd');
    map.insert(1, 'c');
    map.displayAll();
    map[1] = 'e';
    map.displayAll();
    map[11] = 'l';
    map.displayAll();
    
    auto m = map.at(5);
    std::cout<<m<<std::endl;
    std::cout<<map[11]<<std::endl;

    // VectorMap<int, char> map;
    // map.insert(1, 'c');
    // map[1] = 'e';        // replaces value under 1
    // std::cout << map[1]; // prints 'e'
    // std::cout << map[2];
    // map.at(3);           // throw std::out_of_range
    return 0;
}