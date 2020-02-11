#include<iostream>
#include<map>
#include<string.h>
#include<cstdlib>

using namespace std;

map< int, string > readFile()
{
        map< int, string> data; //saving the data from file in form of map.
        FILE *file=fopen("input.csv","r"); //to access file
        char buffer[1024];
        if(!file)
        {
                printf("CAN'T OPEN FILE");
                return data;
        }
        const char *delim=", ";
        while(fgets(buffer, 1024, file))
        {
                char *token=strtok(buffer, delim);
                string word=token;
                token=strtok(NULL, delim);
                int freq=atoi(token);
                data[freq]=word;
        }
        
        return data;
}
int find(map<int, string> dictionary, string word) //function to find the key by value in a map
{
        for (auto it=dictionary.begin();it!=dictionary.end();++it)
        {        
                if (it->second==word)
                        return it->first;        
        }
        return -1; //in case the value is not present in the map items
}
void printOutput(map<int, string> dictionary)
{
        for (auto it=dictionary.begin();it!=dictionary.end();++it)
        {
                cout<<it->second<<endl;
        }
}

int main()
{
        map< int, string > dictionary= readFile();
        string word;
        cin>>word;
        
        int val=find(dictionary, word);
        
        map< int, string > dictionary2;//to save the map items in the order of relevence. 
        if (val==-1)
                return -1;
        for (auto it=dictionary.begin();it!=dictionary.end();++it)
        {
                
                int updated_freq= it->first - val;
                if (updated_freq<0)
                        updated_freq*=(-1);
                
                dictionary2[updated_freq]=it->second;
        }
        
        //printing the output
        printOutput(dictionary2);

        return 0;
        
}
