//
// Created by Bánfalvi Katalin on 2024. 09. 16..
//

#ifndef MANKALA_TEST_HELPER_H
#define MANKALA_TEST_HELPER_H


#include <random>
#include <span>

class Random {
    static std::mt19937 gen;
public:

    template<typename T>
    static T randomElement(std::span<T> vec) {
        std::uniform_int_distribution<unsigned char> distr(0, vec.size() - 1);  // Generate index within vector size
        unsigned char randomIndex = distr(gen);  // Get a random index
        return vec[randomIndex];  // Return the element at that index
    }
    template<typename T, unsigned char size>
    static T randomElement(const std::array<T, size>& array) {
        std::uniform_int_distribution<unsigned char> distr(0, size - 1);  // Generate index within vector size
        unsigned char randomIndex = distr(gen);  // Get a random index
        return array[randomIndex];  // Return the element at that index
    }
    template<typename T>
    static T randomElement(const std::vector<T>& vec) {
        std::uniform_int_distribution<unsigned char> distr(0, vec.size() - 1);  // Generate index within vector size
        unsigned char randomIndex = distr(gen);  // Get a random index
        return vec[randomIndex];  // Return the element at that index
    }

};
std::mt19937 Random::gen(std::random_device{}());
#endif //MANKALA_TEST_HELPER_H
