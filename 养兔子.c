#include <iostream>
using namespace std;

int main() {
    int number = 0;
    //scanf返回值为正确输出数据的变量个数，当一个变量都没有
    //获取到数据时，此时返回-1
    while (scanf("%d", &number) != - 1) {
        if (number < 4) {
            //计算可知第一天1只，第2天2只，第3天3只
            printf("%d\n", number);
        } else {
            //递推第i(i ≥ 4)天的兔子f(i) = f(i - 1) + f(i - 2)
            long long before = 2, now = 3, next = 0;
            for (int i = 4; i <= number; ++i) {
                //f(i) = f(i - 1) + f(i - 2)
                next = before + now;
                //更新f(i - 2) = f(i - 1), f(i - 1) = f(i)
                before = now;
                now = next;
            }
            printf("%lld\n", now);
        }
    }
    return 0;
}