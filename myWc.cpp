
/**********************************************
 * Last Name:   Lykhosherstov
 * First Name:  Bogdan
 * Student ID:  10162345
 * Course:      CPSC 457
 * Tutorial:    04
 * Assignment:  1
 * Question:    Q4
 *
 * File name: countLines.cpp
 *********************************************/

#include <unistd.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main (int argc, char * const argv[])
{
  // get the file name from command line
  string filename;
  if (argc != 2) {
    cerr << "Usage: readFile <input file> " << endl;
    return -1;
  }
  else {
    filename = argv[1];
  }

  // open the file for reading
  int fd = open( filename.c_str(), O_RDONLY);
  if( fd < 0) {
    cerr << "Could not open file " << filename << "\n";
    exit(-1);
  }

  // read file character by character and count lines

  // int count = 0;
  // while(1) {
  //   char c;
  //   if( read( fd, & c, 1) < 1) break;
  //   if( c == '\n') count ++;
  // }

  // My Code START
  int count = 0;
  char buffer[1024];
  
  while(1){
      if (read(fd, &buffer, sizeof(buffer)) < 1) break;
      for (int i=0; i<sizeof(buffer); i++){
          if (buffer[i] == '\n') count++;
      }
      //This is done to flush the buffer on the last iteration so it doesn't double count the old \n
      memset(buffer, 0, sizeof buffer);
  }
  // My Code END


  // close file and report results
  close( fd);
  cout << count << " " << filename << "\n";
  return 0;
}
