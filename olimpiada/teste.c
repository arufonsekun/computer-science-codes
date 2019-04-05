// CPP program to find the most frequent element
// in an array.
#include <bits/stdc++.h>
using namespace std;
#include <iostream>   // std::cout
#include <string>
#include <stdio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

int check(string A, int len)
{
    string s3;
    int flag=0 ,len1;
    int maior=0;
    len1=A.length();
    std::map<std::string, int> wordCount;
    
    for(int i=0;i<len1-1;i++)
    {
        s3=A.substr(i,len);
        
        if((s3.length())>0)
           ++wordCount[s3];
    }
    
    for (std::map<std::string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it)
    {
         if(maior<it->second){
           maior=it->second;
           s3=it->first;
         }
      }
     for (std::map<std::string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it){
       if(maior==it->second){
          cout << it->first <<":"<< it->second << endl;
          break;
       }
     }



}

// driver program
int main(int argc,char* argv[])
{
    
    
    string in=argv[1];
    transform(in.begin(), in.end(), in.begin(), ::tolower);
    check(in, 2);
    
    return 0;
}
