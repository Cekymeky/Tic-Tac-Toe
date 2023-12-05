#include <bits/stdc++.h>
using namespace std;

// Class representing a process
class Process
{
public:
    string name;
    string pid;
    string memoryUsage;

    // Constructor to initialize process details
    Process(string &n, string id, string mem)
        : name(n), pid(id), memoryUsage(mem) {}

    // Overloaded less-than operator to enable sorting processes by name
    bool operator<(const Process &other) const
    {
        return name < other.name;
    }
};

// Class representing a list of processes
class ProcessList
{
private:
    vector<Process> processes;

public:
    // Method to fill the list of processes by executing 'tasklist' command
    void fill()
    {
        processes.clear();
        remove("tasks.txt");
        string command = "tasklist > tasks.txt";
        system((command).c_str());

        ifstream taskFile;
        taskFile.open("tasks.txt");
        string line;
        int lineNum = 0;

        // Parsing the output of 'tasklist' command to extract process information
        while (getline(taskFile, line))
        {
            if (lineNum == 3) // The data starts in the 3rd line
            {
                // Extracting process name, PID, and memory usage
                string n = line.substr(0, 25);
                string id = line.substr(26, 8);
                string mem = line.substr(64, 12);
                Process temp(n, id, mem);
                processes.push_back(temp);
            }
            else
                lineNum++;
        }
        // Close and delete the file after finishing
        taskFile.close();
        remove("tasks.txt");
    }

    // Method to display the list of processes
    void display()
    {
        for (auto &process : processes)
        {
            cout << "Name: " << process.name << "\tPID: " << process.pid
                 << "\tMemory Usage: " << process.memoryUsage << " bytes\n";
        }
    }

    // Method to sort processes by memory usage in ascending order
    void sortByMemoryUsage()
    {
        sort(processes.begin(), processes.end(),
             [](Process &a, Process &b)
             { return a.memoryUsage < b.memoryUsage; });
    }

    // Method to sort processes by name in ascending order
    void sortByName()
    {
        sort(processes.begin(), processes.end());
    }

    // Method to sort processes by PID in ascending order
    void sortByPID()
    {
        sort(processes.begin(), processes.end(),
             [](Process &a, Process &b)
             { return a.pid < b.pid; });
    }
};

int main()
{
    // Creating an instance of ProcessList
    ProcessList processList;

    // Filling the list of processes
    processList.fill();

    // Displaying processes sorted by name
    std::cout << "Processes (sorted by name):\n";
    processList.sortByName();
    processList.display();

    // Displaying processes sorted by PID
    std::cout << "\nProcesses (sorted by PID):\n";
    processList.sortByPID();
    processList.display();

    // Displaying processes sorted by memory usage
    std::cout << "\nProcesses (sorted by memory usage):\n";
    processList.sortByMemoryUsage();
    processList.display();

    return 0;
}
