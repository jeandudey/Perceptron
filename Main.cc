/**
 * Single Layer Perceptron (SLP) on C++.
 * Copyright (C) 2015  Jean Pierre Dudey

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <vector>
#include <iostream>
#include <cassert>

#include "Perceptron.hpp"

int main(int argc, char **argv)
{
    std::cout << "Single Layer Perceptron (SLP)  Copyright 2015  Jean Pierre Dudey" << std::endl;
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY." << std::endl;
    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "under certain conditions." << std::endl;

    std::vector<TrainingItem> training_set =
    {
        TrainingItem(true,  { 1, 0, 0 }),
        TrainingItem(true,  { 1, 0, 1 }),
        TrainingItem(true,  { 1, 1, 0 }),
        TrainingItem(false, { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.train(training_set);

    assert(perceptron.get_result({ 1, 0, 0 }) == true);
    assert(perceptron.get_result({ 1, 0, 1 }) == true);
    assert(perceptron.get_result({ 1, 1, 0 }) == true);
    assert(perceptron.get_result({ 1, 1, 1 }) == false);

    return 0;
}
