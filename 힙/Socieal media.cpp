#include <iostream>
#include <vector>
using namespace std;
int like[200000];
vector<int> user[];
vector<int> follow_user[];
void init(int N)
{
    int like[200000] = {
        0,
    }; // 좋아요 수 배열.
    int answer_score = 0;
    // post_arr 초기화.
    for (int i = 0; i < N; i++)
    {
        post_arr[i] = 0;
    }
    vector<int> user[N + 1]; // User vector
    vector<int> follow_user[N + 1];
}

void follow(int uID1, int uID2, int timestamp) // uId1 -> uId2를 timestamp 시간에 follow
{
    follow_user[uID1].push_back(uID2); // user_follow 추가.
}

void makePost(int uID, int pID, int timestamp) // uid가 Pid라는 게시글을 timestmap에 발행
{
    // post[pid]에는 timestamp가 찍혓음
    user[uID].push_back(pID); // user에 추가.
}

void like(int pID, int timestamp) // pid 게시글의 좋아요 수를 ++
{
    like[pID]++; // 좋아요 수 하나 올려줌.
}

void getFeed(int uID, int timestamp, int pIDList[]) // uid가 timestamp시간에 볼 수 있는 feed를 보여줘야함.
{
    // uid가 팔로우한 목록이고, timestamp - 글의 timestamp를 도출해서 우선순위를 결정
    for (int i = 0; i < follow_user[uID].size(); i++)
    {
        int people = follow_user[uID][i]; // UID가 팔로우한 유저
        for (int j = 0; j < user[people].size(); j++)
        {                                // 우선순위 타임스탬프 > 좋아요수 >
            int p_num = user[people][j]; // user가 쓴 pid num
        }
    }
}