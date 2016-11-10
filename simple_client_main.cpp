#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
string Bahnhof = "0";

string fahreNach(string b);
int main ( int argc, int argv[] )
{

  cout << "Geben Sie die IP ein." << endl;
  string s_ip;
  cin >> s_ip;
  cout << "Geben Sie den Port ein:" << endl;
  int i_port;
  cin >> i_port;

  try
    {

      ClientSocket client_socket ( s_ip, i_port );

      std::string reply;


       while(true){ 
      try
	{
    cout << "Zug: Uebermittle Position an den Bahnhof." << endl;

	  client_socket << Bahnhof;
	  client_socket >> reply;
	}
      catch ( SocketException& ) {}

      cout << "Zug: Vom Pi erhalten: " << reply << endl;
      Bahnhof=fahreNach(reply);
}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}

string fahreNach(string b){
  if(b=="nachB"){
    cout << "Zug: Ich fahre nach B." << endl;
    for(int i=0;i<5;i++){
    sleep(1);
    cout << "--" << endl;
    }
    
   
    cout << "Zug: Ich bin bei B angekommen." << endl;
    cout << "------------------------------" << endl;
    return "1";
    }
  if(b=="nachA"){
    cout << "Zug: Ich fahre nach A." << endl;
    for(int i=0;i<5;i++){
    sleep(1);
    cout << "--" << endl;
    }
    cout << "Zug: Ich bin bei A angekommen." << endl;
    cout << "------------------------------" << endl;
    return "0";
  }

}
  ;