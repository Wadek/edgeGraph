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


    if(startY == endY) {
        startD = 0;
        for(int j = 0; j < datesCounter; j++) {
            int temp = atoi((*dates)[j].c_str());
            if( temp == endY+1) {
                cout<<"here"<<endl;
                endD = floor(j/2);
                cout<<"here"<<endl;
                break;
            }
        }
    }
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

    edgesCounter = edgesCounter/2;

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
