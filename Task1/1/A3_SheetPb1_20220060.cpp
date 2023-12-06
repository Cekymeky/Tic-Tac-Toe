#include <bits/stdc++.h>

using namespace std;

class LabelGenerator
{
private:
    string prefix;
    int currIndex;

public:
    LabelGenerator(string prefix, int currIndex) : prefix(prefix), currIndex(currIndex) {}
    virtual string nextLabel();
};

class FileLabelGenerator : LabelGenerator
{
private:
    string fileName;
    ifstream fileStream;

public:
    FileLabelGenerator(string prefix, int currIndex, string fileName) : LabelGenerator(prefix, currIndex), fileName(fileName)
    {
        fileStream.open(fileName);
    }
    ~FileLabelGenerator()
    {
        fileStream.close();
    }

    virtual string nextLabel();
};

string LabelGenerator::nextLabel()
{
    return prefix + to_string(currIndex++);
}

string FileLabelGenerator::nextLabel()
{
    string firstLabel = LabelGenerator::nextLabel();
    string secondLabel;

    if (fileStream.is_open() && getline(fileStream, secondLabel))
    {
        return firstLabel + " " + secondLabel;
    }

    return firstLabel;
}

int main()
{
    FileLabelGenerator figureLabels("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << figureLabels.nextLabel() << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << figureLabels.nextLabel() << endl;
    }
}