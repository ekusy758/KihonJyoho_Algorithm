import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

export default defineConfig({
  base: '/KihonJyoho_Algorithm/sample_20221226/Q.15/', // GitHub Pagesでの相対パスを追加
  plugins: [react()]
});
