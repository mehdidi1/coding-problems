#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::gcd
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long N{6000000};
    vector<bool> isPrime(N, true);
    vector<long> primeSum(N, 0);
    for (int i = 2; i < std::sqrt(N); i++)
    {
        long temp{i};

        if (isPrime[i])
        {
            primeSum[i] = primeSum[i - 1] + i;
            while (temp+i < N)
            {
                temp = temp +i;
                isPrime[temp] = false;
            }
        }
        else
        {
            primeSum[i] = primeSum[i - 1];
        }
    }

    int t;
    cin >> t;

    while (--t)
    {
        // Input handling
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        long sum{0};

        for (int i : arr)
        {
            sum = sum + i;
        }

        std::sort(arr.begin(), arr.end());

        int siz = arr.size();
        while (sum < primeSum[siz])
        {
            sum = sum - arr[siz-1];
            siz--;
        }
        std::cout << arr.size() - siz << std::endl;
    }

    // Logic to solve the problem
    // ...

    // Output the result
    // ...

    return 0;
}