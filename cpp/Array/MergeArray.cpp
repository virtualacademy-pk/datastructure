// Program Ch02pr02
// Program to merge two 1-D arrays

#include <iostream>

const int MAX1 = 5 ;
const int MAX2 = 7 ;

class Array
{
	private :

		int *arr ;
		int size ;

	public :

		void create ( int sz ) ;
		void sort( ) ;
		void display( ) ;
		void merge ( Array &a , Array &b ) ;
} ;

// creates Array of given size sz, dynamically
void Array :: create ( int sz )
{
	size = sz ;
	arr = new int[size] ;

	int n ;

	for ( int i = 0 ; i < size ; i++ )
	{
		std::cout << "\nEnter the element no. " << ( i + 1 ) << " " ;
		std::cin >> n ;
		arr[i] = n ;
	}
}

// sorts Array in ascending order
void Array :: sort( )
{
	int temp ;
	for ( int i = 0 ; i < size ; i++ )
	{
		for ( int j = i + 1 ; j < size ; j++ )
		{
			if ( arr[i] > arr[j] )
			{
				temp = arr[i] ;
				arr[i] = arr[j] ;
				arr[j] = temp ;
			}
		}
	}
}

// displays the contents of Array
void Array :: display( )
{
	for ( int i = 0 ; i < size ; i++)
		std::cout << "  " << arr[i] ;
}

// merges two Arrays of different size
void Array :: merge ( Array &a, Array &b )
{
	int i, k, j ;
	size = a.size + b.size ;

	arr = new int[size] ;

	for ( k = 0, j = 0, i = 0 ; i <= size ; i++ )
	{
		if ( a.arr[k] < b.arr[j] )
		{
			arr[i] = a.arr[k] ;
			k++ ;
			if ( k >= a.size )
			{
				for ( i++ ; j < b.size ; j++, i++ )
					arr[i] = b.arr[j] ;
			}
		}
		else
		{
			arr[i] = b.arr[j] ;
			j++ ;
			if ( j >= b.size )
			{
				for ( i++ ; k < a.size ; k++, i++ )
					arr[i] = a.arr[k] ;
			}
		}
	}
}

int main( )
{
	Array a ;
	std::cout << "\nEnter elements for first Array: \n" ;
	a.create ( MAX1 ) ;

	Array b ;
	std::cout << "\nEnter elements for second Array: \n" ;
	b.create ( MAX2 ) ;

	a.sort( ) ;
	b.sort( ) ;

	std::cout << "\nFirst Array: \n" ;
	a.display( ) ;
	std::cout << "\n\nSecond Array: \n" ;
	b.display( ) ;
	std::cout << "\n\nAfter Merging: \n" ;

	Array c ;
	c.merge ( a, b ) ;
	c.display( ) ;
	return 1;
}
