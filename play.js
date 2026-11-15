// Start the bundled game server on Windows, macOS and Linux.
import('./scripts/serve_distribution.mjs')
  .then(({ main }) => main(['--port', '8007', ...process.argv.slice(2)]))
  .catch(error => { console.error(error.message); process.exitCode = 1; });
