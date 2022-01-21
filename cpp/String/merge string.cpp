// Program to manage strings

#include <iostream>
#include <string.h>
using namespace std;
const int MAX = 10 ;

class string
{
	private :

		char str[MAX] ;

	public :

        string( ) ;
		string ( char *s ) ;
		int xstrlen( ) ;
		static void xstrcpy ( string &t, string &s ) ;
		static void xstrcat ( string &t, string &s ) ;
		static int xstrcmp ( string &s1, string &s2 ) ;
		void show( ) ;
} ;

// initializes data member
string :: string( )
{
}

// initialize the data memebers
string :: string ( char *s )
{
	strcpy ( str, s ) ;
}

// finds the length of the string
int string :: xstrlen( )
{
	int l = 0 ;
	char *s = str ;
	while ( *s )
    {
		l++ ;
        s++ ;
    }
	return l ;
}

// copies source string s to the target string t
void string :: xstrcpy ( string &t, string &s )
{
	char *s1 = t.str ;
	char *s2 = s.str ;

	while ( *s2 )
	{
		*s1 = *s2 ;
		s1++ ;
		s2++ ;
	}
	*s1 = '\0' ;
}

// concatenates the two strings
void string :: xstrcat ( string &t, string &s )
{
	char *s1 = t.str ;
	char *s2 = s.str ;

	while ( *s1 )
		s1++ ;
	while ( *s2 )
		*s1++ = *s2++ ;
	*s1 = '\0' ;
}

// comapres two strings s1 and s2 for equality
int string :: xstrcmp ( string &s1, string &s2 )
{
	char *s = s1.str ;
	char *t = s2.str ;

	while ( *s == *t )
	{
		if ( ! ( *s ) )
			return 0 ;
		s++ ;
		t++ ;
	}
	return ( *s - *t ) ;
}

// displays the string
void string :: show( )
{
	std::cout << str << std::endl ;
}

 main( )
{
	string s1 ( "lahore" ) ;
	string s2 ( "karachi" ) ;

	std::cout << std::endl ;
	std::cout << "String s1: " ;
	s1.show( ) ;
	std::cout << "\nLength of string s1: " << s1.xstrlen( ) << std::endl ;

	std::cout << "\nString s2: " ;
	s2.show( ) ;

	string s3 ;
	string :: xstrcpy ( s3, s1 ) ;
	std::cout << "\nString s3 after copying s1 to it: " ;
	s3.show( ) ;

	string :: xstrcat ( s3, s2 ) ;
	std::cout << "\nString s3 after concatenation: " ;
	s3.show( ) ;

	if ( string :: xstrcmp ( s1, s2 ) == 0 )
		std::cout << "\nThe strings s1 and s2 are similar" << std::endl ;
	else
		std::cout << "\nThe strings s1 and s2 are not similar" << std::endl ;
		
		return 1;
}
