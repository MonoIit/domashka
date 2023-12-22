#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int countWaysRecursive(int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    return countWaysRecursive(N - 1) + countWaysRecursive(N - 2) + countWaysRecursive(N - 3);
}

int countWays(int N) {
    if (N == 0) return 1;
    if (N == 1) return 1;
    if (N == 2) return 2;

    vector<int> dp(N + 1);
    dp[0] = 1; // 1 ������ ��������� �� ������ ��������
    dp[1] = 1; // 1 ������ ��������� �� ������ ���������
    dp[2] = 2; // 2 ������� ��������� �� ������ ���������

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[N];
}

void algoritm() {
    int N = 30; // ����� ���������� ������ �������� ��� N

    auto start_rec = chrono::high_resolution_clock::now();
    cout << "����������: " << countWaysRecursive(N) << endl;
    auto end_rec = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec = end_rec - start_rec;
    cout << "����� ���������� ���������: " << elapsed_rec.count() << " ��" << endl;

    auto start_dp = chrono::high_resolution_clock::now();
    cout << "� �������������� ��: " << countWays(N) << endl;
    auto end_dp = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_dp = end_dp - start_dp;
    cout << "����� ���������� � �������������� ��: " << elapsed_dp.count() << " ��" << endl;

}


