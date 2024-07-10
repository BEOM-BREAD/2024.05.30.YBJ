#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> argument;
vector<string> babble = { "aya", "ye", "woo", "ma" };

vector<bool> visited;
vector<string> canBabble;

// bubble을 이용해서 만들 수 있는 단어를 다 만들어본다.
// 총 만들수 있는 64가지의 단어
void DFS(int here, string word)
{
    visited[here] = true;
    word += babble[here];

    canBabble.push_back(word);

    for (int there = 0; there < 4; there++)
    {
        if (here == there)
            continue;

        if (visited[there] == true)
            continue;
        
        DFS(there, word);
    }

    visited[here] = false;
}

void DFS_ALL()
{
    for (int i = 0; i < 4; i++)
    {
        DFS(i, "");
    }
}

int solution(vector<string> babbling) 
{
    int answer = 0;
    visited = vector<bool>(4, false);

    DFS_ALL();

    for (auto word : babbling)
    {
        if (canBabble.count(word) != 0)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution(argument) << endl;

    return 0;
}