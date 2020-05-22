#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

const int ALPHABETS = 26;
struct Trie
{
    bool is_terminal;
    Trie *children[ALPHABETS];
    unordered_map<int, int> mp;

    Trie()
    {
        is_terminal = false;
        fill(children, children + ALPHABETS, nullptr);
    }
    ~Trie()
    {
        for (int i = 0; i < ALPHABETS; i++)
        {
            if (children[i])
                delete children[i];
        }
    }
    void insert(const char *key, int length)
    {
        if (*key == '\0')
        {
            is_terminal = true;
            return;
        }
        int idx = *key - 'a';
        mp[length] += 1;
        if (!children[idx])
        {
            children[idx] = new Trie;
        }
        children[idx]->insert(key + 1, length);
    }
    int find(const char *key, int length)
    {
        if (*key == '\0')
            return is_terminal;
        int ret = 0;
        int idx = *key - 'a';
        if (*key == '?')
        {
            ret += mp[length];
        }
        else
        {
            if (!children[idx])
                return 0;
            ret = children[idx]->find(key + 1, length);
        }
        return ret;
    }
};

vector<int> solution(vector<string> w, vector<string> q)
{
    Trie *front = new Trie;
    Trie *back = new Trie;

    int wsize = w.size(), qsize = q.size();
    for (int i = 0; i < wsize; i++)
    {
        string s = w[i];
        front->insert(&s[0], s.size());
        reverse(s.begin(), s.end());
        back->insert(&s[0], s.size());
    }

    vector<int> answer(qsize, 0);
    for (int i = 0; i < qsize; i++)
    {
        string query = q[i];
        if (query[0] != '?')
        {
            //forward
            answer[i] = front->find(&query[0], query.size());
        }
        else
        {
            reverse(query.begin(), query.end());
            answer[i] = back->find(&query[0], query.size());
        }
    }
    return answer;
}
int main(void)
{

    return 0;
}