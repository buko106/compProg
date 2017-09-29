#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i< (n);++i)
#define REP(i,n) for(int i=1;i<=(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define LLI long long int
LLI GCD(LLI a,LLI b){ if(a<b) return GCD(b,a); else if(a%b==0) return b; else return GCD(b,a%b); }
LLI LCM(LLI a,LLI b){ return (a/GCD(a,b))*b; }

int main() {
    std::ios::sync_with_stdio(false);
    return 0;
}