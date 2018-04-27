/**
 * Author: Lewis Brockman-Horsley
 * Date Created: 27 April 2018
 * Purpose: Simulate and election, generate votes to a file
 *          and then count the votes.
 * */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

void emulateElection()
{
    ofstream lVotes;
    lVotes.open("ballots.txt", ios::out);
    if (!lVotes.good())
    {
        cerr << "Cannot create file" << endl;
        exit(EXIT_FAILURE);
    }
    //generate votes
    int ballot[5] = { 1, 2, 3, 4, 5};
    for (int k = 0; k < 75000; k++)
    {
        int x = 0; //generate a list of random non-repeating numbers
        for (int i = 0; i < 5; i++)
        {
            ballot[i] = rand()%5+1;
            x = 0;
            while (x < i)
            {
                if (ballot[i] == ballot[x])
                {
                    ballot[x] = rand()%5+1;
                    i = 0;
                }
                else
                {
                    x++;
                }
            }     
        }
        for (int p = 0; p < 5; p++)
        {
            lVotes << ballot[p] << " "; //print the votes to a file
        }
        lVotes << endl;
    }
    lVotes.close();
}
void determineFirstPreference()
{
    ifstream lVotes;
    lVotes.open("ballots.txt", ios::in);
    if (!lVotes.good())
    {
        cerr << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }
    int preferences[5] = {0, 0, 0, 0, 0};
    int Vote;
    cout << "Counting first preference..." << endl;
    while(!lVotes.eof())
    {
        for (int i = 0; i < 5; i++)
        {
            lVotes >> Vote;
            if (Vote == 1)
            {
                preferences[i]++; //count first preferences
            }
        }
    }
    double percent[5]; //turn votes into percentages
    for (int f = 0; f < 5; f++)
    {
        percent[f] = double(preferences[f]) / 75000;
    }
    char candidates[5] = {'A', 'B', 'C', 'D', 'E'}; //candidate names
    for (int i = 0; i < 5; i++)
    {
        cout << candidates[i] << ": " << setprecision(4) << percent[i] * 100 << "%" << endl;
    }
    if (*max_element(percent, percent+5) > double(1)/3)
    {
        cout << "The winner is " << candidates[distance( percent, max_element(percent, percent + 5))] << endl;
    }
    else
    {
        cout << "Eliminate Candidate: : " << candidates[distance( percent, min_element(percent, percent + 5))] << endl;
    }
    lVotes.close();
}
int main()
{
    srand(time(NULL));
    emulateElection();
    determineFirstPreference();
    return 0;
}