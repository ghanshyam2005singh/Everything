# System Design

High-Level Design (HLD) and Low-Level Design (LLD) studies for real-world systems. Each subfolder covers one system end-to-end: requirements → architecture → schema → APIs → tradeoffs.

---

## Systems Covered

| System    | Folder          | Status      |
|-----------|-----------------|-------------|
| WhatsApp  | `Whatsapp/`     | In progress |
| Uber      | `uber/`         | In progress |

---

## How to Study a System

For each system, work through these documents in order:

1. **`require.md`** — functional & non-functional requirements, scale estimates
2. **`architecture.md`** — HLD diagram, major components, data flow
3. **`schema.md`** — database schema, indexes, data models
4. **`api.md`** — REST/gRPC/WebSocket API contracts

---

## System Design Framework (for any system)

### Step 1 — Clarify Requirements (5 min)
**Functional:** What does the system DO?
- Core features (e.g., for WhatsApp: send/receive messages, group chats, read receipts)
- Out of scope (e.g., video calls initially)

**Non-Functional:** How well must it perform?
- Scale: DAU, messages/sec, storage/year
- Latency: p99 < 100ms?
- Availability: 99.9% or 99.99%?
- Consistency: strong or eventual?

### Step 2 — Capacity Estimation (5 min)
```
Users: 500M DAU
Messages: 100 msgs/user/day = 50B msgs/day = ~600K msgs/sec
Storage: avg 100 bytes/msg → 5 TB/day → 1.8 PB/year
```

### Step 3 — High-Level Design (10 min)
Draw boxes:
- **Client** → **Load Balancer** → **App Servers** → **Cache** → **DB**
- Identify: where is the bottleneck? where do we need a queue? when to shard?

### Step 4 — Data Model & APIs (10 min)
- Design the key tables / documents / schemas
- Define the critical API endpoints (method, path, request, response)

### Step 5 — Deep Dive (15 min)
Pick 2-3 hard parts:
- How do messages get delivered in real-time? (WebSocket, long polling, SSE)
- How do we handle fan-out for group messages?
- How do we shard the database?
- How does the CDN serve media?

### Step 6 — Tradeoffs & Bottlenecks (5 min)
- SQL vs NoSQL for messages
- Push vs pull notification model
- Single leader vs leaderless replication
- Synchronous vs asynchronous processing

---

## Key Components to Know

### Load Balancer
- Distributes traffic across app servers
- Layer 4 (TCP) vs Layer 7 (HTTP/HTTPS)
- Health checks, sticky sessions

### Cache (Redis / Memcached)
- Cache-aside, write-through, write-back patterns
- Eviction: LRU, LFU, TTL-based
- Cache invalidation is the hardest problem

### Message Queue (Kafka / RabbitMQ / SQS)
- Decouples producers and consumers
- At-least-once / exactly-once delivery
- Use for: notifications, fan-out, event sourcing

### Database Choices
| Use case              | Choice                        |
|-----------------------|-------------------------------|
| User profiles, auth   | PostgreSQL / MySQL            |
| Time-series (metrics) | InfluxDB / TimescaleDB        |
| Messages / feeds      | Cassandra / DynamoDB          |
| Search                | Elasticsearch                 |
| Graph (friends)       | Neo4j / DGraph                |
| Cache / sessions      | Redis                         |
| Files / media         | S3 + CDN                      |

### CDN
- Edge servers cache static content close to user
- Reduces latency for images, videos, JS/CSS
- CloudFront, Cloudflare, Fastly

### Consistent Hashing
- Distribute keys across nodes with minimal remapping on add/remove
- Used in Cassandra, DynamoDB, Redis Cluster

### CAP Theorem
- **C**onsistency: every read sees the latest write
- **A**vailability: every request gets a response
- **P**artition tolerance: system works despite network split
- You can only guarantee 2 of 3 (choose CA, CP, or AP per use case)

---

## Resources

- [System Design Primer](https://github.com/donnemartin/system-design-primer) — the best free resource
- [Designing Data-Intensive Applications](https://dataintensive.net) — essential book (DDIA)
- [ByteByteGo Blog](https://blog.bytebytego.com) — system design visuals
- [High Scalability Blog](http://highscalability.com) — real architecture case studies
- [The Architecture of Open Source Applications](https://aosabook.org) — how real systems are built
- [AWS Architecture Blog](https://aws.amazon.com/blogs/architecture/)

---

## Systems to Design Next

- [ ] Twitter / X — timeline, fan-out on write vs read
- [ ] YouTube — video upload, transcoding pipeline, CDN
- [ ] Google Drive — file sync, conflict resolution, chunking
- [ ] Airbnb — search, booking, payments
- [ ] Rate Limiter — token bucket vs sliding window
- [ ] URL Shortener — hashing, redirection, analytics
- [ ] Notification Service — push, email, SMS at scale
