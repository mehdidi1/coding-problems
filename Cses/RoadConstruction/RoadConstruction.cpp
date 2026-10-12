#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

template <typename T> void print_arr(const vector<T> &arr);
template <typename T> T mod(T x, T n);


/// @brief Disjoint Set Union (union-find) over dense indices [0, n).
///
/// Uses path compression and union by size: amortized O(α(n)) per operation,
/// where α is the inverse Ackermann function (≤ 4 for any practical n).
///
/// @tparam Index Integral type used for element indices and sizes (default int).
template <class Index = int> class DSU {
  public:
    /// @brief Creates n singleton components {0}, {1}, …, {n-1}.
    /// @param n Initial number of elements (default 0, grow with add()).
    explicit DSU(Index n = 0) : parent_(n), size_(n, 1), components_(n),max_size_(1) {
        std::iota(parent_.begin(), parent_.end(), Index{0});
    }

    /// @brief Returns the representative (root) of x's component.
    ///
    /// Compresses the path: every node visited ends up pointing directly at the root.
    /// Recursion depth ≤ log2(n), guaranteed by union by size in unite().
    /// @pre 0 <= x < number of elements.
    Index find(Index x) {
        if (x != parent_[x]) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }

    /// @brief Merges the components containing a and b.
    ///
    /// The smaller component is attached under the root of the larger one.
    /// @return true if a merge happened, false if a and b were already connected.
    bool unite(Index a, Index b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size_[a] < size_[b]) {
                std::swap(a, b);
            }
            parent_[b] = a;
            size_[a] += size_[b];
            max_size_ = max(max_size_,size_[a]);
            components_--;
        }
        return (a != b);
    }

    /// @brief Adds a new singleton element.
    /// @return Index of the new element (equal to the previous element count).
    Index add() {
        Index idx = static_cast<Index>(parent_.size());
        parent_.push_back(idx);
        size_.push_back(1);
        components_++;
        return idx;
    }

    /// @brief Checks whether a and b are in the same component.
    bool same(Index a, Index b) { return find(a) == find(b); }

    size_t max_size(){
        return max_size_;
    }

    /// @brief Returns the number of elements in x's component.
    Index size(Index x) { return size_[find(x)]; }

    /// @brief Returns the current number of components. O(1).
    Index count() const { return components_; }

  private:
    std::vector<Index> parent_; ///< parent_[x] == x iff x is a root.
    std::vector<Index> size_;   ///< Component size; only valid at roots.
    Index components_;          ///< Number of components, maintained incrementally
    Index max_size_;
};

/// @brief Disjoint Set Union over arbitrary hashable keys, built on DSU<Index>.
///
/// Each key is mapped to a dense index on first use. Calling unite(), same()
/// or size() with an unseen key registers it as a new singleton component,
/// so count() reflects only keys seen so far.
///
/// @tparam T     Key type.
/// @tparam Index Integral index type of the underlying DSU (default int).
/// @tparam Hash  Hash functor for T (default std::hash<T>).
template <class T, class Index = int, class Hash = std::hash<T>>
class KeyedDSU {
  public:
    /// @brief Creates an empty structure; keys are added on first use.
    KeyedDSU() = default;

    /// @brief Merges the components containing a and b. Registers unseen keys.
    /// @return true if a merge happened, false if a and b were already connected.
    bool unite(const T& a, const T& b) { return dsu_.unite(get_id(a), get_id(b)); }

    /// @brief Checks whether a and b are in the same component. Registers unseen keys.
    bool same(const T& a, const T& b) { return dsu_.same(get_id(a), get_id(b)); }

    /// @brief Returns the number of keys in x's component. Registers x if unseen.
    Index size(const T& x) { return dsu_.size(get_id(x)); }

    /// @brief Returns the current number of components among keys seen so far. O(1).
    Index count() const { return dsu_.count(); }

  private:
    /// @brief Returns x's index, registering x as a new singleton if unseen.
    Index get_id(const T& x) {
        auto it = id_.find(x);
        if (it != id_.end()) return it->second;
        Index id = dsu_.add();
        id_.emplace(x, id);
        return id;
    }

    DSU<Index> dsu_;                         ///< Underlying index-based DSU.
    std::unordered_map<T, Index, Hash> id_;  ///< Key → dense index.
};
void solve() {
    int n ,m;
    cin >> n >> m;
    DSU<int> dsu(n) ;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >>b;
        dsu.unite(a-1, b-1);
        cout << dsu.count() << " " << dsu.max_size() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}

template <typename T> void print_arr(const vector<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size())
            cout << " ";
    }
    cout << endl;
}
template <typename T> T mod(T x, T n) { return ((x % n) + n) % n; }
