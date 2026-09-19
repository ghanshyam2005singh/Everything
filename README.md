# Everything

A personal knowledge repo covering DSA, Competitive Programming, System Design, and full-stack backend engineering — structured for deliberate, day-by-day learning.

---

## Folder Structure

```
Everything/
├── DSA/                  # Data Structures & Algorithms
│   ├── STL.c++           # Complete STL + algorithm reference
│   └── basics/           # LeetCode problem solutions
├── POTD/                 # Problem of the Day solutions
├── CP/                   # Competitive Programming templates & problems
├── Coding/               # Backend feature engineering (weekly plan)
└── System Design/        # HLD/LLD for real-world systems
```

---

## Learning Roadmap

### Phase 1 — DSA Foundations (Weeks 1–8)
1. Master STL containers and algorithms → `DSA/STL.c++`
2. Solve ~3 LeetCode problems per day, starting from basics → `DSA/basics/`
3. Do the daily LeetCode POTD every day → `POTD/`

### Phase 2 — Competitive Programming (Weeks 4–12)
1. Learn core CP patterns (two pointers, segment trees, etc.) → `CP/`
2. Participate in Codeforces / AtCoder rounds weekly

### Phase 3 — System Design (Weeks 6–16)
1. Study real-world architectures → `System Design/`
2. Design: Whatsapp, Uber, Twitter, YouTube, etc.

### Phase 4 — Backend Engineering (Weeks 1–16, parallel)
1. Build one production-grade feature per week → `Coding/`
2. Each feature: code → Dockerize → deploy → document

---

## Resources

### DSA
- [NeetCode 150](https://neetcode.io/practice) — curated problem list
- [CP-Algorithms](https://cp-algorithms.com) — algorithm theory with proofs
- [USACO Guide](https://usaco.guide) — structured from bronze to platinum
- [Striver's A2Z Sheet](https://takeuforward.org/strivers-a2z-dsa-course) — comprehensive DSA sheet

### Competitive Programming
- [Codeforces](https://codeforces.com) — main contest platform
- [AtCoder](https://atcoder.jp) — excellent problem quality
- [CSES Problem Set](https://cses.fi/problemset/) — essential CP problems

https://cses.fi/problemset/list/

https://codeforces.com/group/MWSDmqGsZm/contests

### System Design
- [System Design Primer](https://github.com/donnemartin/system-design-primer)
- [Designing Data-Intensive Applications](https://dataintensive.net) — book
- [ByteByteGo Newsletter](https://blog.bytebytego.com)

### Backend / Coding
- [roadmap.sh/backend](https://roadmap.sh/backend)
- Node.js docs, Docker docs, AWS docs

---

## How to Run C++ Code with Test Cases

See `DSA/basics/7.c++` for the full pattern. Short version:

```bash
# Compile
g++ -std=c++17 -o solution DSA/basics/7.c++ && ./solution
```

Expected output shows PASS/FAIL per test case.

---

## Daily Habit

| Time      | Activity                          |
|-----------|-----------------------------------|
| Morning   | 1 POTD (LeetCode)                 |
| Afternoon | 2 DSA basics / CP problems        |
| Evening   | 30 min System Design reading      |
| Night     | Backend feature work (Coding/)    |
