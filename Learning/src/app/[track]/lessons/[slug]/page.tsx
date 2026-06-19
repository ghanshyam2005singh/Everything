import { getLessonBySlug, getLessons } from '@/lib/content';
import { LessonClient } from './LessonClient';
import { notFound } from 'next/navigation';

export function generateStaticParams() {
  const lessons = getLessons('javascript');
  return lessons.map((l) => ({ track: 'javascript', slug: l.slug }));
}

export default async function LessonPage({ params }: { params: Promise<{ track: string; slug: string }> }) {
  const { track, slug } = await params;
  const lesson = getLessonBySlug(track, slug);
  if (!lesson) notFound();

  return <LessonClient lesson={lesson} track={track} />;
}
