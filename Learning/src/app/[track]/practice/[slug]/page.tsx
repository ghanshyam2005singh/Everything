import { getChallengeBySlug, getChallenges } from '@/lib/content';
import { ChallengeClient } from './ChallengeClient';
import { notFound } from 'next/navigation';

export function generateStaticParams() {
  const challenges = getChallenges('javascript');
  return challenges.map((c) => ({ track: 'javascript', slug: c.slug }));
}

export default async function ChallengePage({ params }: { params: Promise<{ track: string; slug: string }> }) {
  const { track, slug } = await params;
  const challenge = getChallengeBySlug(track, slug);
  if (!challenge) notFound();

  return <ChallengeClient challenge={challenge} track={track} />;
}
