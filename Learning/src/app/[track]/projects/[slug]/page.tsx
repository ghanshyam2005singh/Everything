import { getProjectBySlug, getProjects } from '@/lib/content';
import { ProjectPageClient } from './ProjectPageClient';
import { notFound } from 'next/navigation';

export function generateStaticParams() {
  const projects = getProjects('javascript');
  return projects.map((p) => ({ track: 'javascript', slug: p.slug }));
}

export default async function ProjectPage({ params }: { params: Promise<{ track: string; slug: string }> }) {
  const { track, slug } = await params;
  const project = getProjectBySlug(track, slug);
  if (!project) notFound();

  return <ProjectPageClient project={project} track={track} />;
}
