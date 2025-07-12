import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

export default defineConfig({
  base: '/KihonJyoho_Algorithm/', // リポジトリ名と同じにする
  plugins: [react()]
});
