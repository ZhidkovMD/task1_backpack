#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

using namespace std;
namespace fs = filesystem;

int max(int x, int y){
    return (x > y) ? x : y;
}

int backpack(int W, vector<int> wt, vector<int> val, int n){
    vector<int> dp(W+1);
    fill(dp.begin(), dp.end(), 0);
    for(int i = 1; i < n + 1; i++){
        for(int w = W; w >= 0; w--){
            if(wt[i - 1] <= w){
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[W];
}

int main(){
    string path = "/Users/Михаил/FSR/алгоритмы&прога/4й семестр/backpack";
          auto it = fs::directory_iterator(path);
          vector<fs::path> array_path;
          copy_if(fs::begin(it), fs::end(it), std::back_inserter(array_path),
              [](const auto& entry) {
                  return fs::is_regular_file(entry);
          });
    for (auto& p : array_path) {
        ifstream ff;
        ff.open(p.string());
        cout << p.string() << endl;
        int N, W;
        ff >> n >> W;
        vector<int> vals;
        vector<int> ws;
        for (int i = 0; i < N; i++) {
            int val, wt;
            ff >> val >> wt;
            vals.push_back(val);
            ws.push_back(wt);
        }
        int maxvalue = backpack(W, ws, vals, N);
        cout << maxvalue << endl;
    }
    return 0;
}
