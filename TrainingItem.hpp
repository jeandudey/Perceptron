#pragma once
#ifndef TRAININGITEM_HPP
#define TRAININGITEM_HPP

#include <vector>

class TrainingItem {
 public:
  TrainingItem(bool expected_output, const std::vector<double> &inputs)
      : output_(expected_output)
  {
    inputs_ = inputs;
  }

  bool output() const { return output_; }
  std::vector<double> & inputs() { return inputs_; }

 private:
  bool output_;
  std::vector<double> inputs_;
};

#endif // TRAININGITEM_HPP
