#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
#define DB(x) cout<<"Valor ->" << x << endl;

int Pangram(string inputString, int *costValues){

	bool hashTable [26];
	
	for(int i = 0; i < 26;i++)hashTable[i] =0;
	
	for(char actualChar: inputString){
		hashTable[actualChar-97] =1; 
	}
	int sum=0,pos = 0;
	
	for(bool element: hashTable){
		
		if(!element) sum += costValues[pos];
		pos++;
	}
	return sum;
	
}

int main(){
	int nTimes;
	cin>>nTimes;
	
	int costValues [26] ;
	string tempInputCost;
	string inputString;
	string bug;
	
	getline(cin,bug);
	while(nTimes>0){
			
		getline(cin,tempInputCost);
		getline(cin,inputString);

		  
		
		stringstream ss;
		ss<<tempInputCost;
		int pos = 0;
		int cost;
		
		while(ss >> cost){
			
			costValues[pos] = cost;
			pos++;
		}
		
		
		cout<<Pangram(inputString,costValues)<<endl;
		nTimes--;
		
	}
	
	
	return 0;
}
