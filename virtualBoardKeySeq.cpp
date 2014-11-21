//设计一个电视虚拟键盘，按左到右上到下（左对齐）依次是0-9A-Z，
//由于电视宽度不同，每行键位数是个变量（K）。
//电视遥控器有5个按键（U-向上，D-向下，L-向左，R-向右，S-选中输入）。
//光标初始位置在左上角，光标移动期间不可以移动到键盘外。选中某字符后，光标依然停留在原地。
//输入一个字符串+键盘的列数K，输出遥控器按键序列。然后问怎么测试这个接口。

#include <iostream>
#include <utility>
#include <string>

using namespace std;

pair<int,int> getPosition(char ch, int K)
{
    int idx = (ch >= '0' && ch <= '9')? (ch-'0'):(ch-'A'+10);
	return make_pair(idx/K, idx%K);
}

string stepToMove(pair<int,int> &start, pair<int,int> &end)
{
	string result;

	int h_step = end.second - start.second;
	int v_step = end.first - start.first;
    
	if(h_step > 0)
		result.append(h_step, 'R');
	else if(h_step < 0)
		result.append(0-h_step, 'L');

	if(v_step > 0)
		result.append(v_step, 'D');
	else if(v_step < 0)
		result.append(0-v_step, 'U');

	result.push_back('S');

	return result;
}


string keySequence(string &str, int K)
{
    string result;
    pair<int,int> start(0,0);
    
    for(int i=0; i<str.size(); i++)
    {
        pair<int,int> cur = getPosition(str[i], K);
        string seq = stepToMove(start, cur);
        result += seq;
        start = cur;
    }
    return result;
}

int main()
{
    string input1("0123456789");
    string input2("");
    string input3("101");
    string input4("0");
    cout << keySequence(input1, 6) << endl;
    cout << keySequence(input2, 6) << endl;
    cout << keySequence(input3, 6) << endl;
    cout << keySequence(input4, 6) << endl;
    
   return 0;
}
