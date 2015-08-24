#include <iostream>
#include <limits.h>
 
using namespace std;
 
int min(int key[], bool set[]){
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < 8; v++)
     if (set[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
void printMST(int p[], int graph[8][8]){

   for (int i = 1; i < 8; i++){
   	 if(p[i] == 0)
	      cout << "A";
	 else if(p[i] == 1)
	      cout << "B";
	 else if(p[i] == 2)
	      cout << "C";
	 else if(p[i] == 3)
	      cout << "D";
	 else if(p[i] == 4)
	      cout << "E";
	 else if(p[i] == 5)
	      cout << "F";
	 else if(p[i] == 6)
	      cout << "G";
	 else if(p[i] == 7)
	      cout << "H";
	 
	 cout << " - ";
	 
	 if(i == 0)
	      cout << "A";
	 else if(i == 1)
	      cout << "B";
	 else if(i == 2)
	      cout << "C";
	 else if(i == 3)
	      cout << "D";
	 else if(i == 4)
	      cout << "E";
	 else if(i == 5)
	      cout << "F";
	 else if(i == 6)
	      cout << "G";
	 else if(i == 7)
	      cout << "H";
	 
	 cout << " has weight " << graph[i][p[i]] << endl;
      
   }
}
 
void primAlgorithm(int graph[8][8]){
     int p[8];
     int key[8];   
     bool set[8];
 
     for (int i = 0; i < 8; i++){
        key[i] = INT_MAX;
        set[i] = false;
     }
 
     key[0] = 0;
     p[0] = -1;
 
     for (int count = 0; count < 8; count++)
     {
        int j = min(key, set);
 
        set[j] = true;
 
        for (int v = 0; v < 8; v++){
 
          if (graph[j][v] && set[v] == false && graph[j][v] <  key[v]){
             p[v]  = j;
             key[v] = graph[j][v];
          }
        }
     }
 
     printMST(p, graph);
}
 
 
int main(){
   int graph[8][8] = {{0, 1, 0, 0, 4, 8, 0, 0},
                      {1, 0, 2, 0, 0, 6, 6, 0},
                      {0, 2, 0, 1, 0, 0, 2, 0},
                      {0, 0, 1, 0, 0, 0, 1, 4},
                      {4, 0, 0, 0, 0, 5, 0, 0},
				  {8, 6, 0, 0, 5, 0, 0, 0},
				  {0, 6, 2, 1, 0, 0, 0, 0},
				  {0, 0, 0, 4, 0, 0, 1, 0},};
	primAlgorithm(graph);
 
    return 0;
}
