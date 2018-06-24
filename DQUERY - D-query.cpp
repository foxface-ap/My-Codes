#include <bits/stdc++.h>

using namespace std;

int current_answer,answers[200500],BLOCK_SIZE,arr[30500],mp[1000100];

pair< pair<int, int>, int> queries[200500];

inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

inline void add(int x)
{
    if(mp[x] == 0)
        current_answer++;
    mp[x]++;
}

inline void remove(int x)
{
    if(mp[x] == 1)
        current_answer--;
    mp[x]--;
}

int main()
{
    cin.sync_with_stdio(false);

    int N, Q;
    cin >> N;

    BLOCK_SIZE = static_cast<int>(sqrt(N));

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> Q;

    int x,y;

    for(int i = 0; i < Q; i++) 
    {
        cin >> x >> y;
        queries[i].first.first = x-1;
        queries[i].first.second = y-1;
        queries[i].second = i;
    }

    sort(queries, queries + Q, mo_cmp);

    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < Q; i++) 
    {
        int left = queries[i].first.first;
        int right = queries[i].first.second;

        while(mo_right < right) 
        {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right > right) 
        {
            remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) 
        {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) 
        {
            mo_left--;
            add(arr[mo_left]);
        }

        answers[queries[i].second] = current_answer;
    }

    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n";
    return 0;
}