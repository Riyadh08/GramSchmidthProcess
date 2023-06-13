/*
Name:Robiul Islam Riyadh
ROLL: 2007008
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute the dot product of two vectors
double dotProduct(const vector<double>& v1, const vector<double>& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to subtract vector v2 from v1
vector<double> subtractVectors(const vector<double>& v1, const vector<double>& v2) {
    vector<double> result(v1.size());
    for (size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] - v2[i];
    }
    return result;
}

// Function to compute the orthogonal vectors using Gram-Schmidt process
vector<vector<double>> computeOrthogonalVectors(const vector<vector<double>>& inputVectors) {
    vector<vector<double>> orthogonalVectors;
    for (const auto& inputVector : inputVectors) {
        vector<double> orthogonalVector = inputVector; // Initialize with input vector

        // Subtract projections of previous orthogonal vectors
        for (const auto& prevVector : orthogonalVectors) {
            double projection = dotProduct(inputVector, prevVector) / dotProduct(prevVector, prevVector);
            for (size_t i = 0; i < orthogonalVector.size(); i++) {
                orthogonalVector[i] -= projection * prevVector[i];
            }
        }

        orthogonalVectors.push_back(orthogonalVector);
    }
    return orthogonalVectors;
}

// Function to normalize a vector to make it unit length
vector<double> normalizeVector(const vector<double>& v) {
    vector<double> result(v.size());
    double magnitude = sqrt(dotProduct(v, v));
    for (size_t i = 0; i < v.size(); i++) {
        result[i] = v[i] / magnitude;
    }
    return result;
}

// Function to compute the orthonormal vectors from the orthogonal vectors
vector<vector<double>> computeOrthonormalVectors(const vector<vector<double>>& orthogonalVectors) {
    vector<vector<double>> orthonormalVectors;
    for (const auto& orthogonalVector : orthogonalVectors) {
        vector<double> orthonormalVector = normalizeVector(orthogonalVector);
        orthonormalVectors.push_back(orthonormalVector);
    }
    return orthonormalVectors;
}

int main() {
    // Input vectors
    vector<vector<double>> inputVectors = {{0, 2, 1, 0},
                                           {1, -1, 0, 0},
                                           {1, 2, 0, -1},
                                           {1, 0, 0, 1}};

    // Compute the orthogonal vectors
    vector<vector<double>> orthogonalVectors = computeOrthogonalVectors(inputVectors);

    // Compute the orthonormal vectors
    vector<vector<double>> orthonormalVectors = computeOrthonormalVectors(orthogonalVectors);

    // Output the orthogonal vectors
    cout << "Orthogonal vectors:" << endl;
    for (const auto& orthogonalVector : orthogonalVectors) {
        for (double value : orthogonalVector) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Output the orthonormal vectors
    cout << "Orthonormal vectors:" << endl;
    for (const auto& orthonormalVector : orthonormalVectors) {
        for (double value : orthonormalVector) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
