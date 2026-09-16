# 🧠 DSA Pattern Bible

> **Your personal pattern book.** One chapter per Striver section. After you finish a section, tell me — I will add its chapter here. Read it before interviews. Revise it with the tables (cover the right column and guess!).

---

# 📖 Chapter 1 — Arrays (Striver Step 3: Easy → Medium → Hard)

## 1.1 The big idea (read this first — 2 minutes)

Most array problems are one of only **3 jobs**:

| Job                     | Meaning                            | Example                         |
| ----------------------- | ---------------------------------- | ------------------------------- |
| **Find something**      | an element, a max, a missing value | largest element, missing number |
| **Count something**     | subarrays, pairs, triplets         | count subarrays with sum K      |
| **Rearrange something** | sort, rotate, move, merge          | move zeros, rotate by D         |

And the **naive way** is always slow:

> _"Try all pairs"_ → O(n²) · _"Try all subarrays"_ → O(n²) or O(n³)

Every single pattern in this chapter is **one trick to remove one loop**. That's it. Nothing magical.

**The golden rule of time limits:**

| n (array size) | Safe complexity                                |
| -------------- | ---------------------------------------------- |
| up to 10³      | O(n²) is fine                                  |
| up to 10⁵      | **O(n) or O(n log n) needed** — O(n²) will TLE |
| up to 10⁶      | O(n) or O(n log n), and be careful with memory |

**Two questions decide 80% of array problems:**

1. **Does order matter?** (Is it a _subarray_ = contiguous, or a _pair/triplet_ = any selection?)
2. **Is the array sorted — or can I sort it?**

---

## 1.2 Words you must know (simple meanings)

| Word | Simple meaning |
| --- | --- |
| **Subarray** | A **continuous** block. Like coaches attached in a train. `[2,3,4]` is a subarray of `[1,2,3,4,5]`. |
| **Subsequence** | Pick some elements, keep their order, gaps allowed. |
| **Subset** | Any selection, order doesn't matter. |
| **Prefix sum** | The running total from the start. Like your bill total as you keep adding items. |
| **In-place** | Solve it using **almost no extra memory** (no new big array). |
| **Brute force** | The straightforward, slow solution (try everything). |
| **Pairs (i < j)** | Two positions where the first comes **before** the second. |

---

## 1.3 The Thinking Flow 🧭 (use this before EVERY problem)

Answer these 6 questions out loud. It takes 30 seconds and it kills "beating my head".

**Q1. What am I returning?** A value? An index? A count? A changed array? A list of answers?

**Q2. Is it about a SUBARRAY (contiguous) or a SELECTION (any elements)?**

- Subarray → **Prefix-sum map** / **Sliding window** / **Kadane-state** (P6, P8, P9)
- Selection → **Sort + two pointers** / **Hashmap** (P7, P10)

**Q3. Is the array sorted? If not — CAN I SORT IT?**

- "Can I sort it?" = _Does the answer care about the original position?_
- Sorting is free help if order doesn't matter.
- If it's sorted already → two pointers from both ends / merge pointers / binary search.

**Q4. What is the brute force? Where is the repeated work?**

- "Trying all subarrays" → one of the subarray tricks removes that loop.
- "Trying all pairs/triplets" → sort + two pointers or hashmap removes that loop.

**Q5. Any special constraint?** In-place? No extra space? All positive numbers? (These **change which pattern** you may use!)

**Q6. Which pattern does it smell like?** → Check the Map below.

Then: **dry-run on a tiny example (4–5 numbers, draw it), code it, state the complexity.**

---

## 1.4 ⚡ The 80% Table (the "don't beat your head" map)

This is the most important table of the whole chapter. **Memorize it.**

