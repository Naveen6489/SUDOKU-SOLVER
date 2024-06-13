#include <bits/stdc++.h>
using namespace std;

//The isvalid function is checking 
// whether the value is present in the
// row, coulumn, and the square of having 9 cells
// after finding these this function will returns these
// bool output which is valid or not.

bool isvalid(int row,int col,int val,int mat[9][9])
{
   // we have to run the loop for 9 iterations beacause
   //there are 9 rows and 9 coulumns in the SUDUKO
   
    for(int i=0;i<9;i++)
    {
        // This will check the Coulumn;
        
        if(mat[i][col]==val)
        {
            return false;
        }
        //This condition will check the Row
        
        if(mat[row][i]==val)
        {
            return false;
        }
        //This condition will check the 9 cells
        if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}
// This function will solve the sudoko
bool solve(int mat[9][9]){
    //This loop is run for the rows
    
    for(int i=0;i<9;i++)
	{
	     //This loop is run for the Coulumn
	    for(int j=0;j<9;j++)
	    {
	        //This condition will check the cell in the board 
	        //Empty or not
	        if(mat[i][j]==0)
	        {
	            //This will run for which element is suitable
	            //in the board which is empty
	            for(int c=1;c<=9;c++)
	            
	            {
	                if(isvalid(i,j,c,mat))
	                
	                {
	                    mat[i][j]=c;
	                    
	                    if(solve(mat)==true)
	                    
	                    {
	                        return true;
	                    }
	                    else
	                    
	                    {
	                        mat[i][j]=0;
	                    }
	                }
	            }
	            
	            return false;
	        }
	    }
	}
	
	return true;
}

int main() {
	int n=9;
	int m=9;
	
	int mat[9][9];
	for(int i=0;i<n;i++){
	    
	    for(int j=0;j<m;j++){
	        
	        cin>>mat[i][j];
	    }
	}
	bool k=solve(mat);
	
	cout<<"HEY NAVEEN YOUR SUDUKO IS SOLVED"<<endl<<endl;
	
	cout<<"I will print it in Few Second"<<endl<<endl;
	
	for(int i=0;i<n;i++){
	    
	    for(int j=0;j<m;j++){
	        
	        cout<<mat[i][j]<<" ";
	        
	    }
	    
	    cout<<endl;
	}
	
}
