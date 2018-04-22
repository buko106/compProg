// I/O
#include <iostream>
#include <iomanip>

// data structures
#include <set>
#include <queue>

// manipulations
#include <algorithm>

#define rep(i,n) for(int (i)=0;(i)< (n);++(i))
#define REP(i,n) for(int (i)=1;(i)<=(n);++(i))
#define for_lowercase(c) for(char (c)='a';(c)<='z';++(c))
#define for_uppercase(c) for(char (c)='A';(c)<='Z';++(c))
#define ALL(a) (a).begin(),(a).end()
using LLI = long long int;
LLI GCD(LLI a,LLI b){ if(a<b) return GCD(b,a); else if(a%b==0) return b; else return GCD(b,a%b); }
LLI LCM(LLI a,LLI b){ return (a/GCD(a,b))*b; }
using VI  = std::vector<LLI>;
using PII  = std::pair<LLI,LLI>;
using VVI = std::vector<VI>;
using VPII = std::vector<PII>;
template<class T> bool is_odd (T x){ return   x%2 ; }
template<class T> bool is_even(T x){ return !(x%2); }
LLI combination(LLI n,LLI k,bool reset=false){
    static VVI C; static LLI n_hashed = -1;
    if(n<0){ std::cerr << "[ERROR] n must be non-negative in combination()" << std::endl; exit(1); }
    if(!(0<=k&&k<=n)){ std::cerr << "[WARNING] k should be in range [0,n] in combination()" << std::endl; return 0; }
    if(n_hashed<n || reset){
        C.resize(n+1);
        for(int i=0;i<=n;++i) C[i].resize(i+1,1); // filled with 1
        for(int i=1;i<=n;++i)for(int j=1;j<i;++j) C[i][j] = C[i-1][j-1] + C[i-1][j];
        n_hashed = n;
    }
    return C[n][k];
}
namespace compProg{
    template<class T> std::ostream& ostream_iterable_impl(std::ostream &os,
                                                          const T &t,
                                                          const std::string &LEFT,
                                                          const std::string &RIGHT,
                                                          const std::string &DELIMITER){
        bool first = true;
        os << LEFT;
        for(const auto &x:t){
            if(first) first = false;
            else os << DELIMITER;
            os << x;
        }
        os << RIGHT;
    }
    void please_never_call_this_function_to_eliminate_warning(){
        is_odd(0); is_even(0); combination(0,0); LCM(0,0);
        rep(i,0)REP(j,0)for_lowercase(c)for_uppercase(c);
        std::sort(ALL(std::string("")));
    }
}
template<class T> std::ostream& operator<<(std::ostream &os,const std::vector<T> &t){
    return compProg::ostream_iterable_impl(os,t,"[","]",", ");
}
template<class T> std::ostream& operator<<(std::ostream &os,const std::set<T> &t){
    return compProg::ostream_iterable_impl(os,t,"{","}",", ");
}
template<class T> std::ostream& operator<<(std::ostream &os,const std::multiset<T> &t){
    return compProg::ostream_iterable_impl(os,t,"{","}",", ");
}

int main() {
    std::ios::sync_with_stdio(false);

    return 0;
}