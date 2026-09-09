class Solution {
public:
    long long countCommas(long long n) {
        int digits = 0;
        long long num = n;
        while(num>0){
            digits++;
            num /= 10;
        }
        if(digits<4)return 0;
        int temp = digits/3;
        long long num1 = pow(10, digits-1);
        if(digits%3==0)temp-=1;
        long long sum = (n-num1+1)*temp;
        digits-=2;
        while(digits>=3){
            temp = digits/3;
            long long n1 = pow(10, digits);
            n1*=(9*temp);
            sum += n1;
            digits--;
        }
        return sum;
    }
};