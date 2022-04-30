//
// Created by beloin on 25/04/2022.
//

#include "HTTPRequester.h"
#include <cmath>
#include "random"
#include "iostream"

using namespace std;

HTTPRequester::HTTPRequester(double sizeMultiplier){
    int size = floor(defaultSize * sizeMultiplier);

    veryHeavyMatrix = new double**[size];
    for (int i = 0; i < size; ++i) {
        veryHeavyMatrix[i] = new double*[size];
        for (int j = 0; j < size; ++j) {
            veryHeavyMatrix[i][j] = new double[size];
            for (int k = 0; k < size; ++k) {
                this->veryHeavyMatrix[i][j][k] = (rand() % 10000) * 0.1;
            }
        }
    }
}

void HTTPRequester::makeRequest(string url, string body, string method) {
    cout << "Request:\n";
    cout << method << " " << url << endl;
    cout << "Body: " << body << endl;
}

