import { lessons } from '@/content/javascript/lessons';
import { challenges } from '@/content/javascript/challenges';
import { projects } from '@/content/javascript/projects';
import { interviewQuestions } from '@/content/javascript/interview';
import type { Lesson, Challenge, Project, InterviewQuestion } from '@/types';

export function getLessons(track: string): Lesson[] {
  if (track === 'javascript') return lessons;
  return [];
}

export function getLessonBySlug(track: string, slug: string): Lesson | undefined {
  return getLessons(track).find((l) => l.slug === slug);
}

export function getLessonsByCategory(track: string): Record<string, Lesson[]> {
  const trackLessons = getLessons(track);
  return trackLessons.reduce(
    (acc, lesson) => {
      if (!acc[lesson.category]) acc[lesson.category] = [];
      acc[lesson.category].push(lesson);
      return acc;
    },
    {} as Record<string, Lesson[]>
  );
}

export function getChallenges(track: string): Challenge[] {
  if (track === 'javascript') return challenges;
  return [];
}

export function getChallengeBySlug(track: string, slug: string): Challenge | undefined {
  return getChallenges(track).find((c) => c.slug === slug);
}

export function getProjects(track: string): Project[] {
  if (track === 'javascript') return projects;
  return [];
}

export function getProjectBySlug(track: string, slug: string): Project | undefined {
  return getProjects(track).find((p) => p.slug === slug);
}

export function getInterviewQuestions(track: string): InterviewQuestion[] {
  if (track === 'javascript') return interviewQuestions;
  return [];
}
