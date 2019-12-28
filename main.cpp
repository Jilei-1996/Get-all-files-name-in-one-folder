/*int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}*/

#include <dirent.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

int fileNameFilter(const struct dirent *cur)
{
    std::string str(cur->d_name);
    if (str.find(".pcd") != std::string::npos)
    {
        return 1;
    }
    return 0;
}

int main()
{
   ofstream mycout("result.txt"); 
   struct dirent **namelist;
   int n = scandir("/home/jilei/data_sum/out2", &namelist, fileNameFilter, alphasort);
   vector<string> name_list(n);
   if(n < 0)
            cerr << "memery error " << endl;
   else 
            cout << "total number is: " << n << endl;
            
   for( int i = 0; i < n; i++)
   {
            // /* skip . && .. */
            // if(namelist[i]->d_name[0] == '.')
            //     continue;
            name_list.push_back(namelist[i]->d_name);
	    //vector<string> instr;
	    //name_list.push_back(instr);//instr+namelist[i]->d_name);
            mycout<<namelist[i]->d_name<<endl;
            free(namelist[i]);
    }
    free(namelist);
    //delete name_list;
    mycout.close();
    
    cout << "ok" << endl;
   /* for(auto it:name_list)
    {
        cout << it << endl;
    }*/
    return 0;
}
