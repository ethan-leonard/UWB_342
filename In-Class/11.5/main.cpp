#include <iostream>
#include <vector>
#include <string>
#include <fstream>

template <class T>
std::vector<T> readFileIn(std::string file_name) {
    std::ifstream in_file;
    T temp;
    std::vector<T> vec;

    in_file.open(file_name);
    while (!in_file.eof()) {
        in_file >> temp;
        vec.push_back(temp);
    } in_file.close();

    return vec;
}



int main(int arg, char* argv[]) { 
    std::string file_name;
    std::vector<int> numbers;

    std::cout << "Input file name: ";
    std::cin >> file_name;
    numbers = readFileIn<int>(file_name);

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << (numbers.at(i)) << std::endl;
    }

}
