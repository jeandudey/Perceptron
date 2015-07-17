#pragma once
#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include <vector>
#include <numeric>
#include <stdexcept>

#include "TrainingItem.hpp"

class Perceptron
{
 public:
  Perceptron (int input_count, const double learning_rate = 0.1,
              const double threshold = 0.5)
    : weights_(input_count)
  {
    learning_rate_ = learning_rate;
    threshold_ = threshold;
  }

  ~Perceptron () { }

  double learning_rate() const { return learning_rate_; }
  void learning_rate(const double &learning_rate) { learning_rate_ = learning_rate; }

  double threshold() const { return threshold_; }
  void threshold(const double &threshold) { threshold_ = threshold; }

  std::vector<double> & weights() { return weights_; }
  void weights(const std::vector<double> &weights) { weights_ = weights; }

  bool get_result(const std::vector<double> &inputs)
  {
    if (inputs.size() != weights_.size())
      throw std::invalid_argument("Invalid number of inputs. Expected: "
                                  + weights_.size());

    return dot_product(inputs, weights_) > threshold_;
  }

  bool learn(bool expected_result, const std::vector<double> &inputs)
  {
    bool result = get_result(inputs);
    if (result != expected_result) {
        // Convert boolean to a number
        double error = (expected_result ? 1 : 0) - (result ? 1 : 0);
        for (int i = 0; i < weights_.size(); i++) {
            weights_[i] += learning_rate_ * error * inputs[i];
        }
    }

    return result;
  }

 private:
  double learning_rate_;
  double threshold_;
  std::vector<double> weights_;

  /**
   * Taken from StackOverflow:
   * http://stackoverflow.com/questions/13314098/get-the-dot-product-of-two-vectors-by-functors-and-stl-algorithms
   */
  double dot_product(const std::vector<double> &v1,
                     const std::vector<double> &v2)
  {
      return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
  }

};

#endif // PERCEPTRON_HPP
