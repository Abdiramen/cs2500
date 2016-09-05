/*
 * File: InsertionSort.cpp
 * Date:  9.04.2016
 * Programmer:  Abdirahman Ahmed Osman
 *
 * Purpose:  Implementation of Insertion Sort the worst sorting algorithm.
 *
 * Issues:  print() should be overloaded so that there is a function for 
 * handling color prints and there should be one for handling printing the
 * whole array.
 *          On anothre note there shoul be a funcs.h and funcs.cpp so that
 * the function for printing arrays can be more easily used in future
 * programmes that use them in this series. Or I could not and get more
 * practice.
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
 * Precondition: n > 0 and i>=0
 * 
 * Postcondition: Prints array to stdscr
 *
 * Description: Prints each element of an array to stdscr unless the i!=n then
 * the element at index i is printed to stdscr.
 *
 */
void print(int* A, int n, int i, short color);//should overload this function


int main()
{
  int* Array;
  int size=0;
  srand(time(NULL));
  initscr();
  start_color();
  init_pair(1, COLOR_BLUE,COLOR_BLACK);
  init_pair(2, COLOR_RED,COLOR_BLACK);
  init_pair(3, COLOR_GREEN,COLOR_BLACK);
  printw("What size array: ");
  refresh();

  scanw("%d",&size);
  clear();
  
  mvprintw(LINES/2,COLS/2,"Generating random Array...");
  refresh();
  Array = rand_array(size);
  clear(); 

  //print(Array, size);
  attroff(A_BLINK);
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

  print(A,n,n,0);

  for(int j=1; j<n; j++ ) 
  {
    key=A[j];
    i=j-1;
    print(A,n,j,2);
    while(i>=0 && A[i] > key)
    {
      A[i+1]=A[i];
      print(A,n,i,1);//printing new location of element. in blue.
      i--;
    }
    print(A,n,n,0);//printing whole list. no valid color pair chosen.
    A[i+1]=key;
    print(A,n,i+1,3);//printing key at new index. in green.
  }
  print(A,n,n,0);
  return;
}


void print(int* A, int n, int i, short color)
{
  //move(LINES/2,(COLS)/2-2*n);
  if(i!=n)
  {
    attron(COLOR_PAIR(color));
    mvprintw(LINES/2,i*5,"[%3d]",A[i]);// i*5 each index takes up five colomns.
    attroff(COLOR_PAIR(1));
  }
  else
  {
    for(int k=0; k<n; k++)
    {
      mvprintw(LINES/2,k*5,"[%3d]",A[k]);
    }
  }
 refresh();
 usleep(100000);
 return;
}
