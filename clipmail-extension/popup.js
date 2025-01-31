document.getElementById('extract-btn').addEventListener('click', async () => {
  try {
    console.log('Reading clipboard...');
    const clipboardItems = await navigator.clipboard.read();
    let imageBlob;

    // Find the first image in the clipboard
    for (const item of clipboardItems) {
      for (const type of item.types) {
        if (type.startsWith('image/')) {
          console.log('Image found:', type);
          imageBlob = await item.getType(type);
          break;
        }
      }
    }

    if (!imageBlob) {
      alert('⚠️ No image found in clipboard! Use Win+Shift+S to capture a screenshot first.');
      return;
    }

    // Convert blob to image URL for Tesseract
    const imageUrl = URL.createObjectURL(imageBlob);
    console.log('Image URL created:', imageUrl);

    // Initialize Tesseract worker with local scripts
    console.log('Initializing Tesseract...');
    const worker = Tesseract.createWorker({
      workerPath: 'scripts/worker.min.js',
      corePath: 'scripts/tesseract-core.wasm.js',
      langPath: 'https://tessdata.projectnaptha.com/4.0.0/',
    });

    await worker.load();
    await worker.loadLanguage('eng');
    await worker.initialize('eng');

    // Perform OCR
    console.log('Processing image...');
    const { data: { text } } = await worker.recognize(imageUrl);
    console.log('Extracted text:', text);

    // Display result
    document.getElementById('result').textContent = text;
    await worker.terminate();

  } catch (error) {
    console.error('❌ Error:', error);
    alert(`Failed to extract text: ${error.message || error.toString()}`);
  }
});