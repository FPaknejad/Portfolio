const esbuild = require('esbuild');

esbuild.build({
  entryPoints: ['node_modules/franc/index.js'], // Entry point for franc
  bundle: true,
  outfile: 'scripts/franc.min.js', // Output file
  format: 'esm', // Use ES modules
  minify: true, // Minify the output
}).catch(() => process.exit(1));