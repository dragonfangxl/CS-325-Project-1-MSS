#include <iostream>
#include <fstream>
#include <string>
#define maxProblem 100

using namespace std;

int runAlgorithms(string fileName);

int main(){

    string fileName="MSS_TestProblems.txt";
    cout << "What file should I read?" << endl;
    //cin >> fileName;
    //We can undo this later






    int results = runAlgorithms(fileName);





    if(results == 1){
        cout << "Bad file read attempt" << endl;
    }

    return 0;
}

int runAlgorithms(string fileName){

    int problem[maxProblem]={0};
    int problemLength=0;

    const char* file = fileName.c_str();
    std::ifstream input;
    input.open(file, std::ifstream::in);
    if(input.fail()){
        cout << "File does not exist, Exiting" << endl;
        return 1;
    }

    string line;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    std::string::size_type sz;

    while(!input.eof()){

        problemLength=0;
        getline(input, line);
        while((pos = line.find(delimiter)) != std::string::npos){
            token = line.substr(0,pos);
            //cout << token << endl;
            problem[problemLength] = std::stoi(token, &sz);
            problemLength++;
            line.erase(0,pos+delimiter.length());
        }

        if(line.length() > 0 && (isdigit(line[0]) || (line[0]=='-'))){
           pos=0;
           while(isdigit(line[pos]) || line[pos] =='-'){
               pos=pos+1;
           }
           pos=pos+1;
           token = line.substr(0, pos);
           //cout << token << endl;
           problem[problemLength] = std::stoi(token, &sz);
           problemLength++;
        }
        /*
        cout << endl << endl;
        for(int j=0;j<problemLength;j++){
            cout << problem[j] << endl;
        }
        cout << endl << endl;
        */

    }


    /**
        We should be able to just run our algorithms here. We can each
        make a run through the current problem using the array "problem[]".
        The variable problemLength has the current number of items in problem[].
        We can each make a run with our algorithm, time them, then save the results
        as we go to a file or data structure. This should be a good skeleton to work from.




    **/
    return 0;
}