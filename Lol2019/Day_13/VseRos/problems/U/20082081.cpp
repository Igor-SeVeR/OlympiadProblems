#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    long long int N,i,j,iter=100,k; long double x1,y1,x2,y2,a,b,c;
    cin>>N;
    cout.precision(20);
    vector <long double> A(N),B(N),C(N);
    for (i=0; i<N; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        a=y2-y1; b=x1-x2; c=x2*y1-x1*y2;
        A[i]=a/sqrt(a*a+b*b);
        B[i]=b/sqrt(a*a+b*b);
        C[i]=c/sqrt(a*a+b*b);
    };
    long double mx1,mx2,lx,rx,my1,my2,ly,ry,fx1,fx2,fy1,fy2;
    lx=-1000000000; rx=1000000000;
    for (i=0; i<iter; i++)
    {
        mx1=lx+(rx-lx)/3;
        mx2=rx-(rx-lx)/3;
        ly=-1000000000; ry=1000000000;
        for (j=0; j<iter; j++)
        {
            my1=ly+(ry-ly)/3;
            my2=ry-(ry-ly)/3;
            fy1=-1; fy2=-1;
            for (k=0; k<N; k++) if (abs(A[k]*mx1+B[k]*my1+C[k])>fy1) fy1=abs(A[k]*mx1+B[k]*my1+C[k]);
            for (k=0; k<N; k++) if (abs(A[k]*mx1+B[k]*my2+C[k])>fy2) fy2=abs(A[k]*mx1+B[k]*my2+C[k]);
            if (fy1>fy2) ly=my1; else ry=my2;
        };
        fx1=-1;
        for (k=0; k<N; k++) if (abs(A[k]*mx1+B[k]*(my1+my2)/2+C[k])>fx1) fx1=abs(A[k]*mx1+B[k]*(my1+my2)/2+C[k]);
        ly=-1000000000; ry=1000000000;
        for (j=0; j<iter; j++)
        {
            my1=ly+(ry-ly)/3;
            my2=ry-(ry-ly)/3;
            fy1=-1; fy2=-1;
            for (k=0; k<N; k++) if (abs(A[k]*mx2+B[k]*my1+C[k])>fy1) fy1=abs(A[k]*mx2+B[k]*my1+C[k]);
            for (k=0; k<N; k++) if (abs(A[k]*mx2+B[k]*my2+C[k])>fy2) fy2=abs(A[k]*mx2+B[k]*my2+C[k]);
            if (fy1>fy2) ly=my1; else ry=my2;
        };
        fx2=-1;
        for (k=0; k<N; k++) if (abs(A[k]*mx2+B[k]*(my1+my2)/2+C[k])>fx2) fx2=abs(A[k]*mx2+B[k]*(my1+my2)/2+C[k]);
        if (fx1>fx2) lx=mx1; else rx=mx2;
    };
    cout<<(mx1+mx2)/2<<" "<<(my1+my2)/2;
    return 0;
}
