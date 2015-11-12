////算法训练 2的次幂表示
//问题描述
//　　任何一个正整数都可以用2进制表示，例如：137的2进制表示为10001001。
//　　将这种2进制表示写成2的次幂的和的形式，令次幂高的排在前面，可得到如下表达式：137=2^7+2^3+2^0
//　　现在约定幂次用括号来表示，即a^b表示为a（b）
//　　此时，137可表示为：2（7）+2（3）+2（0）
//　　进一步：7=2^2+2+2^0 （2^1用2表示）
//　　3=2+2^0
//　　所以最后137可表示为：2（2（2）+2+2（0））+2（2+2（0））+2（0）
//　　又如：1315=2^10+2^8+2^5+2+1
//　　所以1315最后可表示为：
//　　2（2（2+2（0））+2）+2（2（2+2（0）））+2（2（2）+2（0））+2+2（0）
//输入格式
//　　正整数（1<=n<=20000）
//输出格式
//　　符合约定的n的0，2表示（在表示中不能有空格）
//样例输入
//137
//样例输出
//2(2(2)+2+2(0))+2(2+2(0))+2(0)
//样例输入
//1315
//样例输出
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//提示
//　　用递归实现会比较简单，可以一边递归一边输出
#include <iostream>
using namespace std;

void func(int a);

int main() {
    int n;
    cin >> n;
    func(n);
    return 0;
}

void func(int a) {
    int i = 0;
    int s[100] = {0};
    if(a == 0) {
        cout << "";
    }
    else {
        while (a != 0) {
            s[i++] = a % 2;
            a = a / 2;
        }
        int t = 0;
        for (int c = 0; c <= i - 1; c++) {
            if (s[c] == 1) {
                t = c;break;
            }
        }
        for (int j = i - 1; j >= t + 1; j--) {
            if (s[j] != 0) {
                if (j == 1) {
                    cout << "2+";
                }
                else if (j == 2) {
                    cout << "2(2)+";
                }
                else {
                    cout << "2(";
                    func (j);
                    cout << ")+";
                    }
            }
        }
        if (t == 0) {
            cout << "2(0)";
        }
        else if (t == 1) {
            cout << "2";
        }
        else if (t == 2) {
            cout << "2(2)";
        }
        else {
            cout << "2(";
            func(t);
            cout << ")";
            
        }
    }
}
