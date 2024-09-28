#include <cstdlib>
#include "random_vector.h"

RandomVector::RandomVector(int size, double max_val) { 
  std::vector<double> newVec(size, max_val);
  vect = newVec;

  for (unsigned int i = 0; i != vect.size(); i++) {
    vect.at(i) = (double) rand() / RAND_MAX;
  }
}

void RandomVector::print(){
  //for (auto i = 0; i != vect.size(); i++) {
  //  std::cout << vect.at(i) << " ";
  //}
  for (auto &item : vect) {
    std::cout << item;
  }
  std::cout << std::endl;

}

double RandomVector::mean(){
  double sum = vect.at(0);

  for (auto &item : vect) {
    sum += item;
  }

  double avg = sum / vect.size();
  return avg;
}

double RandomVector::max(){
  double max = vect.at(0);

  for (unsigned int i = 1; i != vect.size(); i++) {
    if (max < vect.at(i)) {
      max = vect.at(i);
    }
  }

  return max;
}

double RandomVector::min(){
  double min = vect.at(0);

  for (unsigned int i = 1; i < vect.size(); i++) {
    if (min > vect.at(i)) {
      min = vect.at(i);
    }
  }
  return min;
}

void RandomVector::printHistogram(int bins){
  // define width of each bin
  double width = RandomVector::max() / bins;

  // vector to hold width sizes from vect.min as lower bound
  std::vector<double> bin_widths;
  for (auto i = 0; i < bins; i++) {
    double bin_width = RandomVector::min() + (width * (i + 1));
    bin_widths.push_back(bin_width);
  }

  // ensure the upper bound of the last bin is not greater than vect.max()
  if (bin_widths.at(bins - 1) > RandomVector::max()) {
    bin_widths.at(bins - 1) = RandomVector::max();
  }

  // initialize vector to count number of items in bins
  std::vector<int> counts;
  for (int i = 0; i < bins; i++) {
    counts.push_back(0);
  }

  // val is in bin1: interval min to bin_width[0]
  for (auto &item : vect) {
    if (item < bin_widths.at(0))
    {
      counts.at(0) ++;
    }
  }

  // val is in bins 2 to 2nd to last bin: interval bin_width[0] to bin_width[bin - 2]
  int k = 1;
  while (k <= bins - 2) 
  {
    for (auto &item : vect) 
    {
      if (item >= bin_widths.at(k - 1) && item < bin_widths.at(k))
      {
        counts.at(k) ++;
      }
    }
    k++;
  }

  // val is in lastbin: interval bin_widths[bins-2] to bin_widths[bins-1]
  for (auto &item : vect) 
  {
    if (item >= bin_widths.at(bins - 2) && item <= bin_widths.at(bins - 1))
    {
      counts.at(bins - 1) ++;
    }
  }

  // find max height of histogram from counts
  int max_height = counts[0];
  for (auto i = 1; i < bins; i++)
  {
    if (counts.at(i) > max_height)
    {
      max_height = counts.at(i);
    }
  }

  // Plot the histogram max_height (row) x bins (column)
  for (auto i = max_height; i >= 1; i--)
  {
    for (unsigned int j = 0; j < counts.size(); j++)
    {
      if (i <= counts.at(j)) {
        std::cout << "*** ";
      } else {
        std::cout << "    ";
      }
    }
    std::cout << std::endl;
  }

}
