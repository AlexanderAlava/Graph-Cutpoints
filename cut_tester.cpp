//======================================================================//
//=05/01/2017                                           Alexander Alava=//
//=cut_tester.cpp                                             U35432961=//
//=                                                                    =//
//=    This is the driver/test file for the graph cutpoints project    =//
//======================================================================//

#include "graph.h"
using namespace std;

int main()
{
  // Instatiating a class object //
  graph G;

  // Checking if the graph is connected //
  if(!G.connected(-1))
  {
    // Printing an error message //
    cout << "Graph is not connected; terminating" << endl;
    return 1;
  }

  // Declaring a vecotr of integers and filling it with the cutponts //
  vector<int> cutpoints = G.get_cutpoints();

  // Printing the amount of cutpoints //
  cout << "Number of cutpoints: " << cutpoints.size() << endl;

  // Printing a header for the cutpoints themselves //
  cout << "Cutpoints: ";

  // Establishing a for loop to run through the vector //
  for(int i = 0; i < cutpoints.size(); ++i)
  {
    // Printing the cutpoints //
    cout << cutpoints[i] << " ";
  }
  cout << endl;
  
  return 0;
}
