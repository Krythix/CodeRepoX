#include <iostream>
#include <algorithm>
#include <functional>
#include <optional>
#include <cmath>

using namespace std;

constexpr int N=10000;
int arr[N];

// find the last ele which equals to k
int bsearch1(int arr[], int n, int k) {
    int l=0, r=n;
    int mid = (l+r)/2;
    while(l != r-1) {
        if(arr[mid] > k) {
            r = mid;
        } else if(arr[mid] <= k) {
            l = mid;
        }
        mid = (l+r)/2;
    }
    return arr[l] == k ? l : -1;
}

// find the first ele which equals to k
int bsearch2(int arr[], int n, int k) {
    int l=-1, r=n-1;
    int mid = (l+r+1)/2;
    while(l != r-1) {
        if(arr[mid] >= k) {
            r = mid;
        } else if(arr[mid] < k) {
            l = mid;
        }
        mid = (l+r+1)/2;
    }
    return arr[r] == k ? r : -1;
}

/**
 * @berif: find the resolution of func
 * @parm func : func should single in (a,b)
 * @parm a, b : range(a, b)
 */
bool bsearch_func(function<double (double)> func, double a, double b, double yk, double& result, double jing=0.01) {
    // let func(a) < func(b)
    if(func(a) > func(b)) {
        return bsearch_func([func](double x){return -func(x);}, a, b, -yk, result, jing);
    }
    double l=a, r=b;
    double mid=(l+r)/2;
    while(l<r) {
        double y = func(mid);
        double dis = abs(y - yk);
        if(dis < jing) {
            result = mid;
            return true;
        } else if(y > yk) {
            r = mid;
        } else { //(y < yk)
            l = mid;
        }
        mid = (l+r)/2;
    }
    return false;
}


int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++) {
        int index = bsearch1(arr, n, arr[i]);
        int correct = 0;
        if(arr[index] == arr[i]) {
            if(index <= n-2) {
                if(arr[index+1] != arr[i]) {
                    correct = 1;
                }
            } else {
                correct = 1;
            }
        }
        cout << correct << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++) {
        int index = bsearch2(arr, n, arr[i]);
        int correct = 0;
        if(arr[index] == arr[i]) {
            if(index >= 1) {
                if(arr[index-1] != arr[i]) {
                    correct = 1;
                }
            } else {
                correct = 1;
            }
        }
        cout << correct << " ";
    }
    cout << endl;

    auto func = [](double x){
        return sqrt(x);
    };
    int split = 100;
    for(int i=0; i<split; i++) {
        int a=0, b=10;
        double ya = func(a), yb=func(b);
        double result;
        double target = (double)i*(b-a)/split;
        bool correct = 0;
        if(bsearch_func(func, a, b, target, result, 0.0001)) {
            // cout << func(result) << " " << target << endl;
            if(abs(func(result) - target) <= 0.0001) {
                correct = 1;
            }

        } else {
            if(ya <= target && target <= yb) {
                correct = 0;
            } else {
                correct = 1;
            }
        }
        cout << correct << " ";
    }
    cout << endl;
    return 0;
}