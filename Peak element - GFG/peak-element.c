// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
#include<stdbool.h>


 // } Driver Code Ends
//User function Template for C

int pks(int a[],int l, int h, int n)
{
    int mid = (l+h)/2;
    
    if((mid == 0 || a[mid]>=a[mid-1]) && (a[mid]>=a[mid+1] || mid == n-1))
    return mid;
    
    else if(mid >0 && a[mid-1] > a[mid])
        return pks(a,l,mid-1,n);
    else
       return pks(a,mid+1,h,n);
}

int peakElement(int a[], int n)
{
  return pks(a,0,n-1,n);
}

// { Driver Code Starts.

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			tmp[i] = a[i];
		}
		bool f=0;
		
		int A = peakElement(tmp,n);
		
		if(A<0 && A>=n)
		    printf("0\n");
		else
		{
    		if(n==1 && A==0)
    		    f=1;
    		else if(A==0 && a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 && a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] && a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		printf("%d\n", f);
		}
		
	}

	return 0;
}  // } Driver Code Ends) 