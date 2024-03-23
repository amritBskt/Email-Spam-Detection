#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<math.h>
#include<vector>
#include"Email.h" // Including the header file for Email class

using namespace std;

const int WORDS_SET_SIZE = 57;   // Number of distinct words used for spam detection
const double OFF_SET = 1.0/4000; // Offset value for calculations

// Overloading addition operator for vectors
vector<double> operator+(vector<double>& A, const vector<double>& B);

int main(){
    // Initializing variables and vectors for storing data and calculations
    vector<double> num_words_spam(WORDS_SET_SIZE,0);  // Total occurrence of words in spam emails
    vector<double> num_words_ham(WORDS_SET_SIZE,0);   // Total occurrence of words in ham emails
    int num_spam = 0;  // Total number of spam emails
    int num_ham = 0;   // Total number of ham emails 

    vector<double> word_probability_spam(WORDS_SET_SIZE,0);  // Probability of words in spam emails
    vector<double> word_probability_ham(WORDS_SET_SIZE,0);   // Probability of words in ham emails

    // Reading data from training_set
    ifstream file; 
    file.open("training_set.data");
    if(!file){
        cerr<<"file cannot be open";
        exit(1);
    }

    Email* my_email = new Email(); // Creating an instance of Email class
    string email_data; // Variable to store email data from file

    // Looping through each line of data in the training set
    while(!file.eof()){
        getline(file,email_data);
        my_email->setEmailData(email_data); // Setting email data using Email class method

        // Counting words in spam and ham emails based on classification
        if(my_email->isHam() == 0){
            num_spam++;
            num_words_spam = num_words_spam + my_email->wordsFrequency();
        }
        if(my_email->isHam() == 1){
            num_ham++;
            num_words_ham = num_words_ham + my_email->wordsFrequency();
        }
    }
    file.close();

    // Calculating word probabilities for spam and ham emails
    double total_words_spam = 0;
    double total_words_ham = 0;

    // Summing up the occurrence of each word in spam and ham emails
    for(int i=0;i<57;i++){
        total_words_spam += num_words_spam[i];
        total_words_ham += num_words_ham[i];
    }

    // Calculating log probabilities for each word in spam and ham emails
    for(int i=0;i<57;i++){
        word_probability_spam[i] = log(num_words_spam[i]/total_words_spam);
        word_probability_ham[i] = log(num_words_ham[i]/total_words_ham);
    }

    // Reading emails from the test_set and predicting their classification
    int num_test_email = 0;
    int num_ham_in_test = 0;
    int num_spam_in_test = 0;

    int ham_predict_as_ham = 0;
    int spam_predict_as_spam = 0;
    int ham_predict_as_spam = 0;
    int spam_predict_as_ham = 0;

    ifstream test;
    test.open("test_set.data");
    if(!test){
        cerr<<"cannot open the test set";
        exit(1);
    }

    while(!test.eof()){
        getline(test,email_data);
        my_email->setEmailData(email_data);
        num_test_email++;

        // Calculating log ratio for spam/ham classification
        double log_ratio=0;

        for(int i=0;i<57;i++){
            log_ratio += word_probability_spam[i]*((my_email->wordsFrequency())[i])
                - word_probability_ham[i]*((my_email->wordsFrequency())[i]);
        }
        log_ratio += log((double)num_spam) - log((double)num_ham);

        // Predicting email classification and counting correct/incorrect predictions
        if(!my_email->isHam()) {num_ham_in_test++;}
        else {num_spam_in_test++;}
        if(log_ratio<0 && my_email->isHam()) ham_predict_as_ham++;
        if(log_ratio<0 && !my_email->isHam()) spam_predict_as_ham++;
        if(log_ratio>0 && my_email->isHam()) ham_predict_as_spam++;
        if(log_ratio>0 && !my_email->isHam()) spam_predict_as_spam++;
    }
    test.close();

    // Displaying the results
    cout<<"The training set has "<<(num_ham + num_spam)<<" emails"<<endl;
    cout<<"Spam emails: "<<num_spam<<endl;
    cout<<"Ham emails: "<<num_ham<<endl;
    
    cout<<"The test set has "<<num_test_email<<" emails"<<endl;
    cout<<"Spam emails: "<<num_spam_in_test<<endl;
    cout<<"Ham emails: "<<num_ham_in_test<<endl;
    cout<<"Ham predicted as ham: "<<ham_predict_as_ham<<endl;
    cout<<"Spam predicted as spam: "<<spam_predict_as_spam<<endl;
    cout<<"Spam predicted as ham: "<<spam_predict_as_ham<<endl;
    cout<<"Ham predicted as spam: "<<ham_predict_as_spam<<endl;
    cout<<"The prediction accurary is: "<<
        (ham_predict_as_ham+spam_predict_as_spam)*1.0/num_test_email*100<<
        " percents"<<endl;
    system("pause");
    return 1;
}

// Overloaded addition operator for vectors
vector<double> operator+(vector<double>& A, const vector<double>& B){
    if(A.size()!=B.size()){
        throw "The sizes of the two vector objects are not equal";
    }
    vector<double> ans;
    for(int i=0;i<A.size();i++){
        ans.push_back(A[i]+B[i]);
    }
    return ans;
}
