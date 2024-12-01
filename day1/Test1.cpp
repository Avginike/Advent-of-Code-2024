// Complete!
// Answer was: 2086478


#include <iostream>


#include <utility>
#include <list>
#include <iterator>
#include <algorithm>


#include <string>
#include <fstream>

using namespace std;

typedef list<int> num_list;
typedef pair<num_list,num_list> list_pair;

list_pair ParseInput(istream& in)
{
    list_pair out;
    while(!in.bad() && !in.eof())
    {
        int temp;
        in >> temp;
        out.first.push_back(temp);
        in >> temp;
        out.second.push_back(temp);
    }
    return out;
}   

// returns the smallest element and removes it from the list
int DeleteSmallest(num_list& list)
{
    num_list::iterator smallest = min_element(list.begin(), list.end());

    int value = *smallest;

    list.erase(smallest);

    return value;

}





int main(int argc, char *argv[]) {
    
    
   if(argc != 2)
   {
        cout << "Pass the input as the 1st argument!";
        return 1;
   }
   
   string file_path(argv[1]);

    ifstream input_file;
    input_file.open(file_path);

    list_pair input_pair = ParseInput(input_file);

    input_file.close();

    int length = input_pair.first.size();

    int total{0};

    for(int i = 0; i < length; i++)
    {
        int x = DeleteSmallest(input_pair.first);
        int y = DeleteSmallest(input_pair.second);

        int difference = abs(x - y);

        total += difference;
    }

    
    cout << total;
    


    
    
    return 0;
}


