/*
 * Verified by https://beta.atcoder.jp/contests/abc087/tasks/arc090_b
 */


#include <vector>
#include <cassert>

using LLI = long long int;


template<class Abel=LLI> class UnionFind {
private:
    inline void assert_initialized() {
        assert(size > 0);
    }
    Abel diff_to_root(LLI x) {
        assert_initialized();
        find(x); // connect directly to root
        return diff_to_parent[x];
    }
    std::vector<LLI> rank;
    std::vector<Abel> diff_to_parent;
    Abel UNIT;
public:
    std::vector<LLI> parent;
    size_t size = 0;

    void init(const size_t size, const Abel UNIT_ABEL = 0) {
        this->size = size;
        this->UNIT = UNIT_ABEL;
        rank.resize(size, 0);
        diff_to_parent.resize(size, UNIT_ABEL);
        parent.resize(size);
        for(LLI i = 0 ; i < size ; ++i) {
            parent[i] = i;
        }
    }

    LLI find(const LLI x) {
        assert_initialized();
        if(parent[x] == x) {
            return x;
        }
        LLI root = find(parent[x]);
        diff_to_parent[x] = diff_to_parent[x] + diff_to_parent[parent[x]];
        parent[x] = root;
        return root;
    }

    bool is_same(const LLI x, const LLI y) {
        assert_initialized();
        return find(x) == find(y);
    }

    bool unite(const LLI x, const LLI y, const Abel d = 0) { // false if d is invalid
        assert_initialized();

        Abel diff_from_root_x_to_root_y = (d + diff_to_root(x)) - diff_to_root(y);
        LLI root_x = find(x);
        LLI root_y = find(y);

        if (root_x == root_y) return d == diff(x,y); // invalid input of d
        if (rank[root_x] < rank[root_y]) {
            std::swap(root_x,root_y);
            diff_from_root_x_to_root_y = this->UNIT - diff_from_root_x_to_root_y;
        }
        if (rank[root_x] == rank[root_y]) ++rank[root_x];
        parent[root_y] = root_x;
        diff_to_parent[root_y] = diff_from_root_x_to_root_y;
        return true;
    }

    Abel diff(LLI x, LLI y) {
        assert(is_same(x,y));
        return diff_to_root(y) - diff_to_root(x);
    }
};
