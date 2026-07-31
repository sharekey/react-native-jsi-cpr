import type { JsiRequest } from './types';

declare global {
  var jsiHttp: {
    httpCancelRequest(requestId: string): void;
    makeHttpRequest(
      request: Partial<JsiRequest>,
      callback: (response: unknown, error: unknown) => void
    ): void;
  } | undefined;
}

export {};
