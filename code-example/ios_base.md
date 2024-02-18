#include <iostream>
#include <cstdio>
 
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int x;
    std::cout <<"cout\n";
    std::printf("printf\n");
    std::cin >> x;
    
    return 0;
}
/* Output:
    printf
    10
    cout 
*/