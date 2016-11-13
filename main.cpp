#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//uppercase array for sub
 const string UPPERCASE[31] = {"A","B","C","D","E","F","G","H","I","J","K","L","M",
    "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," ",",","!",".","\n"};

//lowercase array for sub
 const string LOWERCASE[31] = {"a","b","c","d","e","f","g","h","i","j","k","l","m",
    "n","o","p","q","r","s","t","u","v","w","x","y","z"," ",",","!",".","\n"};

//Get the char and return the int value
int frequency_counter(string s){
    for(int i = 0; i < 31; i++) 
        if(s == UPPERCASE[i] || s == LOWERCASE[i]) return i;
    return -1;
}

//Output the analysis of the letter frequency
void output_frequency(int total, int f[]){

    string table[31] = {"A","B","C","D","E","F","G","H","I","J","K","L","M",
    "N","O","P","Q","R","S","T","U","V","W","X","Y","Z","SP",",","!",".","NL"};

    for(int i = 0; i < 31; i++)
        cout << table[i] << ": " << ((double)f[i]/total) * 100 
             << "% \t, " << f[i] << "/" << total << endl;
}

string calculate_frequency (int * frequency) {
    string line, message;
    ifstream infile("problem1.enc");
    
    char character;
    while(!infile.eof()) {
        infile >> noskipws >> character;
        message.push_back(character);
    }
    
    message.pop_back();
    
    for(int i = 0; i < message.size(); i++) 
        frequency[frequency_counter(message.substr(i,1))] += 1;
        
    int totalsize = message.size();
    output_frequency(totalsize,frequency);
    return message;
}

int main(int argc, char * argv[]) {
    int frequency[31] = {0};
    vector<int> factors;
    string message = calculate_frequency(frequency);

    for(int i = 1; i <= message.size(); i++) {
        if(message[i - 1] == '\n') message[i - 1] = ';';
        if(message.size() % i == 0) {
            if(i >= 4) {
                cout << i << " ";
                factors.push_back(i);
            }
        }
    }
    cout << endl;

    cout << endl << message << endl << endl;
    
    return 0;
}