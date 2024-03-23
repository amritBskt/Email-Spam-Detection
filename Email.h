// File: Email.h
// Description: Header file for the Email class used in the spam detection project.

#pragma once

#include <vector> // Include vector library
#include <string> // Include string library

// Declaration of constants
extern const int WORDS_SET_SIZE; // Size of the fixed word set
extern const double OFF_SET; // Offset value for calculations

using std::vector; // Import vector from the standard library
using std::string; // Import string from the standard library

class Email {
 private: 
	 int word_set_size_; // Size of the fixed word set for all email objects
	 vector<double> words_frequency_; // Frequency of words (from the word set) in the email
	 int spam_or_ham_; // 0 for spam, 1 for ham								 
	 double num_words_; // Total number of words in this email

 public:
	 // Constructor
	 Email();
	 // Destructor
	 ~Email();

	 // Function to determine if the email is ham or spam
	 int isHam() const;

	 // Function to return the total number of words
	 double numWords() const; 

	 // Function to return words frequency
	 const vector<double>& wordsFrequency() const;

	 // Function to set email data
	 void setEmailData(string& email_data);
};
