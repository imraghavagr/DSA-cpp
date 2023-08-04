#include<iostream>
#include<vector>
using namespace std;

class Raghav{
  private:
    string name, college, degree, strength;
    vector<string> languages_spoken;
  public:
    Raghav(){
      name = "Raghav";
      college = "Vellore Institute of Technology";
      degree = "CSE with spec. in AI and ML";
      strength = "Strong hold in DS and Algo";
      languages_spoken = {"English", "Hindi"};
    }
    void current_status(){
      cout<<"I am a final year student at "<<college<<" persuing "<<degree<<endl;
    };
    void say_bye(){
      cout<<"Thanks for dropping by, how you find some of my work interesting."<<endl;
    }
};

int main(){
  Raghav obj;
  obj.current_status();
  obj.say_bye();
  return 0;
}