#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
struct Reading{
    int hour;
    double temperature;
};
int main(){
    int hour;
    double temperature;
    vector<Reading> temps;
    while(cin>>hour>>temperature){
        Reading r;
        r.hour = hour;
        r.temperature = temperature;
        temps.push_back(r);
    }
    ofstream ost("store_temps.txt");
    for (int i = 0; i < temps.size(); i++){
        ost << temps[i].hour << " " << temps[i].temperature << endl;
    }
    ost.close();
    return 0;
}
