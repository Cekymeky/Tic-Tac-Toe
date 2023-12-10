// File name: A3_SheetPb2_20220287.cpp
// Purpose:
// Author(s): Mohammad Zeinhom Anwar
// ID(s): 20220287
// Section: s29
// Date: 12/09/2023
#include <bits/stdc++.h>
using namespace std;

// Class to represent a set of unique words
class StringSet
{
private:
    vector<string> query; // Vector to store unique words

public:
    // Default constructor
    StringSet(){};

    // Constructor that takes a string or file name and populates the set with unique words
    StringSet(string data);

    // Method to add a word to the set
    void add(string keyword);

    // Method to remove a word from the set
    void remove(string keyword);

    // Method to clear the set
    void clear();

    // Method to get the size of the set
    int getSize();

    // Method to print the contents of the set
    void print();

    // Overloaded + operator to perform set union
    StringSet operator+(StringSet &other);

    // Overloaded * operator to perform set intersection
    StringSet operator*(StringSet &other);

    // Method to calculate the similarity coefficient between two sets
    float similarity(StringSet &other);
};

// Constructor implementation
StringSet::StringSet(string data)
{
    vector<string> notUnique; // Temporary vector to store non-unique words
    ifstream file;
    file.open(data);

    // Read from file or use the provided string to populate the notUnique vector
    if (file.is_open())
    {
        // Read from file line by line
        string line;
        while (getline(file, line))
        {
            string currentWord;
            for (char c : line)
            {
                c = tolower(c);
                if (isalnum(c))
                {
                    currentWord += c;
                }
                else if (!currentWord.empty())
                {
                    notUnique.push_back(currentWord);
                    currentWord.clear();
                }
            }
            if (!currentWord.empty())
            {
                notUnique.push_back(currentWord);
            }
        }
    }
    else
    {
        // Read from the provided string
        string currentWord;
        for (char c : data)
        {
            c = tolower(c);
            if (isalnum(c))
            {
                currentWord += c;
            }
            else if (!currentWord.empty())
            {
                notUnique.push_back(currentWord);
                currentWord.clear();
            }
        }
        if (!currentWord.empty())
        {
            notUnique.push_back(currentWord);
        }
    }

    // Populate the query vector with unique words
    for (auto word : notUnique)
    {
        if (std::find(query.begin(), query.end(), word) == query.end())
        {
            query.push_back(word);
        }
    }
}

// Method to add a word to the set
void StringSet::add(string keyword)
{
    string word = keyword;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    if (std::find(query.begin(), query.end(), word) == query.end())
    {
        query.push_back(word);
    }
}

// Method to remove a word from the set
void StringSet::remove(string keyword)
{
    // Use std::remove_if with a lambda function to remove the specified word
    query.erase(std::remove_if(query.begin(), query.end(), [keyword](const string &s)
                               { return s == keyword; }),
                query.end());
}

// Method to clear the set
void StringSet::clear()
{
    query.clear();
}

// Method to get the size of the set
int StringSet::getSize()
{
    return query.size();
}

// Method to print the contents of the set
void StringSet::print()
{
    for (auto &word : query)
    {
        cout << word << ' ';
    }
    cout << endl;
}

// Overloaded + operator to perform set union
StringSet StringSet::operator+(StringSet &other)
{
    StringSet Union;
    for (auto e : query)
    {
        Union.add(e);
    }
    for (auto e : other.query)
    {
        Union.add(e);
    }
    return Union;
}

// Overloaded * operator to perform set intersection
StringSet StringSet::operator*(StringSet &other)
{
    StringSet Intersection;

    // Use find to check if each word in the current set exists in the other set
    for (auto e : query)
    {
        if (std::find(other.query.begin(), other.query.end(), e) != other.query.end())
        {
            Intersection.add(e);
        }
    }
    return Intersection;
}

// Method to calculate the similarity coefficient between two sets
float StringSet::similarity(StringSet &other)
{
    // If both are empty so they are perfectly similar
    if (!this->getSize() && !other.getSize())
        return 1;

    // If one of them is empty so they are totally different
    else if (!this->getSize() || !other.getSize())
        return 0;

    float sim = (*this * other).query.size() / ((sqrtf(query.size())) * (sqrtf(other.query.size())));
    return sim;
}

// Main function
int main()
{
    // Create a StringSet object using data from a file
    StringSet s1("data.txt");
    s1.print();

    // Remove a word and print the updated set
    s1.remove("and");
    s1.print();

    // Add a word and print the updated set
    s1.add("AND");
    s1.print();

    // Create another StringSet object using a provided string
    StringSet s2("Hello, world! This is a sample string. And Hello, world!");
    s2.print();
}
