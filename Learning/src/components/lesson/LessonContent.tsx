'use client';

import { useState } from 'react';
import Link from 'next/link';
import type { Lesson } from '@/types';
import { Badge } from '@/components/ui/Badge';
import { CodeBlock } from '@/components/lesson/CodeBlock';
import { Exercise } from '@/components/lesson/Exercise';
import { formatTime } from '@/lib/utils';

interface LessonContentProps {
  lesson: Lesson;
  track: string;
  isComplete: boolean;
  onToggleComplete: () => void;
}

function renderContent(content: string) {
  return content.split('\n\n').map((para, i) => {
    const html = para
      .replace(/\*\*(.+?)\*\*/g, '<strong class="text-slate-100">$1</strong>')
      .replace(/`([^`]+)`/g, '<code class="px-1.5 py-0.5 rounded bg-slate-800 text-violet-300 text-[0.85em] font-mono">$1</code>')
      .replace(/\n/g, '<br/>');

    if (para.startsWith('**') && !para.includes('\n')) {
      return <p key={i} className="text-slate-300 leading-relaxed" dangerouslySetInnerHTML={{ __html: html }} />;
    }
    return <p key={i} className="text-slate-300 leading-relaxed" dangerouslySetInnerHTML={{ __html: html }} />;
  });
}

export function LessonContent({ lesson, track, isComplete, onToggleComplete }: LessonContentProps) {
  const [openQuestions, setOpenQuestions] = useState<Set<number>>(new Set());

  function toggleQuestion(i: number) {
    setOpenQuestions((prev) => {
      const next = new Set(prev);
      next.has(i) ? next.delete(i) : next.add(i);
      return next;
    });
  }

  return (
    <article className="max-w-3xl mx-auto">
      {/* Header */}
      <div className="mb-8">
        <div className="flex flex-wrap items-center gap-2 mb-3">
          <Badge variant={lesson.difficulty}>{lesson.difficulty}</Badge>
          <Badge variant="default">{lesson.category}</Badge>
          <span className="text-xs text-slate-500">{formatTime(lesson.estimatedTime)}</span>
        </div>
        <h1 className="text-3xl font-bold text-white mb-3">{lesson.title}</h1>
        <p className="text-slate-400 text-lg leading-relaxed">{lesson.description}</p>
      </div>

      {/* Content */}
      <section className="space-y-4 mb-10">
        {renderContent(lesson.content)}
      </section>

      {/* Code Examples */}
      {lesson.codeExamples.length > 0 && (
        <section className="mb-10">
          <h2 className="text-xl font-bold text-white mb-4">Examples</h2>
          {lesson.codeExamples.map((ex, i) => (
            <CodeBlock key={i} example={ex} />
          ))}
        </section>
      )}

      {/* Common Mistakes */}
      {lesson.commonMistakes.length > 0 && (
        <section className="mb-10">
          <h2 className="text-xl font-bold text-white mb-4">Common Mistakes</h2>
          <div className="bg-red-500/5 border border-red-500/20 rounded-xl p-5 space-y-3">
            {lesson.commonMistakes.map((mistake, i) => (
              <div key={i} className="flex items-start gap-3">
                <span className="text-red-400 mt-0.5 flex-shrink-0">⚠</span>
                <p className="text-slate-300 text-sm leading-relaxed">{mistake}</p>
              </div>
            ))}
          </div>
        </section>
      )}

      {/* Interview Questions */}
      {lesson.interviewQuestions.length > 0 && (
        <section className="mb-10">
          <h2 className="text-xl font-bold text-white mb-4">Interview Questions</h2>
          <div className="space-y-3">
            {lesson.interviewQuestions.map((q, i) => (
              <div key={i} className="border border-slate-700/60 rounded-xl overflow-hidden">
                <button
                  onClick={() => toggleQuestion(i)}
                  className="w-full flex items-center justify-between px-4 py-3 text-left hover:bg-slate-800/40 transition-colors"
                >
                  <div className="flex items-center gap-3">
                    <Badge variant={q.difficulty}>{q.difficulty}</Badge>
                    <span className="text-sm text-slate-200 font-medium">{q.question}</span>
                  </div>
                  <span className="text-slate-500 flex-shrink-0">{openQuestions.has(i) ? '▲' : '▼'}</span>
                </button>
                {openQuestions.has(i) && (
                  <div className="px-4 py-4 border-t border-slate-700/60 bg-slate-900/40">
                    <p className="text-slate-300 text-sm leading-relaxed">{q.answer}</p>
                    {q.tip && (
                      <p className="mt-3 text-violet-400 text-xs">
                        💡 Tip: {q.tip}
                      </p>
                    )}
                    {q.followUp && q.followUp.length > 0 && (
                      <div className="mt-3">
                        <p className="text-xs text-slate-500 mb-1">Follow-up questions:</p>
                        <ul className="space-y-1">
                          {q.followUp.map((fu, j) => (
                            <li key={j} className="text-xs text-slate-400">• {fu}</li>
                          ))}
                        </ul>
                      </div>
                    )}
                  </div>
                )}
              </div>
            ))}
          </div>
        </section>
      )}

      {/* Exercises */}
      {lesson.exercises.length > 0 && (
        <section className="mb-10">
          <h2 className="text-xl font-bold text-white mb-4">Practice Exercises</h2>
          <div className="space-y-6">
            {lesson.exercises.map((ex) => (
              <Exercise key={ex.id} exercise={ex} />
            ))}
          </div>
        </section>
      )}

      {/* Key Takeaways */}
      {lesson.keyTakeaways.length > 0 && (
        <section className="mb-10">
          <h2 className="text-xl font-bold text-white mb-4">Key Takeaways</h2>
          <div className="bg-violet-500/5 border border-violet-500/20 rounded-xl p-5 space-y-2">
            {lesson.keyTakeaways.map((point, i) => (
              <div key={i} className="flex items-start gap-3">
                <span className="text-violet-400 mt-0.5 flex-shrink-0">✓</span>
                <p className="text-slate-300 text-sm">{point}</p>
              </div>
            ))}
          </div>
        </section>
      )}

      {/* Mark complete + navigation */}
      <div className="flex flex-col sm:flex-row items-center justify-between gap-4 pt-8 border-t border-slate-800">
        <button
          onClick={onToggleComplete}
          className={`px-5 py-2.5 rounded-xl font-semibold text-sm transition-colors ${
            isComplete
              ? 'bg-green-500/10 text-green-400 border border-green-500/30 hover:bg-green-500/20'
              : 'bg-violet-600 text-white hover:bg-violet-500'
          }`}
        >
          {isComplete ? '✓ Completed' : 'Mark as Complete'}
        </button>

        <div className="flex items-center gap-3">
          {lesson.prevLesson && (
            <Link
              href={`/${track}/lessons/${lesson.prevLesson}`}
              className="px-4 py-2 text-sm text-slate-400 border border-slate-700 hover:border-slate-500 hover:text-slate-200 rounded-xl transition-colors"
            >
              ← Previous
            </Link>
          )}
          {lesson.nextLesson && (
            <Link
              href={`/${track}/lessons/${lesson.nextLesson}`}
              className="px-4 py-2 text-sm text-white bg-slate-800 hover:bg-slate-700 border border-slate-700 rounded-xl transition-colors"
            >
              Next →
            </Link>
          )}
        </div>
      </div>
    </article>
  );
}
