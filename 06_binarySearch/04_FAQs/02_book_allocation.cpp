#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Book Allocation Problem
 * -----------------------------------------------------------------------------
 * You are given 'n' books, where pages[i] is the number of pages in the i-th book.
 * Distribute all books among 'm' students such that:
 *   1. Contiguous allocation: Each student only gets books placed next to each other.
 *   2. Every student gets at least 1 book.
 *   3. Each book goes to only 1 student (cannot split a book).
 *
 * Goal: Minimize the maximum number of pages assigned to any single student.
 * Return -1 if allocation is not possible (e.g., m > n).
 *
 * Time Complexity: O(n * log(sum - max))
 * Space Complexity: O(1)
 * -----------------------------------------------------------------------------
 *
 * Core Intuition (Binary Search on Answer):
 * 1. Search Space [low, high]:
 *    - low = max element in pages (kisi na kisi student ko sabse badi book toh padhni hi padegi, so limit can't be less than this).
 *    - high = sum of all pages (worst case: if m = 1, ek hi student ko saari books milengi).
 *
 * 2. Guess & Check:
 *    - Pick 'mid' as our max page limit per student.
 *    - Check if we can distribute all books within this 'mid' limit using <= 'm' students.
 *    - If YES (true): Limit works! Store 'mid' and search LEFT (high = mid - 1) to try for an even smaller limit.
 *    - If NO (false): Limit is too tight, we ran out of students. Search RIGHT (low = mid + 1) to increase the limit.
 */

// Returns the maximum pages in a single book
int maxi(const vector<int> &pages) {
    int maxPages = INT_MIN;
    for (int page : pages) {
        maxPages = max(maxPages, page);
    }
    return maxPages;
}

// Returns the total sum of pages across all books
int sumOfArr(const vector<int> &pages) {
    int total = 0;
    for (int page : pages) {
        total += page;
    }
    return total;
}

// Greedy check: Can we allocate all books to at most 'm' students without exceeding 'mid' pages per student?
bool isAllocationPossible(const vector<int> &pages, int mid, int m) {
    int allocatedStd = 1;       // Start assigning from the 1st student
    long long currentPag = 0;   // Pages assigned to the current student (long long avoids overflow)

    for (int page : pages) {
        // If a single book exceeds the 'mid' limit, allocation is impossible
        if (page > mid) return false;

        // If adding this book crosses the 'mid' limit, assign it to the next student
        if (currentPag + page > mid) {
            allocatedStd++;
            currentPag = page;
        } else {
            currentPag += page;
        }
    }

    // Why '<= m' instead of '== m'?
    // Agar books 'm' se kam students me hi adjust ho gayi, toh bache hue students ko hum
    // existing piles split karke books de sakte hain — max limit ('mid') phir bhi break nahi hogi.
    return allocatedStd <= m;
}

int bookAllocation(vector<int> &pages, int m) {
    // Edge case: More students than books -> impossible to give at least 1 book to each
    if (m > pages.size()) return -1;

    int low = maxi(pages);
    int high = sumOfArr(pages);
    int ans = -1;

    while (low <= high) {
        int mid = low + ((high - low) / 2);

        if (isAllocationPossible(pages, mid, m)) {
            ans = mid;         // Valid limit found, save it and try for a smaller max on the left
            high = mid - 1;
        } else {
            low = mid + 1;     // Limit too small, increase the limit on the right
        }
    }
    return ans;
}

int main() {
    vector<int> pages = {25, 46, 28, 49, 24};
    int m = 4;

    int ans = bookAllocation(pages, m);
    cout << "Minimum possible max pages: " << ans << endl;

    return 0;
}