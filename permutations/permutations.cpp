#include<iostream>
#include<string.h>
#include<cstdlib>
#include<vector>
using namespace std;

vector<vector<char>> readFile()
{
        vector<vector<char>> line;
        FILE *file=fopen("input.csv","r");
        char buffer[1024];
        if(!file)
        {
                printf("CANT OPEN FILE");
                return line;
        }
        const char *delim=",";
        while(fgets(buffer,1024,file))
        {
                vector <char> col;
                char *token=strtok(buffer,delim);
                while(token)
                {
                 //ex token='a' we need only the middle character. so we select the character we want by doing token[1]                                         
                        col.push_back(token[1]);
                        token=strtok(NULL, delim);
                }
                line.push_back(col);
        }
        return line;
}
void printAllPermutations(vector<vector<char>> line)
{
        int n=line.size();//no of lines or arrays
        int *index=new int[n]; //track index in every line
        for(int i=0;i<n;++i)
                index[i]=0;
        while(1)
        {
                for(int i=0;i<n;i++)
                        cout<<line[i][index[i]];
                cout<<endl;
                int next=n-1;
                while(next>=0 && index[next]+1>=line[next].size())
                {
                        next--;
                }
                
                if(next<0)
                        return;
                
                index[next]++;
                
                for(int i=next+1;i<n;i++)
                        index[i]=0;
        }
}
int main()
{
        vector<vector<char>>line=readFile();
         
        printAllPermutations(line);
        return 0;
}
