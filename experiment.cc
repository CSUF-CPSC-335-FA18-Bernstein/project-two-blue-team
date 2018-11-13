///////////////////////////////////////////////////////////////////////////////
// experiment.cc
//
// Example code showing how to run an algorithm once and measure its elapsed
// time precisely. You should modify this program to gather all of your
// experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "project2.hh"
#include "timer.hh"

using namespace std;

int main() {

  string_vector all_words;
  if ( ! load_words(all_words, "words.txt") ) {
    cerr << "error: cannot open \"words.txt\"" << endl;
    return 1;
  }

  for(int n = 1000; n <= 5000; n += 1000){
    for(int j = 0; j < 5; j++){
      string_vector n_words(all_words.begin(), all_words.begin() + n);

      randomize_list(n_words);

      Timer timer;
      mergesort(n_words);
      double elapsed = timer.elapsed();
      cout << "mergesort, "
           << "n=" << n << ", "
           << "elapsed time = " << elapsed << " seconds" << endl;
    }
    cout << endl;
  }
  cout << endl;

  for(int n = 1000; n <= 5000; n += 1000){
    for(int j = 0; j < 5; j++){
      string_vector n_words(all_words.begin(), all_words.begin() + n);

      randomize_list(n_words);

      Timer timer;
      quicksort(n_words);
      double elapsed = timer.elapsed();
      cout << "quicksort, "
           << "n=" << n << ", "
           << "elapsed time = " << elapsed << " seconds" << endl;
    }
    cout << endl;
  }

  return 0;
}



