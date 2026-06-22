import {
  collection,
  addDoc,
  updateDoc,
  deleteDoc,
  doc,
  getDocs,
  query,
  orderBy,
  serverTimestamp,
  Timestamp,
} from 'firebase/firestore';
import { db } from './config';

export interface Note {
  id: string;
  title: string;
  content: string;
  type: 'text' | 'code';
  language?: string;
  createdAt: number;
  updatedAt: number;
}

export interface NoteInput {
  title: string;
  content: string;
  type: 'text' | 'code';
  language?: string;
}

const COLLECTION = 'learning_notes';

function notesRef() {
  return collection(db, COLLECTION);
}

export async function fetchNotes(): Promise<Note[]> {
  const q = query(notesRef(), orderBy('updatedAt', 'desc'));
  const snap = await getDocs(q);
  return snap.docs.map((d) => {
    const data = d.data();
    return {
      id: d.id,
      title: data.title ?? '',
      content: data.content ?? '',
      type: data.type ?? 'text',
      language: data.language,
      createdAt: data.createdAt instanceof Timestamp ? data.createdAt.toMillis() : Date.now(),
      updatedAt: data.updatedAt instanceof Timestamp ? data.updatedAt.toMillis() : Date.now(),
    };
  });
}

export async function createNote(input: NoteInput): Promise<Note> {
  const now = serverTimestamp();
  const ref = await addDoc(notesRef(), {
    ...input,
    createdAt: now,
    updatedAt: now,
  });
  return {
    id: ref.id,
    ...input,
    createdAt: Date.now(),
    updatedAt: Date.now(),
  };
}

export async function updateNote(id: string, input: Partial<NoteInput>): Promise<void> {
  const ref = doc(db, COLLECTION, id);
  await updateDoc(ref, {
    ...input,
    updatedAt: serverTimestamp(),
  });
}

export async function deleteNote(id: string): Promise<void> {
  const ref = doc(db, COLLECTION, id);
  await deleteDoc(ref);
}
