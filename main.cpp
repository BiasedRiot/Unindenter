#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  char *fvalue;
  int c;
  opterr = 0;
  string line;
  char *ivalue;
  int indent;
  // Checking the file flag is specified
  while ((c = getopt (argc, argv, "f:i:")) != -1)
    switch (c)
      {
      case 'f':
        fvalue = optarg;
        break;
      case 'i':
        ivalue = optarg;
        break;
      case '?':
        if (optopt == 'f' || optopt == 'i')
          fprintf (stderr, "Options -%f and -%i require an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%f'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
    
  indent = atoi(ivalue);
  
  fstream myFile;
  ofstream write;

  myFile.open(fvalue);
  write.open("new_file.txt");

  if(!myFile){
    cout << "Get gud";
    return 0;
  }
  
  while(myFile){
    getline(myFile, line);

    if(line=="-1")
      break;

    line.erase(0, indent);
    write << line << endl;

  }
  
  myFile.close();

  return 0;
  
  

}
