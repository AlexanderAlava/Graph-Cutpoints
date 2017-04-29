//=============================================================================//
//=05/01/2017                                                  Alexander Alava=//
//=cut_tester.h                                                      U35432961=//
//=                                                                           =//
//=                This is the header file for the graph class                =//
//=============================================================================//

#ifndef GRPH
#define GRPH

#include <iostream>
#include <vector>

using namespace std;

struct vnode
{
  // Declaring the data members of the class //
  int vertex;
  vnode *next;

  // Declaring the constructor with integer and integer pointer parameters //
  vnode(int u, vnode *n): vertex(u), next(n){};
};

// Defining as a type a vnode pointer //
typedef vnode * vnodeptr;

class graph
{
  public:
    // Declaring the constructor //
    graph();

    // Declaring the connected function with an integer parameter //
    bool connected(int excluded);

    // Declaring the depth first search function with a boolean vector parameter //
    void dfs(vector<bool> &visited);

    // Declaring the get_cutpoints function that will return a vector //
    vector<int> get_cutpoints();

  private:
    // Declaring the private data members of the class //
    int size;
    vector<vnodeptr> adjList;
};

#endif
