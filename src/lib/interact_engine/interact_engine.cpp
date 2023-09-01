#include "interact_engine.hpp"
#include <random>


///////////////////////////////// MATHS ///////////////////////////////
int ie::GetRandomNumber(int min, int max)
{
    // static is used to instantiate the random engine and distribution once only.
    // It then generates a new random number on subsequent calls.
    static std::random_device rd;
    static std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(min, max);

    return distr(eng);
}