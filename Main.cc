#include <vector>
#include <iostream>
#include <cassert>

#include "Perceptron.hpp"

int main(int argc, char **argv)
{
    std::vector<TrainingItem> training_set =
    {
        TrainingItem(true,  { 1, 0, 0 }),
        TrainingItem(true,  { 1, 0, 1 }),
        TrainingItem(true,  { 1, 1, 0 }),
        TrainingItem(false, { 1, 1, 1 })
    };

    auto perceptron = Perceptron(3);

    while (true) {
        int error_count = 0;

        for (auto &item : training_set) {
            bool output = perceptron.learn(item.output(), item.inputs());

            if (output != item.output())
                error_count++;
        }

        if (error_count == 0)
            break;
    }

    assert(perceptron.get_result({ 1, 0, 0 }) == true);
    assert(perceptron.get_result({ 1, 0, 1 }) == true);
    assert(perceptron.get_result({ 1, 1, 0 }) == true);
    assert(perceptron.get_result({ 1, 1, 1 }) == false);

    return 0;
}
