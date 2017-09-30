#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define rep(i,n) for(int i=0;i< (n);++i)
#define REP(i,n) for(int i=1;i<=(n);++i)
#define for_lowercase(c) for(int c='a';c<='z';++c)
#define for_uppercase(c) for(int c='A';c<='Z';++c)
#define ALL(a) (a).begin(),(a).end()
using LLI = long long int;
LLI GCD(LLI a,LLI b){ if(a<b) return GCD(b,a); else if(a%b==0) return b; else return GCD(b,a%b); }
LLI LCM(LLI a,LLI b){ return (a/GCD(a,b))*b; }
using VI  = std::vector<LLI>;
using PI  = std::pair<LLI,LLI>;
using VVI = std::vector<VI>;
using VPI = std::vector<PI>;
template<class T> bool is_odd (T x){ return   x%2 ; }
template<class T> bool is_even(T x){ return !(x%2); }

int main() {
    std::ios::sync_with_stdio(false);
    return 0;
}