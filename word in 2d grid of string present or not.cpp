/*Given a 2D grid of characters and a word, the task is to check if that word exists in the grid or not. A word can be matched in 4 directions at any point.

The 4 directions are, Horizontally Left and Right, Vertically Up and Down.

Input Format: A grid and a word will be given as input.

Output Format : print yes if given word is present in the grid if not print no.

Example 1

Input :

grid[][] =
{"axmy",
"bfdf",
"xeet", 
"raks"};

Word :- feet

Output : Yes
Explaination: Feet is present in the grid therefore output is yes.*/

#include<bits/stdc++.h>
using namespace std;
bool isPresent(vector<string >grid,string search,int i,int j,int m,int n,int pos)
{         if(pos==search.length())
             return true;
	 
	 if (i < 0 || j < 0 || i >= m || j >= n) 
        return false; 
     
	     if (grid[i][j] == search[pos]) { 
		     grid[i][j]="#";
     bool res = isPresent(grid, search, i - 1, j, m, n, pos + 1) || isPresent(grid,search, i + 1, j, m, n, pos + 1)||isPresent(grid, search, i, j - 1, m, n, pos + 1) || isPresent(grid, search, i, j + 1, m, n, pos + 1); 
  
        return res;
             
         } 
  
        return false; 
}
int main()
{ int m,n;
cin>>m>>n; 
string word;
vector<string> grid;

  for (int i = 0; i < m; i++) 
   {  
  cin>>word;
	grid.push_back(word);
	word.clear();
  	
  
  }
 string search;
 cin>>search;
 if (search.length() > m * n) 
       cout<<" no"; 
  
  else{
   bool present=false;
    for (int i = 0; i < m; i++) 
       {
		 for (int j = 0; j < n; j++) 
  
           {
		   
            if (grid[i][j] == search[0]) 
               
               if(isPresent(grid, search, i, j, m, n, 0))
			   present=true ;
               
                 
       }
      
}
if(present)
cout<<"YES";
else
cout<<"NO";
}
return 0;
}
