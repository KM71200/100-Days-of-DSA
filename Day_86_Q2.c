/*Sqrt(x)*/
#include <stdio.h>

int mySqrt(int x) {
    if(x==0 || x==1)
        return x;

    long low=1, high=x, mid, ans=0;

    while(low<=high){
        mid=(low+high)/2;

        if(mid*mid==x)
            return mid;

        else if(mid*mid < x){
            ans=mid;
            low=mid+1;
        }

        else
            high=mid-1;
    }

    return ans;
}

int main() {
    int x;

    printf("Enter number: ");
    scanf("%d",&x);

    printf("Square root = %d", mySqrt(x));

    return 0;
}