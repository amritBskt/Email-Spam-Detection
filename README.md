# Email Spam Detection

This project implements a Naive Bayes classifier for detecting spam emails. The model is trained using a dataset of emails, which are classified as either spam or ham (non-spam). The classifier uses the frequency of specific words in the emails to predict the likelihood of an email being spam.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Data](#data)
- [Results](#results)
- [License](#license)

## Introduction

Email spam detection is an important application of machine learning, helping to filter out unwanted emails and improve user experience. This project utilizes a Naive Bayes approach to classify emails based on the frequency of certain words.

## Features

- Implements a Naive Bayes classifier for spam detection.
- Trains on a dataset of labeled emails.
- Calculates the probability of each word being in a spam or ham email.
- Classifies new emails based on the trained model.

## Installation

To get started with this project, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/amritBskt/email-spam-detection.git
   ```
2. Navigate to the project directory:
   ```sh
   cd email-spam-detection
   ```
3. Ensure you have a C++ compiler installed.

## Usage

1. Compile source folder:
  ```sh
  g++ spamDetect.cpp Email.cpp -o spamDetect
  ```

2. Run the program:
   ```sh
   ./spamDetect
   ```

## Data
The dataset consists of two files: training_set.data and test_set.data. Each file contains emails represented by the frequency of certain words and a label indicating whether the email is spam (0) or ham (1).

## Result
The program outputs the following statistics after running the classification:
- Total number of emails in the training and test sets.
- Number of spam and ham emails in the training and test sets.
- Number of correct and incorrect classifications.
- Prediction accuracy.

## License
This project is licensed under the MIT License.

## Contact

- GitHub: [amritBskt](https://github.com/amritBskt)
- Email: your-amritbskt7@gmail.com

