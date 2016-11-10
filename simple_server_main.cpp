#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

using namespace std;

string sendNewBahnhof(string d);

int main ( int argc, int argv[] )
{
  std::cout << "running....\n";


  try
    {
      // Create the socket
      ServerSocket server ( 40000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  cout << "Pi: Info erhalten." << endl;
		  data = sendNewBahnhof(data);

		  new_sock << data;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}

string sendNewBahnhof(string d){
	if(d=="0"){
		cout << "Pi: Zug ist bei A." << endl;
		cout << "Pi: Zug soll nach B fahren." << endl;
		cout << "------------------------------" << endl;
		return "nachB";
		}
	if(d=="1"){
		cout << "Pi: Zug ist bei B." << endl;
		cout << "Pi: Zug soll nach A fahren." << endl;
		cout << "------------------------------" << endl;
		return "nachA";
	}
	else{
		cout << "Ungueltiger Befehl." << endl;
	}
 
}