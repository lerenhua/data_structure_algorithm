#include <iostream>
#include <string>
using namespace std;


int GetInput(string & str)
{
    if (cin >> str)
        return 0;
    else
        return -1;
}

int Flip(string & state, int pos)
{
    if (state[pos] == '0')
        state[pos] = '1';
    else
        state[pos] = '0';
    return 0;
}

int FlipBit(string & state, int pos, int length)
{
    if (pos == 0)  //首位
        Flip(state, pos+1);
    else if (pos == length-1)
        Flip(state, pos-1);
    else
    {
        Flip(state, pos-1);
        Flip(state, pos+1);
    }
    Flip(state, pos);
    return 0;
}

int main()
{
    string init_state, except_state;
    

    /* 处理输入 */
    GetInput(init_state);
    GetInput(except_state);
    if (init_state.size() != except_state.size() || init_state.size() == 0)
        cerr << "Error Input! Try again!\n";


    /* 算法主体 */
    // 密码锁长度不超过30,因此此处不用担心溢出
    int length = init_state.size();

    int ans = 32;
    // 第一种情况
    string temp = init_state;
    int num1 = 0;
    for (int i = 1; i < length; i++)
    {
        if (temp[i-1] != except_state[i-1])
        {
            FlipBit(temp, i, length);
            num1++;
        }
    }
    if (temp[length-1] == except_state[length-1])
        ans = num1;
    
    // 第二种情况
    int num2 = 0;
    
    FlipBit(init_state, 0, length);
    num2++;
    for (int i = 1; i < length; i++)
    {
        if (init_state[i-1] != except_state[i-1])
        {
            FlipBit(init_state, i, length);
            num2++;
        }
    }
    if (init_state[length-1] == except_state[length-1])
        ans = min(ans, num2);

    // 处理最终输出结果
    if (ans == 32) // 没有可行的解
        cout << "impossible\n";
    else
        cout << ans << endl;

    return 0;
}