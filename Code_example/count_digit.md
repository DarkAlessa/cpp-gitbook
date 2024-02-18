int count(int& n) {
    int m = n;
    int digit = 0;
    for(int i = 10; i < 10000000; i*=10) {
        digit++;
        if(m % i == n) { break; }
    }
    return digit;
}

int main()
{
    int x = 1234;
    cout << count(x) << endl;	// 4
}
