///////////////////////////////////////////////////////////////////////////////
// experiment.cc
//
// Example code showing how to run an algorithm once and measure its elapsed
// time precisely. You should modify this program to gather all of your
// experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

#include "project2.hh"
#include "timer.hh"

using namespace std;

int main() {

  string_vector all_words;
  if ( ! load_words(all_words, "words.txt") ) {
    cerr << "error: cannot open \"words.txt\"" << endl;
    return 1;
  }

  ofstream trials;
  trials.open("trials.txt");

  trials << "Mergesort\n";
  for(int n = 5000; n <= 5000; n += 1000){
    for(int j = 1; j <= 500; j++){
      string_vector n_words(all_words.begin(), all_words.begin() + n);

      randomize_list(n_words);

      Timer timer;
      mergesort(n_words);
      double elapsed = timer.elapsed();
      cout << "mergesort, "
           << "Trial: " << j << ", "
           << "elapsed time = " << elapsed << " seconds" << endl;
      trials << "Trials: " << j << ", "
             << "Time: " << elapsed << " seconds" << endl;
    }
    cout << endl;
  }

  trials << "\nQuicksort\n";
  for(int n = 5000; n <= 5000; n += 1000){
    for(int j = 1; j <= 500; j++){
      string_vector n_words(all_words.begin(), all_words.begin() + n);

      randomize_list(n_words);

      Timer timer;
      quicksort(n_words);
      double elapsed = timer.elapsed();
      cout << "quicksort, "
           << "Trial: " << j << ", "
           << "elapsed time = " << elapsed << " seconds" << endl;
      trials << "Trials: " << j << ", "
             << "Time: " << elapsed << " seconds" << endl;
    }
    cout << endl;
  }

  trials.close();

  return 0;
}



