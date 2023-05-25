#include<iostream>
 
using namespace std;

 
bool judge(string s) {
    int a[4];
    char op[3];
    for(int i = 0; i < 4; ++i) {
        a[i] = s[i * 2] - '0';
    }
    for(int i = 0; i < 3; ++i) {
        op[i] = s[i * 2 + 1];
    }
    int k = 3;
    for(int i = 0; i < k; ++i) {
        if(op[i] == 'x' || op[i] == '/') {
            if(op[i] == 'x') {
                a[i] = a[i] * a[i+1];
            }else {
                a[i] = a[i] / a[i+1];
            }
            for(int j = i+1; j < k; ++j) {
                op[j-1] = op[j];
                a[j] = a[j+1];
            }
            // 因为全部往前挪动了一位，所以i--
            k--, i--;
        }
    }
    int ans = a[0];
    for(int i = 0; i < k; ++i) {
        if(op[i] == '+' || op[i] == '-') {
            if(op[i] == '+') {
                ans = a[i] + a[i+1];
                a[i+1] = ans;
            }else {
                ans = a[i] - a[i+1];
                a[i+1] = ans;
            }
        }
    }
    return ans == 24;
}
 
int main()
{
	int n;
	cin>>n;
 
	string str;
	while (n--) {
		cin>>str;
		printf(judge(str) ? "Yes\n" : "No\n");
	}
 
	return 0;
}