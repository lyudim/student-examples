#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string, int> marks;
	marks["phisics"]=3;
	marks.insert(pair<string, int>("math",4));
	marks.insert(make_pair<string, int>("chem",6));
	
	for(auto mark:marks){
		cout<<mark.first<<" - "<<mark.second<<endl;
	}
	
//	for(map<string, int>::iterator it= ma)
     
    int i=0;
	for(auto it=marks.begin(); it!=marks.end(); it++) {
		cout<<i++<<endl;
		cout<<it->first<<" -> "<<it->second<<endl;
}

	cout<<"math mark:";
	auto it= marks.find("math");
	cout<<it->second<<endl;
	
	it->second=6;
	for(auto mark:marks){
		cout<<mark.first<<" - "<<mark.second<<endl;
	}
	
}
