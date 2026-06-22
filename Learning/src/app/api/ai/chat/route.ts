import { NextRequest, NextResponse } from 'next/server';
import { callGemini } from '@/lib/gemini/client';

export async function POST(req: NextRequest) {
  try {
    const body = await req.json();
    const { message, history } = body;

    if (!message || typeof message !== 'string' || message.trim().length === 0) {
      return NextResponse.json({ error: 'Message is required' }, { status: 400 });
    }

    if (message.length > 4000) {
      return NextResponse.json({ error: 'Message is too long (max 4000 characters)' }, { status: 400 });
    }

    const validHistory = Array.isArray(history)
      ? history.filter(
          (h) =>
            h &&
            typeof h === 'object' &&
            (h.role === 'user' || h.role === 'assistant') &&
            typeof h.content === 'string'
        )
      : [];

    const response = await callGemini(message.trim(), validHistory);
    return NextResponse.json({ response });
  } catch (err) {
    const message = err instanceof Error ? err.message : 'An unexpected error occurred';
    return NextResponse.json({ error: message }, { status: 500 });
  }
}
