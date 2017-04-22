#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define maxProblem 100
using namespace std;

typedef struct{
    std::vector<int> array;
    int sum;
}ResultPair;

int runAlgorithms(string fileName);
void printVector(std::vector<int> vec, int vecLength);
ResultPair mssLinear(std::vector<int> array, int length);


int main(){

    string fileName = "MSS_TestProblems.txt";
    cout << "What file should I read?" << endl;
    //cin >> fileName;
    //We can undo this later


    int results = runAlgorithms(fileName);


    if(results == 1){
        cout << "Bad file read attempt" << endl;
    }

    return 0;
}




//Function to read input file and run all algoritm tests
int runAlgorithms(string fileName){

    //The vector with the problem
    std::vector<int> problem;
    //The vectors number of elements (not really needed but leftover and still used 
    //from the switch to vector from array)
    int problemLength = 0;

    //Open the file and verify it opened
    const char* file = fileName.c_str();
    std::ifstream input;
    input.open(file, std::ifstream::in);
    if(input.fail()){
        cout << "File does not exist, Exiting" << endl;
        return 1;
    }

    //Variables for file parsing
    string line;
    string delimiter = " ";
    size_t pos = 0;
    string token;

    //1. Get/Parse one problem store it in vector<int> problem.
    //2. Run all four algorithms on the vector, time and print the results.
    //3. Repeat for all lines in problem file.
    while(!input.eof()){

        problemLength=0;
        getline(input, line);

        //Find the index of the delimiter, save the number and
        //then remove the value from the line.
        while((pos = line.find(delimiter)) != std::string::npos){
            token = line.substr(0,pos);
            //cout << token << endl;
            problem.push_back(std::atoi(token.c_str()));
            problemLength++;
            line.erase(0,pos+delimiter.length());
        }

        //Due to formatting sometimes the last number won't get read by the
        //above while loop. This checks if there is still a number left in
        //the line and parses it if needed.
        if(line.length() > 0 && (isdigit(line[0]) || (line[0]=='-'))){
           pos=0;
           while(isdigit(line[pos]) || line[pos] =='-'){
               pos=pos+1;
           }
           pos=pos+1;
           token = line.substr(0, pos);
           //cout << token << endl;
           problem.push_back(std::atoi(token.c_str()));
           problemLength++;
        }

        //Print the final vector/problem contents
        cout << endl;
        printVector(problem, problemLength);





        /**
            We should be able to just run our algorithms here. We can each
            make a run through the current problem using the array "problem[]".
            The variable problemLength has the current number of items in problem[].
            We can each make a run with our algorithm, time them, then save the results
            as we go to a file or data structure. This should be a good skeleton to work from.




        **/
        ResultPair alg4Results = mssLinear(problem, problemLength);
        printVector(alg4Results.array, alg4Results.array.size());
        cout << alg4Results.sum << endl << endl;

        //clear the vector
        problem.clear();
    }
    return 0;
}

void printVector(std::vector<int> vec, int vecLength){
    for(int i=0;i<vecLength;i++){
            cout << vec[i];
            if(i+1 != vecLength){
                cout << ", ";
            }
            else{
                cout << endl;
            }

        }
}

ResultPair mssLinear(std::vector<int> array, int length){
    int maxSum = array[0];
    int currMax = array[0];
    int low = 0;
    int high = 0;
    int endLow = 0;
    int endHigh = 0;

    for(int i=1; i<length; i++){
        endHigh = i;
        if(currMax > 0){
            currMax = currMax + array[i];
        }
        else{
            endLow = i;
            currMax = array[i];
        }

        if(currMax > maxSum){
            maxSum = currMax;
            low = endLow;
            high = endHigh;
        }
    }

    std::vector<int> mssArray;
    for(int j=low; j<(high+1); j++){
        mssArray.push_back(array[j]);
    }
    ResultPair results;
    results.array = mssArray;
    results.sum = maxSum;

    return results;
}

