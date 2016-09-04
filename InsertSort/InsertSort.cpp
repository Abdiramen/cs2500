/*
 * File: InsertionSort.cpp
 * Date:  9.04.2016
 * Programmer:  Abdirahman Ahmed Osman
 *
 * Purpose:  Implementation of Insertion Sort the worst sorting algorithm.
 *
 * Issues:  I want to have the print function be able to show each change that
 * Insert_Sort()'s makes to the array. besides that I'm done.
 *
 */
#include<ncurses.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

/*
 * Precondition: n > 0 
 *
 * Postcondition: Sorts array in acending order
 *
 * Description: Sorts array on n integers in acending order 
 *
 */
void Insert_Sort(int* A, int n);

/*
 * Precondition: n > 0
 *
 * Postcondition: Array of random numbers from [0,100]
 *
 * Description: Builds randomized array of size n 
 * 
 */
int* rand_array(int n);

/*
 * Precondition: n > 0
 * 
 * Postcondition: Prints array to stdscr
 *
 * Description: Prints each element of an array to stdscr
 *
 */
void print(int* A, int n);


int main()
{
  int* Array;
  int size=0;
  srand(time(NULL));
  initscr();
  
  printw("What size array: ");
  refresh();

  scanw("%d",&size);
  clear();
  
  mvprintw(LINES/2,COLS/2,"Generating random Array...");
  refresh();
  Array = rand_array(size);
  clear(); 

  //print(Array, size);
  Insert_Sort(Array, size);
  delete Array;

  mvprintw(LINES-1,COLS/2,"Press Anything to exit");
  refresh();
  getch();

  endwin();
}


int* rand_array(int n)
{
  int* array = new int[n];

  for(int i=0; i<n; i++)
  {
    array[i]=rand()%(100+1);
  }

  return array;
}


void Insert_Sort(int* A, int n)
{
  int key=0;
  int i;

  print(A,n);

  for(int j=1; j<n; j++ ) 
  {
    key=A[j];
    i=j-1;

    while(i>=0 && A[i] > key)
    {
      A[i+1]=A[i];
      i--;
      print(A,i);
    }
    A[i+1]=key;
    print(A,i+1);
  }
  print(A,n);
  return;
}


void print(int* A, int n)
{
  move(LINES/2,(COLS)/2-2*n);
  for(int i=0; i<n; i++)
  {
    /*mv*/printw(/*LINES/2,(COLS/2)+i,*/"[%d]",A[i]);
    refresh();
  }

 usleep(100000);
 return;
}
