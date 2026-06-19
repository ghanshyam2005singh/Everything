'use client';

import { useState } from 'react';
import Link from 'next/link';
import { Sidebar } from './Sidebar';
import type { Lesson } from '@/types';

interface TrackLayoutProps {
  children: React.ReactNode;
  track: string;
  lessons: Lesson[];
}

export function TrackLayout({ children, track, lessons }: TrackLayoutProps) {
  const [sidebarOpen, setSidebarOpen] = useState(false);

  return (
    <div className="h-screen bg-[#050508] flex flex-col overflow-hidden">
      {/* Mobile header */}
      <header className="lg:hidden flex items-center justify-between px-4 py-3 bg-[#07070b]/90 border-b border-slate-800/50 shrink-0 z-20 backdrop-blur-sm">
        <button
          onClick={() => setSidebarOpen(true)}
          className="p-2 -ml-2 text-slate-500 hover:text-slate-200 transition-colors rounded-lg"
          aria-label="Open navigation"
        >
          <svg width="18" height="18" fill="none" stroke="currentColor" strokeWidth={2} strokeLinecap="round">
            <line x1="1" y1="5" x2="17" y2="5" />
            <line x1="1" y1="9" x2="17" y2="9" />
            <line x1="1" y1="13" x2="17" y2="13" />
          </svg>
        </button>
        <Link href="/" className="flex items-center gap-2">
          <img src="/favicon.ico" alt="Logo" className="w-7 h-7 rounded-lg" />
          <span className="font-bold text-white text-sm">Learning</span>
        </Link>
        <div className="w-8" />
      </header>

      <div className="flex flex-1 overflow-hidden min-h-0">
        {/* Desktop sidebar */}
        <div className="hidden lg:flex flex-col shrink-0">
          <Sidebar track={track} lessons={lessons} />
        </div>

        {/* Mobile sidebar overlay */}
        {sidebarOpen && (
          <div className="fixed inset-0 z-30 lg:hidden">
            <div
              className="absolute inset-0 bg-black/70 backdrop-blur-sm"
              onClick={() => setSidebarOpen(false)}
            />
            <div className="absolute left-0 top-0 bottom-0 z-10">
              <Sidebar track={track} lessons={lessons} />
            </div>
          </div>
        )}

        {/* Main content */}
        <main className="flex-1 overflow-y-auto min-w-0">
          <div className="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 py-6 sm:py-8">
            {children}
          </div>
        </main>
      </div>
    </div>
  );
}
