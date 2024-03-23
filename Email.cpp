#include "Email.h"
#include<iostream>
#include<sstream>

using std::vector;
using std::string;
using std::stringstream;

Email::Email(){
    // Initializes the email object.
	word_set_size_ = WORDS_SET_SIZE;
	vector<double> tmp(WORDS_SET_SIZE,0);
	words_frequency_ = tmp;
	spam_or_ham_ = 0;
	num_words_ = 0;
}

Email::~Email(){}

// Determines if the email is categorized as ham or spam.
int Email::isHam() const{
    return spam_or_ham_;
}

// Returns the total number of words in the email.
double Email::numWords() const {
    return num_words_;
}

// Returns the frequency of words in the email.
const vector<double>& Email::wordsFrequency() const{
    return words_frequency_;
}

// Sets email data, parsing the input string and populating the email object.
void Email::setEmailData(string& email_data){
	// Parses the email data string.
	stringstream ss(email_data);
	string s;
	for(int i=0;i<word_set_size_+1;i++){
		getline(ss,s,',');
		stringstream toNumber(s);
		if(i == word_set_size_){
			toNumber>>spam_or_ham_; // Determines if the email is spam or ham.
		}else{
			toNumber>>words_frequency_[i];
			words_frequency_[i] += OFF_SET; // Adds a small value to avoid zero frequency.
			num_words_ += words_frequency_[i]; // Calculates the total number of words.
		}
	}	
}
