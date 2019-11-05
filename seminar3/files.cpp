#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main(){
	system("chcp 1251>nul");
	ifstream fin;
	string file;
	cout<<"file?";
	cin>>file;
	
	fin.open(file.c_str());
	if(fin.is_open()){
	  cout<<"file is open\n";
	  while(!fin.eof())
	 {
	  string name;
	  getline(fin, name);
	  cout<<name<<endl;	
	  string date;
	  getline(fin, date);
	  
	  int delim1= date.find(".");
	  int delim2= date.find(".", delim1+1);
	  cout<<date<<endl;
	  cout<<delim1<<" "<<delim2<<endl;
	  
	  int day = stoi(date.substr(0, delim1));
	  cout<<"day:"<<day<<endl;
	  int month= stoi(date.substr(delim1+1, delim2- delim1 -1));
	  cout<<"month:"<<month<<endl;
	  int year=stoi(date.substr(delim2+1));
	  cout<<"year="<<year<<endl;
	  
	  map<string, int> marks;
	  
	  string ms;
	 getline(fin, ms);
	  cout<<ms<<endl;
	  int start=0;
	  int current=ms.find(" ");
	  while(current != string::npos){
	  	string field=ms.substr(start, current-start);
	  	int mark= stoi(ms.substr(current+1, 1));
	  	start= current+3;
	  	current= ms.find(" ", start);
	  	cout<<field<<" "<<mark <<endl;
	  	marks.insert(pair<string, int>(field, mark));
	  }
		
		
	}
}
	else{
		cout<<"file not found\n";
	}
	
	
	
	
}
