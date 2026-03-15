#include<iostream>
#include<cmath>
using namespace std;

long long findbase(long long x){
    long long count = 0;
    while(x > 0){
        x = x / 10;      // keep removing last digit
        count++;         // count number of digits
    }
    return count;        // returns number of digits in number
}

void split_num(long long num, long long m, long long &high_num, long long &low_num){
    long long count = 0;
    low_num = 0;

    // example: num = 1234 , m = 2
    // we want high = 12 and low = 34

    while(count != m){
        low_num = low_num + (num % 10) * pow(10, count);
        // take last digit and construct low part

        // iteration 1
        // num = 1234
        // num%10 = 4
        // low = 4

        // iteration 2
        // num = 123
        // num%10 = 3
        // low = 34

        num = num / 10;     // remove last digit
        count++;            // move to next digit
    }

    high_num = num;         // remaining digits form high part
    // here num becomes 12
}

long long karatsuba(long long num1, long long num2){

    if(num1 < 10 || num2 < 10)
        return num1 * num2;   // base case: if single digit multiply normally


    // example: num1 = 1234 , num2 = 5678

    long long m = max(findbase(num1), findbase(num2));
    // find number of digits in larger number
    // here m = 4

    long long m2 = m / 2;
    // split position
    // here m2 = 2


    long long high1, low1, high2, low2;

    split_num(num1, m2, high1, low1);
    split_num(num2, m2, high2, low2);

    // numbers are split like:

    // num1 = 1234 → high1 = 12 , low1 = 34
    // num2 = 5678 → high2 = 56 , low2 = 78


    long long z0 = karatsuba(low1, low2);
    // z0 = 34 × 78

    long long z1 = karatsuba(low1 + high1, low2 + high2);
    // z1 = (34+12)(78+56)
    // z1 = 46 × 134

    long long z2 = karatsuba(high1, high2);
    // z2 = 12 × 56


    return z2 * pow(10, 2 * m2)
         + (z1 - z2 - z0) * pow(10, m2)
         + z0;

    // combine results using karatsuba formula
}


/*
karatsuba is divide and conquer multiplication algorithm

works by splitting numbers into high and low parts

example:
1234 = 12*10^2 + 34
5678 = 56*10^2 + 78

instead of doing 4 multiplications like normal method,
karatsuba reduces them to 3 multiplications

z0 = xl * yl
z1 = (xh + xl)(yh + yl)
z2 = xh * yh

result = z2*10^(2m) + (z1 - z2 - z0)*10^m + z0


time complexity - O(n^1.585)
better than normal multiplication O(n^2)

recurrence relation:
T(n) = 3T(n/2) + O(n)

meaning:
3T(n/2) → three recursive multiplications of half size numbers
O(n) → time required for splitting numbers and combining results

using master theorem :
T(n) = O(n^log2(3)) ≈ O(n^1.585)
*/


int main(){

    long long x,y;

    cout <<"Enter two large nos : "<<endl;
    cin>>x>>y;

    cout<<karatsuba(x, y);
}