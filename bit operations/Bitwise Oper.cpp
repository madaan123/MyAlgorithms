#include<bits/stdc++.h>
using namespace std;
#define INT_BITS 32

void bin(unsigned n)			// function to print binary representation of a number in 32 bits format.
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
}

void binary(int n)		// function to print binary representation of a number
{
	if(n>1)
	binary(n/2);
	
	cout<<n%2;
}

int leftRotate(int n,int d)					// function to left rotate bits of a number by d bits
{
	return (n<<d)|(n>>(INT_BITS-d));
}

int rightRotate(int n,int d)				// function to right rotate bits of a number by d bits
{
	return (n>>d)|(n<<(INT_BITS-d));
}

bool checksparse(int n)						// check if a particular number is a sparse or not
{										// A sparse number is one who does not has consecutive ones in its binary number(101010101)
	while(n)
	{
		if(n&1)
		{
			n>>=1;
			if(n&1)
			return false;
		}
		else
		{
			n>>=1;
		}
	}
	return true;
}

int nextSparse(int n)						// function to find next sparse number after n
{
	while(1)
	{
		if(checksparse(n))
		return n;
		
		n++;
	}
}

int nextSparse2(int x)					// optimized function to find next sparse number after n
{
	vector<bool>bin;
	while(x!=0)
	{
		bin.push_back(x&1);
		x>>=1;
	}
	bin.push_back(0);
	int n=bin.size();
	int l=0;
	int i,j;
	for(i=1;i<n-1;i++)
	{
		if(bin[i]==1 && bin[i-1]==1 && bin[i+1]!=1)
		{
			bin[i+1]=1;
			
			for(j=i;j>=l;j--)
			bin[j]=0;
			
			l=i+1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=bin[i]*(1<<i);
	}
	return ans;
}

int countSetBits(int n)					// function to count set bits(number of ones in binary representation) in a number
{
	int c=0;
	while(n)
	{
		c+=(n&1);
		n>>=1;
	}
	return c;
}

string reverse(string s)			// function to reverse a string without using any temporary variable
{
	int n=s.length();
	int i=0;
	int j=n-1;
	while(i<j)
	{
		s[i]=s[i]^s[j];
		s[j]=s[j]^s[i];
		s[i]=s[i]^s[j];
	}
	return s;
}

int minimum(int a,int b)				// function to find minimum of two numbers by bitwise operators
{
	return b+((a-b) & (a-b)>>(sizeof(int)*CHAR_BIT-1));
}

int maximum(int a,int b)				// function to find minimum of two integers
{
	return a-((a-b) & (a-b)>>(sizeof(int)*CHAR_BIT-1));
}

int MultiplyBy7(int n)				// function to multiply a number by 7 
{									// (n<<3) gives us 8*n and we subtract n from it to get 7*n
	return ((n<<3)-n);
}

int Multiply(int n)
{
	// multiply a number by 3.5
	
	return n<<1 + n + n>>1;			// n<<1=2*n  n>>1=n/2 so by adding all these it becomes 3.5*n
}

int countConsecutiveZeroes(int n)		// function to find consecutive trailing zeroes in binary representation of a number
{
	int c=0;							// 1101000 gives 3
	while(1)
	{
		if(!(n&1))
		c++;
		else if(n&1)
		break;
		n>>=1;
	}
	return c;
}

int Log2(int n)					// function to find log of a number
{
	int c=0;
	while(n>>=1)
	{
		c++;
	}
	return c;
}

int SwapEvenOdd(int n)					// function to swap odd and even bits of a number
{
	int mask=0xAAAAAAAA;				// 7 -> 00000111  	after swap ->00001011 (11)
	int even,odd;
	even=(n & mask)>>1;
	odd=(n & mask>>1)<<1;
	return odd|even;
}

bool oppositeSign(int x,int y)			// Check if 2 numbers are opposite in sign
{
	return ((x^y)<0);
}

int swapNibble(int n)				// swap 2 nibbles of a number
{
	int mask=0x0f;				// mask= 00001111
	int a,b;			
	a=((n & mask)<<4);			// last 4 bits of n
	b=((n & (mask<<4))>>4);		// first 4 bits of n
	return a|b;
}

int UnsetKthbit(int n,int k)
{
	if(k==0)
	return n;						// ~(1<<(k-1)) is a number having all bits set except kth bit
	return (n & ~(1<<(k-1)));
}

int addOne(int n)
{
	int m=1;
	while(n&m)
	{
		n^=m;
		m<<=1;
	}
	n^=m;
	return n;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<addOne(n);
		cout<<endl;
	}
}
