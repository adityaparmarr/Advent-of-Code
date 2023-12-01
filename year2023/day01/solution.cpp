#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Implement cout for vectors
template <typename S>
ostream &operator<<(ostream &os, const vector<S> &vector) {
  os << "[";
  for (int i = 0; i < vector.size(); i++) {
    auto element = vector[i];
    os << element;
    if (i != vector.size() - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

vector<int> substring1(string s, string sub_s) {

  vector<int> indices;

  // return the start indices of each occurrence of sub_s in s
  for (int i; i < s.length(); i++) {

    if (s[i] != sub_s[0]) {
      continue;
    }
    bool found_occurrence = false;
    for (int j = 1; j < sub_s.length(); j++) {
      if (s[i+j] == sub_s[j]) {
        found_occurrence = true;
        }
    }
    if (found_occurrence) {
      indices.push_back(i);
    }
  }
  return indices;
}

void part1(vector<string> input) {
  int result = 0;
  for (string s : input) {
    int first = -1, last = -1;
    for (char c : s) {
      if ('0' <= c && c <= '9') {
        if (first == -1) {
          first = c - '0';
        }
        last = c - '0';
      }
    }
    int num = first * 10 + last;
    result += num;
  }
  cout << "Part 1: " << result << endl;
}

void part2(vector<string> input) {
  int result = 0;
  for (string s : input) {
    int first = -1, last = -1;

    vector<string> digit_words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    for (int i = 0; i < 9; i++) {
      vector<int> digit_word_indices =  substring1(s, digit_words[i]);
      vector<int> digits_indices =  substring1(s, digits[i]);

      int minimum = min(digit_word_indices[0], digits_indices[0]);
      int maximum = max(digit_word_indices[0], digits_indices[0]);

      first = min(minimum, first);
      last = max(maximum, last);
    }

    int num = first * 10 + last;
    result += num;
  }
  cout << "Part 2: " << result << endl;
}



vector<string> read_input() {
  ifstream input_file;
  input_file.open("input.txt");
  vector<string> input;
  while (input_file.good()) {
    string line;
    getline(input_file, line);
    input.push_back(line);
  }
  return input;
}

int main() {
  ios_base::sync_with_stdio(0);
  vector<string> input = read_input();
  // vectors are pass by value, no copying needed
  part1(input);
  part2(input);
  return 0;
}
