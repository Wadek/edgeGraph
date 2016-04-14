#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

vector<string> commands, edges, dates;
int commandCounter = 0;
int edgesCounter = 0;
int datesCounter = 0;
void graph(vector<string>* commands, vector<string>* dates, vector<string>* edges, int i);

void graph(vector<string>* commands, vector<string>* dates, vector<string>* edges, int i) {
    int startY = atoi((*commands)[i+1].c_str());
    int endY = atoi((*commands)[i+2].c_str());
    int startD = 0;
    int endD = 0;
    int counter = 0;

    //finds the range to be used
    for(int j = 0; j < datesCounter; j++) {
        int temp = atoi((*dates)[j].c_str());
        if( temp == endY+1) {
            endD = j/2;
            break;
        }
    }

    endD = endD+1;
    int datesPatents[endD][400];

    for(int j = 0; j < endD-1; j++) {
        int temp = atoi((*dates)[counter].c_str());
        datesPatents[j][0] = temp;
        counter = counter +2;
    }

    int offset = datesPatents[0][0];

    //find edges and add them to data strcture
    for(int j = 0; j < edgesCounter; j+=2) {
        int row = atoi((*edges)[j].c_str())-offset;
        int index = 1;


        if(row <  endD) {
            while(datesPatents[row][index] != 0) {
                index ++;
            }
            datesPatents[row][index] = atoi((*edges)[j+1].c_str());
        }
    }

    for(int j = 0; j < edgesCounter; j+=2) {
        int row = atoi((*edges)[j].c_str())-offset;
        int index = 1;


        if(row <  endD) {
            while(datesPatents[row][index] != 0) {
                index ++;
            }
        }
    }
    // print out results
    for(int j = 0; j < endD-1; j++) {
        counter = 0;
        while(datesPatents[j][counter] != 0 ) {
            if(counter == 0 && datesPatents[j][counter+1] != 0) {
                cout<<datesPatents[j][counter]<<" ";
            }
            else if(counter != 0 && datesPatents[j][counter] != 0) {
                cout<<datesPatents[j][counter]<<" ";
            }
            counter ++;
        }
        if(datesPatents[j][1] != 0) {
            cout<<endl;
        }
    }
    cout<<endl;
}

void fileToVector() {
    string commandsFile, edgesFile, datesFile, line, line1, line2;
    fstream fileobject ( "commands.txt" ); // open a filestream
    while(getline(fileobject,line)) {
        commandCounter++;
    }
    fileobject.close();

    fstream fileobject0 ( "commands.txt" ); // open a filestream
    while ( fileobject0 >> commandsFile) {
        commands.push_back(commandsFile);
    }
    fileobject0.close();

    fstream fileobject1 ( "edges.txt" ); // open a filestream
    while ( fileobject1 >> edgesFile) {
        edges.push_back(edgesFile);
        edgesCounter++;
    }
    fileobject1.close();


    fstream fileobject2 ( "dates.txt" ); // open a filestream
    while ( fileobject2 >> datesFile) {
        dates.push_back(datesFile);
        datesCounter++;
    }
    fileobject2.close();
    datesCounter = datesCounter/2;
}

int  main()
{
    fileToVector();

    for(int i = 0; i< commandCounter; i++) {
        if(commands[i] == "graph") {
            graph(&commands, &dates, &edges,i);
        }
    }
    return 0;
}
