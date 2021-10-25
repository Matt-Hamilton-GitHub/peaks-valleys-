
//Write and test a function that counts the number of peaks and the number of valleys in a dynamic,sequential structure of integers.
// A peak is an element of the structure that is greater than its two adjacent neighbors. 
//A valley is an element of the structure that is less than its two adjacent neighbors. 
//The first and last elements of the structure are adjacent neighbors.

//The function returns the number of peaks and the number of valleys in the structure. 
//The function has only one parameter – the sequential structure, returns only one structure – the number of peaks 
//and the number of valleys, uses neither global nor file scope user-defined objects, and uses neither input nor output streams.

#include <iostream>
#include <vector>
#include <random>

using namespace std;
// declaring a structure that stores no of valleys and peaks
struct PandV{
	
    int _valleys{0};
    int _peaks{0};
  
};
// function to count no of peaks and valleys
//

 
//  unsigned int generator(){
//	   random_device rdevice{};
//	default_random_engine num{rdevice()};
//	uniform_int_distribution< unsigned int> randomNum{0,100};
//	
//	return randomNum(num);
//	
//}



void count(struct PandV& strct, vector<int>& vec)
{
    // check if the first or last element is a peak or valley
    
    if(vec[0]>vec[1] && vec[0]>vec [vec.size()-1])
    {
       strct._peaks++;
    }
    
	
    if(vec[vec.size()-1]>vec [0] && vec [vec.size()-1]>vec [vec.size()-2])
    {
        strct._peaks++;
    }
	
	
    if(vec[0] < vec[1] && vec [0]<vec [vec.size()-1])
    {
        strct._valleys++;
    }
   
    if(vec [vec.size()-1]<vec [0] && vec [vec.size()-1]<vec [vec.size()-2])
    {
       strct._valleys++;
    }
	
	//--------------------------------------
	
	
    // check all the other elements in the vector
    for(unsigned int i {1} ;i<vec.size()-1;i++)
    {
	
        if(vec [i]>vec [i-1] && vec [i]>vec [i+1])
        {
           strct._peaks++;
        }
        
        if(vec [i]<vec [i-1] && vec [i]<vec [i+1])
        {
            strct._valleys++;
        }
    }
	
	cout << "\n\tThe sequential structure of integers has: "<< endl;
	cout << "\n\t\tValleys: " << strct._valleys << endl;
	cout << "\t\tPeaks: " << strct._peaks << endl;
	cout << "\n\t************************************* \n\n\n";
    
}


void display(vector<int> v);

int main(){
	
	//so I thought it would be a good idea to generate random numbers inseted of typing each one in or using a tamplate

		random_device rdevice{};
		default_random_engine num{rdevice()};
		uniform_int_distribution< unsigned int> randomNum{0,100};
		
	// random numbers generator engine
   //--------------------------------------------------------------

	vector<int> vec;
	int numOfElem;
	
	cout << "Number of integers in a sequential structure: ";
	cin >> numOfElem;

	for (int x{0}; x < numOfElem; x++ ){
		
		vec.push_back(randomNum(num));
	}
	
	display(vec);
	PandV myStruct;
	count(myStruct,vec);
	
	
	system("pause");
    return 0;
}



void display(vector<int> v){
	
	unsigned int x{0};
	
	cout << "\n\t Numbers generated - [ ";
	while (x < v.size()){
		
		
		cout << v[x] << " ";
		x++;
	}
	cout << " ] \n";
}