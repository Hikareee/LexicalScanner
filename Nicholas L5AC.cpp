#include <iostream>

using namespace std;

int main(){
	cout << "idk what to do \n";
	string weekday[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	string weekends[] = {"Saturday", "Sunday"};
	string day;
	bool run = true;
	while (run){
	cout << "What day is it today? : ";
	cin >> day;
	
	if(day == weekday[0] || day == weekday[1] || day == weekday[2] || day == weekday[3] || day == weekday[4]) {
		cout << "Skip class and go to sleep \n";
		
	}
	
	else if(day == weekends[0] || day == weekends[1]){
		cout << "Play valorant, then go back to sleep";
	}
	
	else if(day == "Exit"){
		break;
	}
	else{
		cout << "dont know what you mean";
	}
	
 }
}





