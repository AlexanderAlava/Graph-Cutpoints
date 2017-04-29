//=========================================================================================//
//=05/01/2017                                                              Alexander Alava=//
//=cut_tester.cpp                                                                U35432961=//
//=                                                                                       =//
//=            This is the implementation file for the graph class                        =//
//=========================================================================================//

#include "graph.h"
#include <cassert>
#include <stack>

// Defining the constructor of the graph class //
graph::graph()
{
  // Declaring a integer variable //
  int vertex;

  // Reading in user input for the size of the graph //
  cin >> size;

  // Resizing the adjacency list //
  adjList.resize(size,NULL);

  // Establishing a for loop that will run through the adjacency list //
  for(int i = 0; i < size; ++i)
  {
    // Reading user input for the vertex //
    cin >> vertex;

    // Establishing a while loop to run until the ending input is found //
    while(vertex != -1)
    {
      // Inserting a vnode from the beggining of the adjacency list //
      adjList[i] = new vnode(vertex,adjList[i]);

      // Reading user input for the vertex //
      cin >> vertex;
    }
  }
}

// Defining the function that will find the first false index //
int firstFalse(vector<bool> b)
{
  // Declaring and initializing an integer variable //
  int i = 0;

  // Establishing a while loop that runs until a false is found or the vector ends //
  while(i < b.size() && b[i])
  {
    // Increasing the index variable //
    i += 1;
  }
  return i;
}

// Defining the function that checks if the entire vector is true //
bool all(vector<bool> b)
{
  // Establishing a for loop to run through the entire vector //
  for(int i = 0; i < b.size(); ++i)
  {
    // Checking if the current index of the vector is false //
    if(!b[i])
    {
      return false;
    }
  }
  return true;
}

// Defining the depth first search function //
void graph::dfs(vector<bool> &visited)
{
  // Declaring and assigning an integer variable //
  int start = firstFalse(visited);

  // Declaring integer variables and assigning a value to one of them //
  int nbr, current = start;

  // Declaring a stack of integers //
  stack<int> S;

  // Declaring a vnode pointer //
  vnodeptr cursor;

  // Assigning a value of true to the first vertex to be processed //
  visited[start] = true;

  // Pushing the first vertex into the stack //
  S.push(start);

  // Establishing a while loop to run until the stack becomes empty //
  while (!S.empty())
  {
    // Assigning the value at the top of the list to current //
    current = S.top();

    // Establishing a for loop to run through the adjacency list of the current vertex //
    for (cursor = adjList[current]; cursor != NULL; cursor = cursor->next)
    {
      // Assigning current the vertex to the variable //
      nbr = cursor->vertex;

      // Checking if the vertex has already been visited //
      if (!visited[nbr])
      {
        // Pushing the vertex into the stack //
        S.push(nbr);

        // Marking the vertex as visited //
        visited[nbr] = true;

        // Breaking out of the for loop //
        break;
      }
    }

    // Checking if all vertices were already visted //
    if (cursor == NULL)
    {
      // Popping the top element out of the stack //
      S.pop();
    }
  }
}

// Defining the function that determines if a graph is conected //
bool graph::connected(int excluded = -1)
{
  // Declaring a vector of boolean variables and initializing all the values to false //
  vector<bool> visited(size,false);

  // Checking if the value to be checked is the excluded value //
  if(excluded != -1)
  {
    // Marking the vertex as visited //
    visited[excluded] = true;
  }

  // Calling the depth first function in order to traverse through the graph //
  dfs(visited);

  // Calling the all function that will check if all of the values were visited //
  return all(visited);

}

// Defining the function that will find and return the cutpoints of the graph //
vector<int> graph::get_cutpoints()
{
  // Declaring a vector of integers //
  vector<int> cutpts;

  // Establishing a for loop that will run through all the vertices in the graph //
  for (int i = 0; i < size; i++)
  {
    // Checking if the current vertex is a cutpoint //
    if (!connected(i))
    {
      // Pushing back into the vector every cutpoint found //
      cutpts.push_back(i);
    }
  }
  return cutpts;

}