| If the problem says… | The pattern is… |
| --- | --- |
| "subarray with sum K" + **count** or **length** (negatives allowed) | **Prefix sum + hashmap** (P8) |
| "subarray with sum K" + **all elements positive** | **Sliding window** (P9) |
| "**maximum** sum/product of a subarray" | **Kadane running state** (P6) |
| "subarray with XOR K" / "subarray with 0 sum" | **Prefix sum + hashmap** (XOR version) (P8) |
| "find 2 / 3 / 4 numbers that sum to K" | **Sort + two pointers** (P7) |
| "count pairs i < j where a[i] > (2·)a[j]" | **Merge sort counting** (P15) |
| "appears once, others twice" / "missing number" | **XOR or math formula** (P11) |
| "element appearing more than n/2 (or n/3) times" | **Boyer–Moore voting** (P5) |
| "sort 0s, 1s, 2s" / "partition into 3 groups" | **Dutch National Flag** (P4) |
| "remove duplicates in-place" / "move zeros to end" | **Reader–writer pointers** (P3) |
| "two sorted arrays" / "union / merge" | **Merge pointers**; no-extra-space → **gap method** (P12) |
| "merge overlapping intervals" | **Sort + one pass merge** (P13) |
| "rotate matrix / spiral / set zeros" | **Matrix tricks** (P14) |
| "next permutation" | **3-step algorithm** (P14b) |
| "longest consecutive sequence" | **Set + count runs** (P10) |
| "leaders / second largest / sorted check" | **Single-pass tracking** (P1) |

---

## 1.5 The patterns in detail

---

### P1. Single-pass tracking — "walk and remember" 🚶

**What it is:** Walk the array once, left to right, carrying 1–3 small variables that hold "the best answer so far". At each element, update the variables. When the walk ends, the variables have the answer.

**Spot it:** "largest", "second largest", "is it sorted", "most consecutive ones", "leaders", "maximum in one pass". If each element needs only 1–2 comparisons and no reordering → this pattern.

**Recipes** (all O(n) time, O(1) space):

| Problem | Recipe |
| --- | --- |
| Largest element | `best = max(best, a[i])` |
| Second largest | keep `largest` and `second`; update both; use **strict** comparisons so duplicates don't count |
| Check array sorted | `a[i] >= a[i-1]` for all i → sorted (non-decreasing) |
| Max consecutive ones | `cnt = (a[i]==1) ? cnt+1 : 0; ans = max(ans, cnt)` |
| Leaders | walk from the **right**, keep `maxSoFar`; `a[i] > maxSoFar` → it's a leader |

**Trap 🚨:** Leaders must be checked **right to left** (a leader is greater than everything on its right). Second-largest needs duplicate handling (`x > largest` vs `x > second && x != largest`).

**Interview one-liner:** _"Single pass, O(n) time, O(1) space — no sorting needed."_

---

### P2. Running state — the Kadane family "best ending here" 🏃

**What it is:** For "best contiguous subarray" problems, at each index compute the best subarray that **ends exactly here**, then keep the overall max. The state is tiny (1–2 numbers), so it's O(1) space.

**Spot it:** "maximum subarray **sum**", "maximum subarray **product**", "best time to buy & sell", "best … that ends at i".

**Recipes:**

| Problem | Recipe | Trick |
| --- | --- | --- |
| **Kadane: max subarray sum** | `cur = max(x, cur + x); ans = max(ans, cur)` | if `cur` is negative, better to start fresh from `x` |
| **Print that subarray** | same, plus remember the start index whenever `cur` restarts, and start/end when `ans` updates | track `start` & `tempStart` |
| **Max product subarray** | keep `maxEnd` AND `minEnd`: `newMax = max(x, maxEnd*x, minEnd*x)`; `newMin = min(x, maxEnd*x, minEnd*x)`; update both from **old** values | negative × negative = positive, so the min state can become the max! |
| **Stock buy & sell** | `minPrice = min(minPrice, price); profit = max(profit, price - minPrice)` | keep the cheapest day seen so far; try selling today |

