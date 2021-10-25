
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

// declaring a structure that stores number of valleys and peaks, and a vector that contains the numbers
struct PandV{
	
    int _valleys{0};
    int _peaks{0};
	
	vector<int> _vec;  // store integers and its size can change dynamically
  
  
  //function to display the vector 
  void display(){
	
	unsigned int x{0};
	
	cout << "\n\t Numbers generated - [ ";
	while (x < _vec.size()){
		
		
		cout << _vec[x] << " ";
		x++;
	}
	cout << " ] \n";
}
  
};

// function to count the number of peaks and valleys in a sequential structure of integers
//The function returns the number of peaks and the number of valleys in the structure. 
//The function has only one parameter – the sequential structure, returns only one structure – the number of peaks 
//and the number of valleys, uses neither global nor file scope user-defined objects, and uses neither input nor output streams.
struct PandV count(struct PandV strct);


int main(){
	
	//so I thought it would be a good idea to generate random numbers inseted of typing each one in or using a tamplate

		random_device rdevice{};
		default_random_engine num{rdevice()};
		uniform_int_distribution< unsigned int> randomNum{0,100};
		
	// random numbers generator engine
   //--------------------------------------------------------------




	int numOfElem;
	
	
	PandV temp;//create struct 
	
	//I hope it is ok that the main function uses the input/output stream to figure out the number of elements user wants to store in the vector
	//just to make the testing more flexible
	cout << "Number of integers in a sequential structure: ";
	cin >> numOfElem;
	
	
	//once the proram know the number of elements, it stores every randomly generated number to the vector in temp
	for (int x{0}; x < numOfElem; x++ ){

		temp._vec.push_back(randomNum(num));
	}
	
	temp.display();//lets display the vecor so we will be able to check the results
	//then we pass the temp struct to count function 
	struct PandV myStruct = count(temp);//call the function to count and return the results and store them to myStruct 
	
	cout << "\n\tThe sequential structure of integers has: "<< endl;
	cout << "\n\t\tValleys: " << myStruct._valleys << endl;
	cout << "\t\tPeaks: " << myStruct._peaks << endl;
	cout << "\n\t************************************* \n\n\n";
	
	system("pause");
    return 0;
}





struct PandV count(struct PandV strct)
{
    // check if the first or last element is a peak or valley
    
    if(strct._vec[0]>strct._vec[1] && strct._vec[0]>strct._vec [strct._vec.size()-1])
    {
       strct._peaks++;
    }
    
	
    if(strct._vec[strct._vec.size()-1]>strct._vec [0] && strct._vec [strct._vec.size()-1]>strct._vec [strct._vec.size()-2])
    {
        strct._peaks++;
    }
	
	
    if(strct._vec[0] < strct._vec[1] && strct._vec [0]<strct._vec [strct._vec.size()-1])
    {
        strct._valleys++;
    }
   
    if(strct._vec [strct._vec.size()-1]<strct._vec [0] && strct._vec [strct._vec.size()-1]<strct._vec [strct._vec.size()-2])
    {
       strct._valleys++;
    }
	
	//--------------------------------------
	
	
    // check all the other elements in the vector
    for(unsigned int i {1} ;i<strct._vec.size()-1;i++)
    {
	
        if(strct._vec [i]>strct._vec [i-1] && strct._vec [i]>strct._vec [i+1])
        {
           strct._peaks++;
        }
        
        if(strct._vec [i]<strct._vec [i-1] && strct._vec [i]<strct._vec[i+1])
        {
            strct._valleys++;
        }
    }
	
	
	return strct;
	
}
