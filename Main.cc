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

void ANDPerceptron()
{
    std::cout << "Training AND Perceptron..." << std::endl;

    std::vector<TrainingItem> training_set =
    {
        TrainingItem(false, { 1, 0, 0 }),
        TrainingItem(false, { 1, 0, 1 }),
        TrainingItem(false, { 1, 1, 0 }),
        TrainingItem(true,  { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.train(training_set, 43);

    assert(perceptron.get_result({ 1, 0, 0 }) == false);
    assert(perceptron.get_result({ 1, 0, 1 }) == false);
    assert(perceptron.get_result({ 1, 1, 0 }) == false);
    assert(perceptron.get_result({ 1, 1, 1 }) == true);
    std::cout << "Successfully trained!" << std::endl;
    std::cout << std::endl;
}

void NANDPerceptron()
{
    std::cout << "Training NAND Perceptron..." << std::endl;

    std::vector<TrainingItem> training_set =
    {
        TrainingItem(true,  { 1, 0, 0 }),
        TrainingItem(true,  { 1, 0, 1 }),
        TrainingItem(true,  { 1, 1, 0 }),
        TrainingItem(false, { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.train(training_set, 29);

    assert(perceptron.get_result({ 1, 0, 0 }) == true);
    assert(perceptron.get_result({ 1, 0, 1 }) == true);
    assert(perceptron.get_result({ 1, 1, 0 }) == true);
    assert(perceptron.get_result({ 1, 1, 1 }) == false);
    std::cout << "Successfully trained!" << std::endl;
    std::cout << std::endl;
}

void ORPerceptron()
{
    std::cout << "Training OR Perceptron..." << std::endl;

    std::vector<TrainingItem> training_set =
    {
        TrainingItem(false, { 1, 0, 0 }),
        TrainingItem(true,  { 1, 0, 1 }),
        TrainingItem(true,  { 1, 1, 0 }),
        TrainingItem(true,  { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.train(training_set, 14);

    assert(perceptron.get_result({ 1, 0, 0 }) == false);
    assert(perceptron.get_result({ 1, 0, 1 }) == true);
    assert(perceptron.get_result({ 1, 1, 0 }) == true);
    assert(perceptron.get_result({ 1, 1, 1 }) == true);
    std::cout << "Successfully trained!" << std::endl;
    std::cout << std::endl;
}

void NORPerceptron()
{
    std::cout << "Training NOR Perceptron..." << std::endl;

    std::vector<TrainingItem> training_set =
    {
        TrainingItem(true,  { 1, 0, 0 }),
        TrainingItem(false, { 1, 0, 1 }),
        TrainingItem(false, { 1, 1, 0 }),
        TrainingItem(false, { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.train(training_set, 14);

    assert(perceptron.get_result({ 1, 0, 0 }) == true);
    assert(perceptron.get_result({ 1, 0, 1 }) == false);
    assert(perceptron.get_result({ 1, 1, 0 }) == false);
    assert(perceptron.get_result({ 1, 1, 1 }) == false);
    std::cout << "Successfully trained!" << std::endl;
    std::cout << std::endl;
}

void NOTPerceptron()
{
    std::cout << "Training NOT Perceptron..." << std::endl;

    std::vector<TrainingItem> training_set =
    {
        TrainingItem(true,  { 1, 0 }),
        TrainingItem(false, { 1, 1 }),
    };

    Perceptron perceptron(2);

    perceptron.train(training_set, 13);

    assert(perceptron.get_result({ 1, 0 }) == true);
    assert(perceptron.get_result({ 1, 1 }) == false);

    std::cout << "Successfully trained!" << std::endl;
    std::cout << std::endl;
}

void TumorDetectionPerceptron()
{
    std::cout << "Training Custom Perceptron..." << std::endl;

    /*
     *    1 |           x x x
     *      |
     *      |
     * Type |
     *      |
     *      |
     *      |
     *      | x x x
     *    0 |____________________________
     *                    Size
     */

    std::vector<TrainingItem> training_set =
    {
        /**
         * false = benign
         * true  = !false (malign :p)
         *                       Tumor size.
         */
        TrainingItem(false, { 1, 0.1 }),
        TrainingItem(false, { 1, 0.2 }),
        TrainingItem(false, { 1, 0.3 }),
        TrainingItem(true,  { 1, 0.4 }),
        TrainingItem(true,  { 1, 0.5 }),
        TrainingItem(true,  { 1, 0.6 }),
    };

    Perceptron perceptron(2);

    perceptron.train(training_set, 72);

    assert(perceptron.get_result({ 1, 0.1 }) == false);
    assert(perceptron.get_result({ 1, 0.2 }) == false);
    assert(perceptron.get_result({ 1, 0.3 }) == false);
    assert(perceptron.get_result({ 1, 0.4 }) == true);
    assert(perceptron.get_result({ 1, 0.5 }) == true);
    assert(perceptron.get_result({ 1, 0.6 }) == true);
    assert(perceptron.get_result({ 1, 0.7 }) == true);

    std::cout << "Successfully trained!" << std::endl;
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::cout << "Single Layer Perceptron (SLP)  Copyright 2015  Jean Pierre Dudey" << std::endl;
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY." << std::endl;
    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "under certain conditions." << std::endl;

    std::cout << std::endl;

    ANDPerceptron();
    NANDPerceptron();
    ORPerceptron();
    NORPerceptron();
    NOTPerceptron();

    TumorDetectionPerceptron();

    return 0;
}
