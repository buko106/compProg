
#include <vector>
#include <cassert>

using LLI = long long int;


class UnionFind {
private:
    inline void assert_initialized() {
        assert(size > 0);
    }
    std::vector<LLI> rank;
public:
    std::vector<LLI> parent;
    LLI size = 0;

    void init(LLI size) {
        this->size = size;
        rank.resize(size, 0);
        parent.resize(size);
        for(LLI i = 0 ; i < size ; ++i) {
            parent[i] = i;
        }
    }

    LLI find(LLI x) {
        assert_initialized();
        if(parent[x] == x) {
            return x;
        }
        LLI root = find(parent[x]);
        parent[x] = root;
        return root;
    }

    bool is_same(LLI x, LLI y) {
        assert_initialized();
        return find(x) == find(y);
    }

    void unite(LLI x, LLI y) {
        assert_initialized();
        x = find(x);
        y = find(y);

        if(x==y) return;
        if(rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            if(rank[x]==rank[y]) ++rank[x];
            parent[y] = x;
        }
    }
};
