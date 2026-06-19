# DevLearn — Personal Developer Learning Platform

A full-stack developer learning platform built with Next.js, TypeScript, and Tailwind CSS. Interactive lessons, coding exercises, real-world projects, and interview prep — all in one place.

## Features

- **Interactive Lessons** — 20 JavaScript lessons from basics to advanced, each with code examples you can run in the browser
- **In-Browser Code Execution** — Monaco Editor (VS Code's engine) with live output panel
- **Practice Challenges** — 15 coding challenges with hints and solutions
- **Project-Based Learning** — 8 guided projects from Counter App to JWT Auth and Realtime Chat
- **Interview Prep** — 50+ Q&As with detailed answers and follow-up questions
- **Quick Revision** — 5 cheat sheets: array methods, object methods, async JS, top-20 interview topics
- **Progress Tracking** — LocalStorage-based: mark lessons complete, view progress bar
- **Mobile Friendly** — Responsive sidebar with overlay on mobile
- **Scalable Architecture** — Add TypeScript, React, DSA tracks without refactoring

## Tech Stack

| Layer | Technology |
|-------|------------|
| Framework | Next.js 16 (App Router) |
| Language | TypeScript |
| Styling | Tailwind CSS v4 |
| Editor | Monaco Editor |
| Storage | Browser localStorage |

## Folder Structure

```
Learning/
├── src/
│   ├── app/
│   │   ├── page.tsx                    # Home — track selector
│   │   └── [track]/
│   │       ├── layout.tsx              # Track layout (sidebar)
│   │       ├── page.tsx                # Track overview
│   │       ├── lessons/[slug]/page.tsx # Individual lesson
│   │       ├── practice/[slug]/page.tsx # Challenge
│   │       ├── projects/[slug]/page.tsx # Project guide
│   │       ├── interview/page.tsx      # Interview Q&A
│   │       ├── playground/page.tsx     # Free code editor
│   │       └── revision/page.tsx       # Cheat sheets
│   ├── components/
│   │   ├── layout/                     # Sidebar, TrackLayout
│   │   ├── lesson/                     # LessonContent, Exercise, CodeBlock
│   │   ├── playground/                 # CodePlayground (Monaco)
│   │   └── ui/                         # Badge, ProgressBar
│   ├── content/javascript/             # All JS learning content
│   ├── lib/                            # Utilities and progress tracking
│   └── types/index.ts                  # TypeScript types
└── README.md
```

## Prerequisites

- **Node.js 22+**
- npm

## Getting Started

Run the development server:

```bash
npm run dev
# or
yarn dev
# or
pnpm dev
# or
bun dev
```

Open [http://localhost:3000](http://localhost:3000) with your browser to see the result.

You can start editing the page by modifying `app/page.tsx`. The page auto-updates as you edit the file.

This project uses [`next/font`](https://nextjs.org/docs/app/building-your-application/optimizing/fonts) to automatically optimize and load [Geist](https://vercel.com/font), a new font family for Vercel.

## Learn More

To learn more about Next.js, take a look at the following resources:

- [Next.js Documentation](https://nextjs.org/docs) - learn about Next.js features and API.
- [Learn Next.js](https://nextjs.org/learn) - an interactive Next.js tutorial.

You can check out [the Next.js GitHub repository](https://github.com/vercel/next.js) - your feedback and contributions are welcome!

## Deploy on Vercel

The easiest way to deploy your Next.js app is to use the [Vercel Platform](https://vercel.com/new?utm_medium=default-template&filter=next.js&utm_source=create-next-app&utm_campaign=create-next-app-readme) from the creators of Next.js.

Check out our [Next.js deployment documentation](https://nextjs.org/docs/app/building-your-application/deploying) for more details.
