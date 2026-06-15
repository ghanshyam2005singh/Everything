# Coding — Backend Feature Engineering

A 4-week sprint-style plan to build real, production-grade backend features — each one coded, Dockerized, deployed, and documented.

---

## Weekly Plan (from `require.md`)

### Week 1 — Auth
| Feature             | Key Concepts                              |
|---------------------|-------------------------------------------|
| JWT Authentication  | sign/verify tokens, access + refresh flow |
| OAuth Login         | OAuth2 authorization code flow, scopes    |
| Email Verification  | token-based email flow, SMTP/SES          |
| Password Reset      | time-limited reset tokens, bcrypt         |

### Week 2 — File & Media
| Feature          | Key Concepts                                    |
|------------------|-------------------------------------------------|
| File Upload      | multipart/form-data, validation, size limits    |
| Image Processing | sharp/jimp, resize, compress, format convert    |
| S3 Storage       | presigned URLs, bucket policies, IAM roles      |
| CDN              | CloudFront / Cloudflare, cache-control headers  |

### Week 3 — Real-time & Caching
| Feature       | Key Concepts                                           |
|---------------|--------------------------------------------------------|
| WebSocket Chat | ws/socket.io, rooms, broadcast, reconnection          |
| Notifications  | push (FCM/APNs), in-app, polling vs SSE vs WebSocket  |
| Redis Cache    | get/set/expire, cache-aside pattern, invalidation     |
| Rate Limiting  | token bucket, sliding window, Redis-backed middleware |

### Week 4 — Scale & Ops
| Feature        | Key Concepts                                        |
|----------------|-----------------------------------------------------|
| Microservices  | service decomposition, API gateway, inter-service comms |
| Queues         | BullMQ/RabbitMQ/SQS, producer-consumer, DLQ         |
| Cron Jobs      | node-cron, idempotency, distributed locking         |
| Monitoring     | Prometheus, Grafana, structured logging, alerting   |

---

## Feature Checklist (for every feature)

- [ ] **Code** — working implementation, clean, no secrets in code
- [ ] **Dockerize** — `Dockerfile` + `docker-compose.yml`, runs with `docker compose up`
- [ ] **Deploy** — deployed to a cloud environment (Railway / Render / AWS / GCP)
- [ ] **Document** — API docs (Swagger/Postman), architecture decision, env vars listed

---

## Project Setup (Node.js / TypeScript)

```bash
mkdir feature-name && cd feature-name
npm init -y
npm install express typescript ts-node @types/node @types/express
npx tsc --init

# Folder structure
src/
├── index.ts          # entry point
├── routes/           # route handlers
├── controllers/      # business logic
├── middleware/        # auth, validation, rate-limit
├── services/         # external integrations (S3, Redis, etc.)
└── config/           # env, db connections
```

---

## Key Libraries

| Purpose          | Library                          |
|------------------|----------------------------------|
| HTTP server      | express / fastify                |
| Auth             | jsonwebtoken, bcrypt, passport   |
| Validation       | zod, joi                         |
| ORM / DB         | prisma, drizzle, mongoose        |
| File upload      | multer                           |
| Image processing | sharp                            |
| AWS              | @aws-sdk/client-s3               |
| Redis            | ioredis                          |
| WebSocket        | ws, socket.io                    |
| Queue            | bullmq                           |
| Env vars         | dotenv                           |
| Logging          | pino, winston                    |
| Testing          | jest, supertest                  |

---

## Environment Variables Pattern

Never hardcode secrets. Use `.env` + a typed config:

```ts
// src/config/env.ts
import { z } from "zod";

const schema = z.object({
    PORT:         z.string().default("3000"),
    DATABASE_URL: z.string().url(),
    JWT_SECRET:   z.string().min(32),
    AWS_REGION:   z.string().optional(),
});

export const env = schema.parse(process.env);
```

---

## Docker Pattern

```dockerfile
# Dockerfile
FROM node:20-alpine
WORKDIR /app
COPY package*.json ./
RUN npm ci --only=production
COPY . .
RUN npm run build
EXPOSE 3000
CMD ["node", "dist/index.js"]
```

```yaml
# docker-compose.yml
services:
  app:
    build: .
    ports: ["3000:3000"]
    env_file: .env
    depends_on: [db, redis]
  db:
    image: postgres:16-alpine
    environment:
      POSTGRES_PASSWORD: postgres
  redis:
    image: redis:7-alpine
```

---

## Resources

- [roadmap.sh/backend](https://roadmap.sh/backend) — visual backend learning map
- [Node.js docs](https://nodejs.org/docs/latest/)
- [Prisma docs](https://www.prisma.io/docs)
- [Docker docs](https://docs.docker.com)
- [AWS SDK v3](https://docs.aws.amazon.com/AWSJavaScriptSDK/v3/latest/)
- [Socket.io docs](https://socket.io/docs/v4/)
- [BullMQ docs](https://docs.bullmq.io)
