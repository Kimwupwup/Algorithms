/**
 * 백준 11728번 - 배열 합치기
 * 
 * TODO:
 * 병합 정렬
 * */
#include <iostream>

using namespace std;

const int MAX = 1000000;
int A[MAX], B[MAX], temp[MAX * 2];
int N, M;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    int idx_a = 0;
    int idx_b = 0;
    int idx = 0;
    while (!(idx_a == N && idx_b == M)) {
        if (idx_a == N) {
            temp[idx++] = B[idx_b++];
        }
        else if (idx_b == M) {
            temp[idx++] = A[idx_a++];
        }
        else if (A[idx_a] < B[idx_b]) {
            temp[idx++] = A[idx_a++];
        }
        else if (A[idx_a] >= B[idx_b]) {
            temp[idx++] = B[idx_b++];
        }
    }
    for (int i = 0; i < N + M; i++) {
        cout << temp[i] << " ";
    }
    return 0;
}