**Trap 🚨:** In max product, compute `newMax` and `newMin` **both from the old values** before overwriting (don't use the new max to compute the new min). A zero resets everything (subarray must be contiguous).

**Interview one-liner:** _"I keep a small state: the best subarray ending at the current position. That gives O(n) time, O(1) space."_

---

### P3. Reader–writer pointers — "in-place rewrite" ✍️

**What it is:** Two pointers moving the same direction. One **reads** ahead (fast), one **writes** (slow). The write pointer only moves for elements that stay.

**Spot it:** "in-place", "remove/compress", "relative order must be kept", "O(1) extra space".

**Recipes:**

| Problem | Recipe |
| --- | --- |
| Remove duplicates (sorted array) | `write` starts at 1; if `a[read] != a[write-1]` → `a[write++] = a[read]`; return `write` |
| Move zeros to end | `write` = position of next non-zero; if `a[read] != 0` → `swap(a[write++], a[read])` |

**Why it works:** the write pointer **never outruns** the read pointer, so you can overwrite safely — the elements you overwrite are already processed.

**Trap 🚨:** For "move zeros", **swap** (don't blindly overwrite) — this keeps the relative order of non-zero elements, which is usually required.

**Interview one-liner:** _"The write pointer never outruns the read pointer, so overwriting is safe."_

---

### P4. Dutch National Flag — "divide into 3 groups" 🚦

**What it is:** Sort an array of only 0s, 1s, 2s in **one pass** with 3 pointers:

- `low` = end of the 0s region
- `mid` = the scanner (current element)
- `high` = start of the 2s region

**Recipe:**

```
while (mid <= high):
    if a[mid] == 0:  swap(a[low++], a[mid++])      # 0 goes to the left
    elif a[mid] == 1: mid++                          # 1 is already in place
    else:            swap(a[high--], a[mid])        # 2 goes to the right — DON'T move mid!
```

**Spot it:** "sort an array of 0s, 1s, 2s", "sort with three colors", "partition into three groups".

**Trap 🚨:** After swapping with `high`, **do not move `mid`** — the element that came back could be a 0 or a 2 that still needs processing. Condition is `mid <= high`.

**Interview one-liner:** _"One pass, no extra space — it's a 3-way partition."_

---

### P5. Boyer–Moore voting — "candidates cancel each other" 🗳️

**What it is:** If an element appears more than half the time, no matter how you pair it with other elements, it can **never be fully cancelled**. So you keep a candidate + a counter: match → +1, no match → −1, counter hits 0 → pick a new candidate.

**Recipe for n/2 (majority element):**

```
candidate = a[0]; count = 1
for x in a[1:]:
    if x == candidate: count++
    else: count--; if count == 0: candidate = x; count = 1
# VERIFY: count how many times candidate appears; it must be > n/2
```

**Recipe for n/3 (two candidates):** keep `e1, c1, e2, c2`.

```
if x == e1: c1++
elif x == e2: c2++
elif c1 == 0: e1 = x, c1 = 1
elif c2 == 0: e2 = x, c2 = 1
else: c1--, c2--
```

Then **verify both** by a counting pass. (At most 2 candidates can pass n/3.)

**Spot it:** "appears more than n/2 (or n/3) times", "majority element".

**Trap 🚨:** The voting pass alone doesn't guarantee a majority — **always do a verification pass**. For n/3, two candidates are possible.

**Interview one-liner:** _"O(n) time, O(1) space. The intuition: a majority element can never be fully cancelled."_

---

### P6. Two-pointer merge — "two sorted arrays" 🤝

**What it is:** One pointer in each array; move the smaller one forward.

**Problems it solves:**

- **Union of two sorted arrays:** compare heads; push the smaller; skip duplicates.
- **Merge two sorted arrays WITH extra space:** standard merge (the merge step of merge sort).

**Hard variant — merge WITHOUT extra space → Gap method (Shell-sort style):**

```
gap = ceil((n + m) / 2)
while gap >= 1:
    walk both arrays as one logical array; for every pair (i, i+gap):
        if left > right: swap them
    gap = ceil(gap / 2)   # i.e. gap = gap/2 + gap%2
```

Think of it as: sort the two arrays together using a **shrinking gap**. When gap becomes 1, everything is sorted.

**Spot it:** "two sorted arrays", "merge them", "union/intersection", "without extra space".

**Trap 🚨:** In the gap method, shrink by `ceil(gap/2)` and stop when gap becomes 0 (after gap = 1 pass). Careful with indices when `i` crosses into the second array (`j = i + gap - n`).

**Interview one-liner:** _"With extra space it's a trivial linear merge. Without it, the gap method gives O((n+m) log(n+m)) with O(1) space."_

---

### P7. Sort + two pointers — the k-sum family 🎯

**What it is:** Sort the array. Fix one element (or two), then walk a two-pointer from both ends of the remaining part. Because it's sorted, you know which way to move to fix the sum.

**2-Sum (values):** hashmap — store seen values, look for `K - x`. (Or sort + two pointers.)

**3-Sum recipe:**

```
sort(a)
for i in 0..n-1:
    target = -a[i]
    l = i+1, r = n-1
    while l < r:
        s = a[l] + a[r]
        if s == target:  record (a[i], a[l], a[r]); l++; r--; skip duplicates on both sides
        elif s < target: l++
        else: r--
    skip duplicate a[i] values
```

**4-Sum recipe:** same idea — fix `i` and `j` with two outer loops (`i < j`), then two-pointer `l, r` inside. Skip duplicates at every level.

**Why skipping duplicates is compulsory:** the question usually says "unique triplets". Without skipping, you produce duplicate answers and might TLE.

**Spot it:** "find triplets / pairs / quadruplets adding to X", "3sum / 4sum", "unique".

**Trap 🚨:**

- Skip duplicates **after** moving pointers: `while (l < r && a[l] == a[l+1]) l++` etc.
- Also skip duplicate fixed elements (`a[i] == a[i-1]` → continue).
- Use **long** for sums — values can overflow int.

**Interview one-liner:** _"Sort first: O(n log n). Then fixing one element makes it a 2-sum on the rest → two pointers → O(n²) total for 3-sum."_

---

### P8. Prefix sum + hashmap — the subarray hero 🧾

**The core identity (memorize this):**

> Sum of subarray `(i .. j)` = `prefix[j] - prefix[i-1]`

So:

> "Find a subarray with sum K" ⟺ "find **two prefix sums whose difference is K**"

And since you compute the running prefix as you walk, a hashmap of seen prefix sums answers each step in O(1).

**Recipes:**

| Problem | Recipe |
| --- | --- |
| **Count subarrays with sum K** | `map = {0:1}`; `s = 0`; for each x: `s += x; ans += map.get(s - K, 0); map[s]++` |
| **Count subarrays with XOR K** | same but `s ^= x; ans += map.get(s ^ K, 0); map[s]++` |
| **Longest subarray with 0 sum** | store the **first index** where each prefix sum appears; if `s` repeats, the stretch between is 0-sum → `ans = max(ans, i - firstIndex[s])` |
| **Longest subarray with sum K (negatives allowed)** | store first index of each prefix sum; when `s - K` was seen at index `j`, `i - j` is a candidate length |

**Spot it:** "subarray" + "sum K"/"XOR K"/"0 sum" + "count" or "longest" + **negatives allowed**.

**Trap 🚨:**

- **Start the map with `{0: 1}`** — a subarray can start at index 0 (empty prefix).
- "Count" → store **frequency**. "Longest" → store **first index**.

**Interview one-liner:** _"The trick is turning 'subarray sum' into 'difference of two prefix sums', then answering it with a hashmap in O(n)."_

---

### P9. Sliding window (variable size) 🪟

**What it is:** Keep a window `[l, r]`. Grow `r`. While the window is invalid, shrink from `l`. Track the answer when the window is valid. The window's sum is updated incrementally — no recomputation.

**Recipe — Longest subarray with sum K (all positives):**

```
s = 0; l = 0; ans = 0
for r in 0..n-1:
    s += a[r]
    while s > K:  s -= a[l]; l++       # shrink
    if s == K:    ans = max(ans, r - l + 1)
```

**Spot it:** "longest subarray" + **all elements positive** + a sum condition. O(n) time, **O(1) space**.

**Trap 🚨:** Sliding window **fails with negative numbers** (shrinking doesn't guarantee the sum goes down). With negatives → use the prefix-sum map (P8).

**Interview one-liner:** _"Because all numbers are positive, shrinking the window monotonically decreases the sum, so the two-pointer window is O(n) with O(1) space."_

---

### P10. Hashmap / Set — "have I seen this before?" 🔍

**Problems it solves:**

- **2-Sum:** store values seen so far, check for complement.
- **Longest consecutive sequence:** put all in a **set**; only start counting from a number where `x - 1` is NOT in the set (that's the start of a run); count upward.
- **Frequency problems** (count elements, majority via counts — usually spread across questions).
- **Find repeating & missing (brute approach):** frequency array of size n; values 1..n are in bounds.

**Spot it:** "duplicates", "frequency", "have I seen this", "exists quickly", "unique".

**Trap 🚨:** Longest consecutive sequence: if you start counting from **every** element, it's O(n²). Only count from run starts (`x-1` absent).

**Interview one-liner:** _"Set gives O(1) membership. For longest consecutive, counting only from run starts keeps it O(n)."_

---

### P11. XOR & math magic ✨ (the "no extra space" weapons)

**The two magic facts:**

- `x ^ x = 0` (equal numbers cancel)
- `x ^ 0 = x`

So **XOR everything twice-appearing → it vanishes**.

| Problem | Approach |
| --- | --- |
| **Number appearing once (others twice)** | XOR the whole array → answer |
| **Missing number** | `XOR(1..n) ^ XOR(array)` → answer |
| **Missing & repeating (XOR way)** | ① `xr = XOR(1..n) ^ XOR(array)` → `x ^ y` (x = missing, y = repeated). ② Pick any set bit of `xr` (e.g. `xr & -xr`). ③ Split all numbers (array + 1..n) into 2 groups by that bit; XOR each group → `x` and `y`. ④ One scan of the array decides which is missing and which is repeated. |
| **Missing & repeating (math way)** | Let `S = n(n+1)/2`, `Sq = n(n+1)(2n+1)/6`. `S - sum(arr) = x - y`. `Sq - sumsq(arr) = x² - y² = (x-y)(x+y)`. Solve the two equations → get `x` and `y`. Verify with one scan. |

**Spot it:** "appears once / others twice", "missing number", "repeating & missing", "do it with O(1) space / without a hashmap".

**Trap 🚨:**

- Sum of squares **overflows int** → use `long`.
- After the XOR trick, the two found numbers are mixed up — **scan once** to find which is the repeated one.

**Interview one-liner:** _"XOR cancels equal pairs — any element with even frequency disappears. Perfect for O(1) space."_

---

### P12. Intervals — "sort, then merge the chain" 📅

**Recipe — merge overlapping intervals:**

```
sort intervals by start time
cur = intervals[0]
for each next interval:
    if next.start <= cur.end:   cur.end = max(cur.end, next.end)   # overlap → merge
    else:                       push cur; cur = next
push cur
```

**Spot it:** "intervals", "merge overlapping", "meeting/class timings".

**Trap 🚨:** Sort by **start**, not end. After merging, compare against the **updated** `cur.end`.

**Interview one-liner:** _"Once sorted by start, overlapping intervals form a chain — one greedy pass merges them."_

---

### P13. Next permutation — the 3-step algorithm 🔢

**Recipe:**

```
1. From the right, find the first i where a[i] < a[i+1]   ("the dip")
   If none exists → the array is the last permutation → reverse the whole array.
2. From the right, find the first j where a[j] > a[i]. Swap a[i] and a[j].
3. Reverse the tail a[i+1 .. end].
```

Intuition: the dip is where the previous arrangement can be increased _barely_; you swap with the just-bigger element, then sort the tail (it's already descending, so reversing sorts it!).

**Spot it:** "next permutation", "next lexicographic arrangement", "next greater number with same digits".

**Trap 🚨:** Fully descending array → answer is the fully sorted array (wrap-around to the first permutation).

**Interview one-liner:** _"It's a fixed 3-step pattern: find the dip, swap with the just-bigger, reverse the tail."_

---

### P14. Matrix (2D) tricks 🧩

| Problem | Recipe |
| --- | --- |
| **Set matrix zeros** | Use the **first row** and **first column** as the flag rows: pass 1 marks which rows/cols must become 0; pass 2 sets them. Keep a separate boolean for `col0` because cell (0,0) is shared. (Or simply use `row[]` and `col[]` arrays — simpler, O(n+m) space.) |
| **Rotate by 90° (clockwise)** | ① Transpose: swap `a[i][j]` with `a[j][i]` (only `i < j`). ② Reverse **each row**. |
| **Spiral traversal** | 4 boundaries: `top, bottom, left, right`. Loop: go right, then down, then left, then up; shrink the boundary after each side. Check `top <= bottom && left <= right` in **each** of the 4 loops. |
| **Pascal's triangle** | Row `r` has `r+1` elements; first & last are 1; middle = `prev[j-1] + prev[j]`. (Also: the nth row = nCr values.) |

**Spot it:** "matrix", "2D array", "rotate image", "spiral order", "set zeros", "pascal".

**Trap 🚨:** Spiral with a single row or single column → double printing if you don't check bounds in each loop. Transpose must only swap `i < j` (else you swap back). In the in-place set-zeros, (0,0) collision is the classic bug.

**Interview one-liner:** _"Rotate in place = transpose + reverse each row."_

---

### P15. Merge sort counting — "count pairs while merging" ⚖️

**Observation:** during merge sort, both halves are **sorted**. That means counting how many cross-half pairs satisfy a condition can be done in **O(n) per level** (not O(n²)).

**Count inversions — pairs (i < j) with a[i] > a[j]:**

```
in mergesort, during the merge of sorted halves [l..mid] and [mid+1..r]:
    if a[left] > a[right]:  count += (mid - left + 1)     # ALL left-half elements
                                                          # from left..mid are > a[right]
    merge as usual
```

**Reverse pairs — pairs (i < j) with a[i] > 2 \* a[j]:**

```
same framework. BEFORE merging:
    use two pointers on the sorted halves; for each i in left half,
    advance j while a[i] > 2 * a[j] → count += j - start
then do the normal merge (counting step must NOT mutate the halves)
```

**Spot it:** "count pairs i < j where a[i] > a[j] (or > k·a[j])", "inversions", "reverse pairs". This is **the** D&C counting pattern.

**Trap 🚨:**

- The answer can be ~n²/2 → **use `long`**.
- `2 * a[j]` can overflow → use `2LL * a[j]`.
- The counting happens on **already sorted** halves — that's the whole point.

**Interview one-liner:** _"Same as merge sort: halves are sorted, so cross-pair counting is O(n) per level → O(n log n) total."_

---

### P16. The meta-pattern: "brute force → which pattern?" (your internal search engine)

When stuck, name the brute force — it tells you the family:

| Your brute force | Jump to |
| --- | --- |
| "try every subarray, check sum/best" | P8 prefix map (count/longest) · P2 Kadane (best) · P9 sliding window (positive-only) |
| "try every pair/triplet" | P7 sort + two pointers · P10 hashmap |
| "count pairs (i<j) with comparison" | P15 merge sort counting |
| "try every element, count frequency" | P10 hashmap · P5 voting · P11 XOR/math (if O(1) space asked) |
| "generate & check all arrangements" | P13 next-permutation style · sort-based thinking |
| "in-place rearrangement" | P3 reader–writer · P4 Dutch flag |

**The rule:** _if the brute force is O(n²), there is almost always a linear or O(n log n) pattern hiding in the structure (sortedness, contiguity, or index order)._

---

## 1.6 Problem → Pattern index (your full Striver Step 3)

### 🔹 Easy (Step 3.1)

| #   | Problem                                 | Pattern  | One-line trick                                           |
| --- | --------------------------------------- | -------- | -------------------------------------------------------- |
| 1   | Largest element in array                | P1       | single-pass max                                          |
| 2   | Second largest (without sorting)        | P1       | keep largest + second, strict comparisons                |
| 3   | Check if array is sorted                | P1       | `a[i] >= a[i-1]` for all i                               |
| 4   | Remove duplicates from sorted           | P3       | reader–writer, compare with last kept                    |
| 5   | Left rotate by 1                        | P1       | save first, shift left, put at end                       |
| 6   | Left rotate by D                        | rotation | `d %= n`; reverse(0,n-1), reverse(0,d-1), reverse(d,n-1) |
| 7   | Move zeros to end                       | P3       | swap non-zero forward                                    |
| 8   | Linear search                           | —        | simple loop                                              |
| 9   | Union of two sorted arrays              | P6       | merge pointers + skip duplicates                         |
| 10  | Missing number                          | P11      | sum formula or XOR 1..n ^ array                          |
| 11  | Maximum consecutive ones                | P1       | counter, reset at 0                                      |
| 12  | Number that appears once (others twice) | P11      | XOR everything                                           |

### 🔸 Medium (Step 3.2)

| #   | Problem                                 | Pattern | One-line trick                                   |
| --- | --------------------------------------- | ------- | ------------------------------------------------ |
| 1   | Longest subarray with sum K (positives) | P9      | sliding window                                   |
| 2   | Longest subarray with sum K (pos+neg)   | P8      | prefix map, store first index                    |
| 3   | Sort 0s, 1s, 2s                         | P4      | Dutch flag, don't move mid on high swap          |
| 4   | Majority element (> n/2)                | P5      | voting + verify                                  |
| 5   | Kadane: max subarray sum                | P2      | `cur = max(x, cur + x)`                          |
| 6   | Print subarray with max sum             | P2      | track start indices                              |
| 7   | Stock buy & sell                        | P2      | running min price                                |
| 8   | Rearrange elements by sign              | P3/P4   | place negatives & positives at alternating slots |
| 9   | Next permutation                        | P13     | 3-step                                           |
| 10  | Leaders in an array                     | P1      | walk right to left with maxSoFar                 |
| 11  | Longest consecutive sequence            | P10     | set + count only from run starts                 |
| 12  | Set matrix zeros                        | P14     | first row/col as flags (+ col0 boolean)          |
| 13  | Rotate matrix by 90°                    | P14     | transpose + reverse rows                         |
| 14  | Spiral traversal                        | P14     | 4 boundaries, shrink after each side             |
| 15  | Count subarrays with sum K              | P8      | prefix map, `map{0:1}`                           |
| 16  | Pascal's triangle                       | P14     | build row by row                                 |
| 17  | Majority element (> n/3)                | P5      | two candidates + verify                          |
| 18  | 3-Sum                                   | P7      | sort + fix one + two pointers                    |
| 19  | Largest subarray with 0 sum             | P8      | map stores first index                           |
| 20  | Count subarrays with XOR K              | P8      | XOR prefix map                                   |
| 21  | Merge overlapping subintervals          | P12     | sort by start + merge chain                      |

### 🔻 Hard (Step 3.3)

| # | Problem | Pattern | One-line trick |
| --- | --- | --- | --- |
| 1 | 4-Sum | P7 | sort + fix two + two pointers + skip dupes |
| 2 | Merge two sorted arrays without extra space | P6 | gap method (Shell-sort style) |
| 3 | **Find the repeating & missing number** | P11 | frequency array (easy) → math or XOR (optimal). See the deep-dive below |
| 4 | Count inversions | P15 | merge sort counting: `count += mid - l + 1` |
| 5 | Reverse pairs | P15 | merge sort + count `a[i] > 2*a[j]` before merging |
| 6 | Maximum product subarray | P2 | keep max AND min ending here |

### 🎯 Deep dive: Find Repeating & Missing (your current problem)

The problem: array of size n contains numbers 1..n, **one number is missing, one number repeats**. Find both.

**4 approaches, easiest → best:**

1. **Frequency array (brute, fine):** make `freq[n+1]`; count; the one with count 2 = repeated; the one with count 0 = missing. O(n) time, O(n) space. — _Good starting answer._
2. **Index-marking (O(1) space, no math):** for each `x`, go to index `x-1` and mark it (negate it). A positive value at index `i` means `i+1` was never visited = **missing**; the value that was already negative when you tried to mark = **repeated**. O(n), O(1).
3. **Math:** sums & sum of squares → solve the two equations (P11). O(n), O(1). Careful with overflow (use long).
4. **XOR:** XOR everything → `x ^ y`, isolate a set bit, partition, then one scan to label. O(n), O(1). The most impressive to explain.

**Interview answer you should give:** mention frequency array first ("simple, O(n) space"), then say "we can do O(1) space with the math approach or XOR approach", then explain one of them clearly and dry-run it.

---

## 1.7 Traps master table 🚨 (revise before every contest)

| Mistake                                  | Fix                                                                  |
| ---------------------------------------- | -------------------------------------------------------------------- |
| Sorting when order matters               | Check first: "does the answer care about original position?"         |
| 3sum/4sum duplicate triplets             | Skip equal neighbors after every move + skip repeated fixed elements |
| Forgetting `map{0:1}` in prefix sum      | The empty prefix has sum 0 — include it                              |
| "Longest" but you stored frequency       | Longest → store **first index**; Count → store **frequency**         |
| Sliding window on negative numbers       | Use prefix-sum map when negatives exist                              |
| Dutch flag: moving `mid` after high-swap | Only advance `mid` on 0 and 1                                        |
| Voting without verification              | Always do a second counting pass                                     |
| Max product: only one state              | Track both max and min ending here                                   |
| Sum of squares overflow                  | Use `long` (or double for the division trick)                        |
| Rotate by D where D > n                  | `d %= n`                                                             |
| Second largest with duplicates           | Strict comparisons / skip equals                                     |
| Spiral: double-printing a single row/col | Check bounds inside each of the 4 loops                              |
| Set zeros with only (0,0) flag           | Keep a separate `col0` boolean                                       |
| Next permutation on descending array     | Reverse the whole array                                              |
| Inversions with int                      | Count can be ~n²/2 → use `long`                                      |
| Reverse pairs: `2*a[j]` overflow         | Use `2LL * a[j]`                                                     |
| Leaders computed left-to-right           | Leaders are "greater than all to the RIGHT" → walk right-to-left     |
| Gap method: wrong gap shrink             | `gap = gap/2 + gap%2` (ceil), stop when gap becomes 0                |

---

## 1.8 Quick self-test 🧪 (answers at the bottom — no peeking!)

1. "Find the only number appearing once; every other appears exactly twice." → which pattern?
2. "Count subarrays whose sum is exactly K; array contains negatives." → which pattern?
3. "Sort an array of 0s, 1s, 2s in one pass, in place." → which pattern?
4. "Return all unique triplets that sum to zero." → which pattern?
5. "Element occurring more than n/3 times." → which pattern?
6. "Merge two sorted arrays without using extra space." → which pattern?
7. "Count pairs (i < j) with a[i] > 2\*a[j]." → which pattern?
8. "Longest subarray with sum K; all numbers positive." → which pattern?
9. "Next lexicographically greater permutation." → which pattern?
10. "Print a matrix in spiral order." → which pattern?

_(Answers: 1. XOR · 2. Prefix-sum map · 3. Dutch flag · 4. Sort + two pointers · 5. Voting (2 candidates) · 6. Gap method · 7. Merge-sort counting · 8. Sliding window · 9. 3-step next permutation · 10. 4-boundary walk.)_

---

## 1.9 Interview notes 🎤

- **Always give brute force first**, then optimize: _"The brute force is O(n²) — can we make it O(n)?"_ Interviewers love that arc.
- **Dry-run a tiny example** before coding. Draw it. It prevents 90% of bugs.
- **Know your complexities cold:** prefix map O(n) · 3-sum O(n²) · 4-sum O(n² log n) or O(n³) · merge-sort counting O(n log n) · Kadane O(n) + O(1).
- **Most-asked from this chapter:** Two-Sum/3-Sum, Kadane (max subarray), majority element, stock buy & sell, missing & repeating, merge intervals, rotate image, spiral, next permutation, count inversions. Move-Zeros & Remove-Duplicates are common warm-ups.
- **Stuck in the interview?** Go back to the Thinking Flow: Q2 (subarray vs selection) → Q3 (sort?) → Q5 (constraints). The answer usually appears.
- **Be proud of the naming:** saying "I'll use the **gap method**", "**Boyer–Moore voting**", "**Dutch National Flag**", "**prefix-sum hashmap**" instantly signals you know your patterns.

---

## 1.10 What's next ➡️

You finished **Arrays**. Next in Striver is **Binary Search** (Step 4):

- BS on sorted arrays (lower/upper bound, first & last occurrence, search in rotated array)
- BS on answer space (Koko, bouquets, split array, aggressive cows — the "find the answer, not in the array" family)
- BS on 2D (matrix search)
- And how BS + your two-pointer instincts work together.

When you finish Binary Search, tell me — I'll add **Chapter 2** here.

---

_Chapter 1 written after completing Striver Step 3 (Arrays: Easy → Medium → Hard). Generated for personal revision use._
