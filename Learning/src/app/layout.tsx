import type { Metadata } from 'next';
import { Geist, Geist_Mono } from 'next/font/google';
import './globals.css';

const geistSans = Geist({ variable: '--font-geist-sans', subsets: ['latin'] });
const geistMono = Geist_Mono({ variable: '--font-geist-mono', subsets: ['latin'] });

export const metadata: Metadata = {
  title: 'Learning — Personal Developer Learning Platform',
  description:
    'Learn JavaScript, TypeScript, React, Next.js, DSA and more with interactive lessons, hands-on coding, and interview prep.',
  keywords: ['javascript', 'typescript', 'react', 'learning', 'interview prep', 'DSA'],
};

export default function RootLayout({ children }: { children: React.ReactNode }) {
  return (
    <html lang="en" data-scroll-behavior="smooth" className={`${geistSans.variable} ${geistMono.variable} dark`} suppressHydrationWarning>
      <body className="min-h-screen bg-[#050508] text-slate-100 antialiased">{children}</body>
    </html>
  );
}
