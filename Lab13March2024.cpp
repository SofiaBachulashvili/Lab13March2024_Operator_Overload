// Lab13March2024.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Vector.h"

void readVectorsFromFile(const std::string& filename, Vector& vector1, Vector& vector2) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int size1, size2;
        file >> size1;
        vector1 = Vector(size1);
        file >> vector1;
        file >> size2;
        vector2 = Vector(size2);
        file >> vector2;
        file.close();
    }
    else {
        std::cerr << "Error opening file for reading!!!" << std::endl;
    }
}

void writeVectorToFile(const std::string& filename, const Vector& vector) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << vector;
        file.close();
    }
    else {
        std::cerr << "Error opening file for writing!!!" << std::endl;
    }
}


int main(){

    Vector vec1, vec2, vec_sum, copy_;

    readVectorsFromFile("input.txt", vec1, vec2);

    std::cout << "Vector 1: " << vec1 << std::endl;
    std::cout << "Vector 2: " << vec2 << std::endl;
    vec_sum = vec1 + vec2;

    std::cout << "Summary: " << vec_sum << std::endl;

    writeVectorToFile("output.txt", vec_sum);

    std::cout << "Summary of vectors saved to output.txt" << std::endl;

    return 0;
}
