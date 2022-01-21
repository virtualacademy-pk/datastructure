// Program to convert an expression in postfix form to an infix form

#include <iostream>
#include <string.h>
using namespace std;
const int MAX = 50 ;

class postfix
{
	private :

		char stack[MAX][MAX], target[MAX] ;
		char temp1[2], temp2[2] ;
		char str1[MAX], str2[MAX], str3[MAX] ;
		int i, top ;

	public :

		postfix ( ) ;
		void setexpr ( char *c ) ;
		void push ( char *str ) ;
		void pop ( char *a ) ;
		void convert( ) ;
		void show( ) ;
} ;

// initializes data member
postfix :: postfix( )
{
	i = 0 ;
	top = -1 ;
	strcpy ( target, "" ) ;
}

// copies given expression to target string
void postfix :: setexpr ( char *c )
{
	strcpy ( target, c ) ;
}

// adds an expr. to the stack
void postfix :: push ( char *str )
{
	if ( top == MAX - 1 )
		cout << endl << "Stack is full" ;
	else
	{
		top++ ;
		strcpy ( stack[top], str ) ;
	}
}

// pops an expr. from the stack
void postfix :: pop ( char *a )
{
	if ( top == -1 )
		cout << endl << "Stack  is empty" ;
	else
	{
		strcpy ( a, stack[top] ) ;
		top-- ;
	}
}

// converts given expr. to infix form
void postfix :: convert( )
{
	while ( target[i] )
	{
		//skip whitespace, if any
		if( target[i] == ' ' )
			i++ ;
		if ( target[i] == '%' || target[i] == '*' ||
			 target[i] == '-' || target[i] == '+' ||
			 target[i] == '/' || target[i] == '$' )
		{
			pop ( str2 ) ;
			pop ( str3 ) ;
			temp1[0] = target[i] ;
			temp1[1] = '\0' ;
			strcpy ( str1, str3 ) ;
			strcat ( str1, temp1 ) ;
			strcat ( str1, str2 ) ;
			push ( str1 ) ;
		}
		else
		{
			temp1[0] = target[i] ;
			temp1[1] = '\0' ;
			strcpy ( temp2, temp1 ) ;
			push ( temp2 ) ;
		}
		i++ ;
	}
}

// displays the expression
void postfix::show ( )
{
	char *t = stack[0] ;
	while ( *t )
	{
		cout << " " << *t ;
		t++ ;
	}
}

 main( )
{
	char expr[MAX] ;

	cout << "\nEnter an expression in postfix form: " ;
	cin.getline ( expr, MAX ) ;

	postfix q ;
	q.setexpr ( expr ) ;
	q.convert( ) ;

	cout << "\nThe infix expression is: " ;
	q.show( ) ;
}
