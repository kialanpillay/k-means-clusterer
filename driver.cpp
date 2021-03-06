#include <iostream>
#include <fstream>
#include <sstream>
#include "clusterer.h"

using namespace std;

int main(int argc, char* argv[])
{
    string output = "std";
    string dataset = argv[1];
    int bin = 1;
    int clusters = 10;
    bool color = false;
    bool hsv = false;
    if(argc < 2){
        cout << "Incorrect number of arguments!" << endl;
        exit(1);
    }

    for(int i = 2; i < argc ; i+=2){
        string flag = argv[i];
        if(flag!="-color"&&flag!="-hsv"){
            string arg = argv[i+1];
            if(flag.find("-o") != std::string::npos){
                output = arg;
            }
            if(flag.find("-k") != std::string::npos){
                clusters = stoi(arg);
            }
            if(flag.find("-b") != std::string::npos){
                bin = stoi(arg);
            }
        }
        else{
            if(flag=="-color"){
                color = true;
            }
            else{
                hsv = true;
            }
            
            break;
        }
    }
    if(0 >= clusters || bin > 256 || bin < 1){
        cout << "Invalid arguments supplied. numClusters > 1 and binSize in [1,256]" << endl;
        exit(1);
    }

    PLLKIA010::KMeansClusterer kt(dataset, bin, clusters, color, hsv);
    cout << "K-Means Image Clustering" << std::endl;
    cout << "================================================" << std::endl;
    if(output == "std"){
        cout << kt;
    }
    else{
        std::ofstream out(output);
        out << kt;
        cout << "Clustering Results Saved!";
    }
    
    return 0;
}
